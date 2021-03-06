/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:10:31 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/26 03:36:57 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/cub3d.h"

int		ft_count_sp(t_img *param)
{
	size_t	h;
	size_t	w;

	h = 0;
	w = 0;
	param->draw_sp->nb_sprite = 0;
	while (h < param->map_heigth)
	{
		while (w < param->map_width)
		{
			if (param->map[h][w] == '2')
				param->draw_sp->nb_sprite++;
			w++;
		}
		w = 0;
		h++;
	}
	return (ft_put_sp_xy(param, param->draw_sp));
}

int		ft_put_sp_xy(t_img *param, t_draw_sp *dsp)
{
	size_t	h;
	size_t	w;
	size_t	i;

	h = 0;
	w = 0;
	i = 0;
	if (!ft_init_s_sp(dsp))
		return (0);
	while (h < param->map_heigth)
	{
		while (w < param->map_width)
		{
			if (param->map[h][w] == '2')
			{
				dsp->sp_x[i] = w + 0.5;
				dsp->sp_y[i] = h + 0.5;
				i++;
			}
			w++;
		}
		w = 0;
		h++;
	}
	return (1);
}

void	ft_dist_to_p(t_draw_sp *dsp, double pos_x, double pos_y)
{
	int		i;
	double	*sp_x;
	double	*sp_y;

	sp_x = dsp->sp_x;
	sp_y = dsp->sp_y;
	i = 0;
	while (i < dsp->nb_sprite)
	{
		dsp->dist_to_p[i] = hypot((pos_x - sp_x[i]), (pos_y - sp_y[i]));
		i++;
	}
	ft_quicksort(dsp);
}

int		ft_init_s_sp(t_draw_sp *dsp)
{
	if (dsp->nb_sprite >= 0)
	{
		if (!(dsp->sp_x = malloc(sizeof(double) * dsp->nb_sprite)))
			return (ft_err_code(7));
		if (!(dsp->sp_y = malloc(sizeof(double) * dsp->nb_sprite)))
			return (ft_err_code(7));
		if (!(dsp->dist_to_p = malloc(sizeof(double) * dsp->nb_sprite)))
			return (ft_err_code(7));
	}
	return (1);
}
