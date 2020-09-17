/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 18:47:12 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/17 17:05:19 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_quicksort(t_draw_sp *dsp)
{
	int		i;
	double	old_value;

	i = 0;
	while (i < dsp->nb_sprite - 1)
	{
		if (dsp->dist_to_p[i] < dsp->dist_to_p[i + 1])
		{
			old_value = dsp->dist_to_p[i];
			dsp->dist_to_p[i] = dsp->dist_to_p[i + 1];
			dsp->dist_to_p[i + 1] = old_value;
			old_value = dsp->sp_x[i];
			dsp->sp_x[i] = dsp->sp_x[i + 1];
			dsp->sp_x[i + 1] = old_value;
			old_value = dsp->sp_y[i];
			dsp->sp_y[i] = dsp->sp_y[i + 1];
			dsp->sp_y[i + 1] = old_value;
			i = 0;
		}
		else
			i++;
	}
}

int		is_view(t_img *img, t_draw_sp *dsp)
{
	int	i;

	i = 0;
	while (i < dsp->nb_sprite)
	{
		dsp->angle_sp = atan2((dsp->sp_y[i] - img->pos_y),
		(dsp->sp_x[i] - img->pos_x)) - (img->angle_start + img->angle_view / 2);
		dsp->sp_h = img->res_x / (dsp->dist_to_p[i] * cos(dsp->angle_sp));
		dsp->x_start = img->ratio * tan(dsp->angle_sp) * img->res_x
								- dsp->sp_h / 2 + img->res_x / 2;
		dsp->y_start = img->res_y / 2 - dsp->sp_h / 2;
		dsp->y_end = dsp->y_start + dsp->sp_h;
		dsp->x_end = dsp->x_start + dsp->sp_h;
		dsp->old_start_x = dsp->x_start;
		if (dsp->x_start < 0)
			dsp->x_start = 0;
		dsp->old_start_y = dsp->y_start;
		if (dsp->y_start < 0)
			dsp->y_start = 0;
		ft_draw_sp(img, dsp->x_start, dsp->y_start, i);
		i++;
	}
	return (1);
}

void	ft_draw_sp(t_img *img, int x, int y, size_t i)
{
	int		pixx;
	int		pixy;
	double	optipx;
	double	optipy;

	optipx = (img->draw_sp->x_end - img->draw_sp->old_start_x);
	optipy = (img->draw_sp->y_end - img->draw_sp->old_start_y);
	while (x < img->res_x)
	{
		pixx = (x - img->draw_sp->old_start_x) / optipx * img->skin->Sp->width;
		while (y < img->res_y && y < img->draw_sp->y_end)
		{
			pixy = (y - img->draw_sp->old_start_y)
						/ optipy * img->skin->Sp->height;
			if (pixy > 0 && pixy < img->skin->Sp->height && pixx > 0 && pixx <
				img->skin->Sp->width
				&& img->draw_sp->dist_to_p[i] < img->z_buffer[x]
				&& img->skin->Sp->color_tab[pixx][pixy] > 0)
				ft_mlx_pixel_put(img, x, y,
					img->skin->Sp->color_tab[pixx][pixy]);
			y++;
		}
		y = img->draw_sp->y_start;
		x++;
	}
}
