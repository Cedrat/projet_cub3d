/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:22:59 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/17 16:41:37 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_extract_color(char *line, t_img *param, char fc)
{
	size_t	i;
	int		r;
	int		g;
	int		b;

	if (fc == 'C' && param->secu->ceil != 0)
		return (ft_err_code(14));
	else if (fc == 'F' && param->secu->floor != 0)
		return (ft_err_code(14));
	if (!(ft_is_rgb(line)))
		return (0);
	i = 0;
	r = ft_atoi(&line[i]);
	if (!(i = ft_is_nb(i, line)))
		return (0);
	if (line[i] == ',')
		i++;
	g = ft_atoi(&line[i]);
	if (!(i = ft_is_nb(i, line)))
		return (0);
	if (line[i] == ',')
		i++;
	b = ft_atoi(&line[i]);
	create_c_f(fc, param, ft_create_rgb(r, g, b));
	return (1);
}

void	create_c_f(char side, t_img *param, unsigned int rgb_c)
{
	if (side == 'C')
		param->skin->c = rgb_c;
	else if (side == 'F')
		param->skin->f = rgb_c;
	if (side == 'C')
		param->secu->ceil++;
	else if (side == 'F')
		param->secu->floor++;
}
