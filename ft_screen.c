/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 00:00:44 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/15 16:40:09 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_screen(t_img *img)
{
    int fd;

    ft_view(img, img->res_x, img->draw_sp);
    fd = open("./screen.bmp" , O_WRONLY | O_CREAT |O_TRUNC |  O_APPEND, 0644);
    if (fd == -1)
        ft_putstr("err");
    ft_write_header(fd, img);
    ft_write_pic_header(fd, img);
    ft_write_img(fd, img);
    close(fd);
}

int ft_write_header(int fd, t_img *img)
{
    int filesize;
    int i;

    i = 0;
    filesize = (img->res_x * img->bits_per_pixel/8 * img->res_y) + 54;
    write(fd, "BM", 2);
    write(fd, &filesize, 4);
    write(fd, "", 4);
    filesize = 54;
    write(fd, &filesize, 4);
}

int ft_write_pic_header(int fd, t_img *img)
{
    int img_size;
    int plan;
    int offset;
    int bpp;

    bpp = 24;
    plan = 1;
    offset = 40;
    img_size = img->res_x * img->res_y;
    write(fd, &offset, 4);
    write(fd, &img->res_x, 4);
    write(fd, &img->res_y, 4);
    write(fd, &plan, 2);
    write(fd, &bpp , 2);
    write(fd, "\0\0\0\0", 4);
    write(fd, &img_size, 4);
    write(fd, "", 16);
}

int ft_write_img(int fd, t_img *img)
{
    void	*dst;
    unsigned int color;
    int x;
    int y;
    int r;
    int g;
    int b;
    int pitch;

    pitch = (img->res_x % 4);
    x = img->res_x -1;
    y = 0;
    while (x >= 0)
    {
        while (y < img->res_y)
        {
            dst = img->img_addr + (x * img->line_length + y *
                (img->bits_per_pixel / 8));
            color = *(unsigned int *)dst;
            b = color % 256;
            g = ((color - b) / 256)%256;
            r = (color - g - b) / (256 * 256);
            write(fd, &b, 1);
            write(fd, &g, 1);
            write(fd, &r, 1);
            y++;
        }
        write(fd, "\0", pitch);
        y = 0;
        x--;
    }
}
