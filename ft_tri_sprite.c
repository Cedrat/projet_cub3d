/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 18:47:12 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/28 03:01:07 by lnoaille         ###   ########.fr       */
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
	angle_sp = atan2((dsp->sp_y[i] - img->pos_y), (dsp->sp_x[i] - 0.5 - img->pos_x));
	limit_value = 0;

	if (img->angle_start < angle_sp && angle_sp < (img->angle_start + img->angle_view))
		write(1, "ok", 2);
	angle_sp = atan2((dsp->sp_y[i] - img->pos_y), (dsp->sp_x[i] + 0.5 - img->pos_x));
		// while(angle_sp >= M_PI)
		// 	angle_sp -= M_PI;
		// while(angle_sp <= -M_PI)
		// 	angle_sp += M_PI;
	if (img->angle_start < angle_sp && angle_sp < (img->angle_start + img->angle_view))
		write(1, "bi", 2);
	dprintf(1, "%f\n", img->angle_start + img->angle_view);
}
