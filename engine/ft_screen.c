/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 00:00:44 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/18 12:45:47 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/cub3d.h"

int		ft_screen(t_img *img)
{
	int fd;

	ft_view(img, img->draw_sp);
	fd = open("./screen.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644);
	if (fd == -1)
		return (ft_err_code(16));
	ft_write_header(fd, img);
	ft_write_pic_header(fd, img);
	ft_write_img(fd, img);
	close(fd);
	return (1);
}

void	ft_write_header(int fd, t_img *img)
{
	int filesize;

	filesize = (img->res_x * img->bits_per_pixel / 8 * img->res_y) + 54;
	write(fd, "BM", 2);
	write(fd, &filesize, 4);
	write(fd, "", 4);
	filesize = 54;
	write(fd, &filesize, 4);
}

void	ft_write_pic_header(int fd, t_img *img)
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
	write(fd, &bpp, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &img_size, 4);
	write(fd, "", 16);
}

void	ft_write_img(int fd, t_img *img)
{
	void			*dst;
	unsigned int	color;
	int				x;
	int				y;
	int				pitch;

	pitch = (img->res_x % 4);
	x = img->res_y - 1;
	y = 0;
	while (x >= 0)
	{
		while (y < img->res_x)
		{
			dst = img->img_addr + (x * img->line_length + y *
				(img->bits_per_pixel / 8));
			color = *(unsigned int *)dst;
			write_pixel(fd, color);
			y++;
		}
		write(fd, "\0", pitch);
		y = 0;
		x--;
	}
}

void	write_pixel(int fd, unsigned int color)
{
	int b;
	int g;
	int r;

	b = color % 256;
	g = ((color - b) / 256) % 256;
	r = (color - g - b) / (256 * 256);
	write(fd, &b, 1);
	write(fd, &g, 1);
	write(fd, &r, 1);
}
