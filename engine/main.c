/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:06:12 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/22 17:50:12 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/cub3d.h"

int		main(int argc, char *argv[])
{
	t_img *img;

	if (argc == 1 || (!ft_is_cub(argv[1])))
		return (ft_err_code(17));
	img = ft_init_s_img();
	if (argc == 3)
		img->save = ft_strcmp("--save", argv[2]) == 0 ? 1 : 0;
	else
		img->save = 0;
	img->mlx_ptr = mlx_init();
	if (!(ft_parsing(argv[1], img)))
		quick_quit(img);
	ft_count_sp(img);
	img->z_buffer = malloc(sizeof(double) * img->res_x);
	img->img = mlx_new_image(img->mlx_ptr, img->res_x, img->res_y);
	img->img_addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
										&img->line_length, &img->endian);
	if (img->save)
	{
		ft_screen(img);
		quit(img);
	}
	else
		loop_ig(img);
}

void	loop_ig(t_img *img)
{
	img->save = 0;
	img->mlx_wd = mlx_new_window(img->mlx_ptr, img->res_x,
											img->res_y, "cub3D");
	mlx_hook(img->mlx_wd, 2, 1L << 0, keycode, img);
	mlx_hook(img->mlx_wd, 33, 1L << 17, quit, img);
	mlx_loop_hook(img->mlx_ptr, draw, img);
	mlx_loop(img->mlx_ptr);
}

int		draw(t_img *img)
{
	t_draw_sp *dsp;

	dsp = img->draw_sp;
	mlx_do_sync(img->mlx_ptr);
	ft_view(img, img->draw_sp);
	ft_dist_to_p(img->draw_sp, img->pos_x, img->pos_y);
	is_view(img, dsp);
	mlx_put_image_to_window(img->mlx_ptr, img->mlx_wd, img->img, 0, 0);
	return (1);
}
