/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:44:37 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/15 16:46:02 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		keycode(int keycode, t_img *img)
{
	double midofview;

	midofview = (img->angle_start + img->angle_view / 2);
	if (keycode == 119)
		ft_block(img, img->pos_x + cos((midofview))
		* 0.15, img->pos_y + sin((midofview)) * 0.15);
	else if (keycode == 115)
		ft_block(img, img->pos_x + cos((midofview + M_PI))
		* 0.15, img->pos_y + sin((midofview + M_PI)) * 0.15);
	else if (keycode == 100)
	{
		ft_block(img, img->pos_x + cos((midofview + M_PI / 2))
		* 0.15, img->pos_y + sin((midofview + M_PI / 2)) * 0.15);
	}
	else if (keycode == 97)
	{
		ft_block(img, img->pos_x + cos((midofview + M_PI * 1.5))
		* 0.15, img->pos_y + sin((midofview + M_PI * 1.5)) * 0.15);
	}
	return (keycode2(keycode, img));
}

int		keycode2(int keycode, t_img *img)
{
	if (keycode == 65363)
		img->angle_start += 0.05;
	else if (keycode == 65361)
		img->angle_start -= 0.05;
	else if (keycode == 65307)
	{
		mlx_destroy_window(img->mlx_ptr, img->mlx_wd);
		exit(0);
	}
	ft_view(img, img->res_x, img->draw_sp);
	mlx_put_image_to_window(img->mlx_ptr, img->mlx_wd, img->img, 0, 0);
	return (1);
}

void	ft_block(t_img *img, double new_pos_x, double new_pos_y)
{
	if (img->map[(int)new_pos_y][(int)new_pos_x] != '1'
	&& img->map[(int)new_pos_y][(int)new_pos_x] != ' ' && img->map[(int)img->pos_y][(int)new_pos_x] != '1' && img->map[(int)new_pos_y][(int)img->pos_x] != '1')
	{
		img->pos_x = new_pos_x;
		img->pos_y = new_pos_y;
	}
	else if (img->map[(int)img->pos_y][(int)new_pos_x] != '1')
		img->pos_x = new_pos_x;
	else if (img->map[(int)new_pos_y][(int)img->pos_x] != '1')
		img->pos_y = new_pos_y;
}
