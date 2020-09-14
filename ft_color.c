/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:22:59 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/14 21:04:23 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_extract_color(char *line, t_img *param, char fc)
{
	size_t	i;
	int		r;
	int		g;
	int		b;

	if (fc == 'C' && param->secu->ceil != 0)
		return (ft_err_code(14));
	else if (fc == 'F' && param->secu->floor != 0)
		return (ft_err_code(14));
	if (fc == 'C')
		param->secu->ceil++;
	else if (fc == 'F')
		param->secu->floor++;
	if (!(ft_is_rgb(line)))
		return (0);
	i = 0;
	while (line[i] == ' ')
		i++;
	r = ft_atoi(&line[i]);
	while ('0' <= line[i] && line[i] <= '9' && line[i])
		i++;
	if (line[i] = ',')
		i++;
	g = ft_atoi(&line[i]);
	while ('0' <= line[i] && line[i] <= '9' && line[i])
		i++;
	if (line[i] = ',')
		i++;
	b = ft_atoi(&line[i]);
	if (fc == 'C')
		param->skin->c = ft_create_rgb(r, g, b);
	else if (fc == 'F')
		param->skin->f = ft_create_rgb(r, g, b);
	return (1);
}
