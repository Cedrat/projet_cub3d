/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 18:47:12 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/28 20:56:31 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_quicksort(t_draw_sp *dsp)
{
	int i;
	double old_value;

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

// void nb_print_sp(t_img *img, t_draw_sp *dsp)
// {
// 	is_view(img, dsp);
// }

int is_view(t_img *img, t_draw_sp *dsp)
{
	int i = 0;
	double angle_sp;
	double limit_value;
	double sprite_size;
	double x;
	int x_start;
	int x_end;
	int y_start;
	int y_end;
	int		**map;
	t_wall	*sp;
	sp = img->skin->Sp;
	map = sp->color_tab;
	while (i < dsp->nb_sprite)
	{
		angle_sp = atan2((dsp->sp_y[i] - img->pos_y), (dsp->sp_x[i] - img->pos_x)) - (img->angle_start);
		limit_value = 0;
		sprite_size =  1/(cos(angle_sp - img->angle_view/2) * hypot((dsp->sp_y[i] - img->pos_y), (dsp->sp_x[i] - img->pos_x)));
		x = angle_sp/img->angle_view;

		x_start = (x- sprite_size/2) *img->res_x;
		x_end = (x + sprite_size/2) *img->res_x;
		dprintf(1, "%f\n", x * 180 / M_PI);
		y_start = (-sprite_size/2 + 0.5) *img->res_y;
		y_end = (sprite_size/2 + 0.5) *img->res_y;
		// y = 1/(cos(angle_sp - img->angle_view/2) * hypot((dsp->sp_y[i] - img->pos_y), (dsp->sp_x[i] - img->pos_x))) * img->res_y;
		// y_start = ()
		int old_x = x_start;
		int old_y = y_start;
		if (x_start < 0)
			x_start = 0;

		double diff_y = y_end - y_start;
		double diff_x = x_end - x_start;

		if (y_start < 0)
			y_start = 0;
		if (x_end > img->res_x)
			x_end = img->res_x - 1;
		if (y_end > img->res_y)
			y_end = img->res_y - 1;
		int p = x_start;
		int y = y_start;

			while (p < x_end)
			{
				int pixx = (double)(p - old_x) * (((double)sp->width) / (double)(diff_x));
				while (y < y_end)
				{
					int y_pixx = (double)(y - old_y) * (((double)sp->height) / diff_y);
					if (y_pixx > 0 && map[pixx][y_pixx]!= 0)
						ft_mlx_pixel_put(img, p, y, map[pixx][y_pixx]);
					// dprintf(1, "pixx = %d pixy = %d\n", pixx, y_pixx);
					y++;
				}
				y = y_start;
				p++;
			}
		i++;
	}
}

	// dprintf(1, "x_start = |%d\n", y_start);
	// dprintf(1, "x_end = |%d\n", y_end);
	// dprintf(1, "y_pos = |%f\n", img->pos_y);
