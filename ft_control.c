/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:44:37 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/06 22:37:12 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keycode(int keycode, t_img *img)
{
	double midofview;

	midofview = (img->angle_start + img->angle_view / 2);
	if (keycode == 119)
	{
		img->pos_x += cos((midofview)) * 0.15;
		img->pos_y += sin((midofview)) * 0.15;
	}
	else if (keycode == 115)
	{
		img->pos_x += cos((midofview + M_PI)) * 0.15;
		img->pos_y += sin((midofview + M_PI)) * 0.15;
	}
	else if (keycode == 100)
	{
		img->pos_x += cos((midofview + M_PI/2)) * 0.15;
		img->pos_y += sin((midofview + M_PI/2)) * 0.15;
	}
	else if (keycode == 97)
	{
		img->pos_x += cos((midofview + 3 * M_PI/2)) * 0.15;
		img->pos_y += sin((midofview + 3 * M_PI/2)) * 0.15;
	}
	return (keycode2(keycode, img));
}

int	keycode2(int keycode, t_img *img)
{
	if (keycode == 65363)
		img->angle_start += 0.05;
	else if (keycode == 65361)
		img->angle_start -= 0.05;
	while (img->angle_start > M_PI)
		img->angle_start -= 2 * M_PI;
	while (img->angle_start < - M_PI)
		img->angle_start += 2 * M_PI;
	ft_view(img, img->res_x, img->draw_sp);
	mlx_put_image_to_window(img->mlx_ptr, img->mlx_wd, img->img, 0, 0);
	return (1);
}
