/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 18:47:12 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/03 03:30:16 by lnoaille         ###   ########.fr       */
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
	double dist;
	t_wall	*sp;
	int pixx;
	int pixy;
	sp = img->skin->Sp;
	map = sp->color_tab;
	while (i < dsp->nb_sprite)
	{

		angle_sp = atan2((dsp->sp_y[i] - img->pos_y), (dsp->sp_x[i] - img->pos_x)) - (img->angle_start + img->angle_view/2); // not good enough
		limit_value = 0;
		dist = hypot((dsp->sp_y[i] - img->pos_y), (dsp->sp_x[i] - img->pos_x));
		sprite_size =  1/(cos(angle_sp) * dist);
		x = tan(angle_sp);

		dprintf(1, "pixx = |%f\n", x);
		x_start = x * img->res_x + img->res_x/2 - sprite_size/2 * img->res_x;
		y_start = img->res_y / 2 - sprite_size/2 * img->res_y;
		y_end = y_start + sprite_size * img->res_y;
		x_end = (x_start + sprite_size * img->res_x);
		// y = 1/(cos(angle_sp - img->angle_view/2) * hypot((dsp->sp_y[i] - img->pos_y), (dsp->sp_x[i] - img->pos_x))) * img->res_y;


		int p = x_start;
		int y = y_start;


			while (p < img->res_x)
			{
				pixx = (double)(p - x_start) / (x_end - x_start) * sp->width;

				while (y < img->res_y && y < y_end)
				{
					pixy = (double)(y - y_start) /(y_end - y_start) * sp->height;
					// dprintf(1, "pixx = |%d\n", pixy);
					if (pixy > 0 && pixy < sp->height && pixx > 0 && pixx < sp->width && map[pixx][pixy] > 0 )
						ft_mlx_pixel_put(img, p, y, map[pixx][pixy]);
					y++;
				}
				y = y_start;
				p++;
			}
		i++;
	}
	dprintf(1, "x_start = |%d\n", x_start);
	dprintf(1, "y_start = |%d\n", y_start);
	dprintf(1, "x_end = |%d\n", x_end);
	dprintf(1, "y_end = |%d\n", y_end);
}


	// dprintf(1, "x_end = |%d\n", y_end);
	// dprintf(1, "y_pos = |%f\n", img->pos_y);
