/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 00:14:25 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/15 16:51:01 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	void	*dst;

	dst = data->img_addr + (y * data->line_length + x *
		(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	ft_floatypart(double a)
{
	if (a < 0)
		a = -a;
	a = a - (int)a;
	return (a);
}

int ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
