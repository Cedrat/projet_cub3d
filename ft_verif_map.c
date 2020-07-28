/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:14:19 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/24 16:23:35 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_verif_map_w(t_img *param)
{
	size_t	h;
	size_t	w;
	int		ok;
	size_t	nbr_flags;

	ft_initialize_data(&nbr_flags, &ok, &h, &w);
	while (h < param->map_heigth)
	{
		while (w++ < param->map_width)
		{
			if (ft_ispos(ok, param->map[h][w - 1]))
			{
				nbr_flags++;
				ok = 0;
				ft_pos_and_angle(h, w - 1, param, param->map[h][w - 1]);
			}
			else if (!(ft_verif(param->map[h][w - 1], &ok)))
				return (0);
		}
		if (ft_initial(&ok, &w, &h) == 0)
			return (0);
	}
	if (nbr_flags != 1)
		return (ft_err_code(6));
	return (1);
}

int	ft_verif_map_h(t_img *param)
{
	size_t	h;
	size_t	w;
	int		ok;
	size_t	nbr_flags;

	ft_initialize_data(&nbr_flags, &ok, &h, &w);
	while (w < param->map_width)
	{
		while (h++ < param->map_heigth)
		{
			if (ft_ispos(ok, param->map[h - 1][w]))
			{
				nbr_flags++;
				ok = 0;
			}
			else if (!(ft_verif(param->map[h - 1][w], &ok)))
				return (0);
		}
		if (ft_initial(&ok, &h, &w) == 0)
			return (0);
	}
	if (nbr_flags != 1)
		return (ft_err_code(6));
	return (1);
}
