/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:22:59 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/27 20:12:23 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_extract_color(char *line, t_img *param)
{
	size_t	i;
	int		r;
	int		g;
	int		b;

	i = 1;
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
	if (line[0] == 'C')
		param->skin->c = ft_create_rgb(r, g, b);
	else if (line[0] == 'F')
		param->skin->f = ft_create_rgb(r, g, b);
	return (1);
}
