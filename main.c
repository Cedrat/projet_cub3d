/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:06:12 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/15 16:58:21 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char *argv[])
{
		t_img *img;

		if (argc == 1)
			return(0);
		img = ft_init_s_img();
		img->mlx_ptr = mlx_init();
		if (!(ft_parsing(argv[1], img)))
			return (0);
		ft_count_sp(img);
		img->z_buffer = malloc(sizeof(double) * img->res_x);
		img->img = mlx_new_image(img->mlx_ptr, img->res_x, img->res_y);
		// img->mlx_wd = mlx_new_window(img->mlx_ptr, img->res_x , img->res_y, "Cub3D");
		img->img_addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
		if (argc == 3 && ft_strcmp("--save", argv[2]) == 0)
			ft_screen(img);
		else
		{
			img->mlx_wd = mlx_new_window(img->mlx_ptr, img->res_x , img->res_y, "Cub3D");
			ft_view(img, img->res_x, img->draw_sp);
			mlx_put_image_to_window(img->mlx_ptr,img->mlx_wd, img->img, 0,0);
			mlx_hook(img->mlx_wd, 2, 1L<<0, keycode, img);
			mlx_hook(img->mlx_wd, 33, 1L<<17, quit, img);
			mlx_loop(img->mlx_ptr);
		}
}
