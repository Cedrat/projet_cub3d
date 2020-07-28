/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:58:13 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/20 19:56:58 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_extract_map(t_img *param, char *map)
{
	size_t heigth;
	size_t width;
	size_t i;
	size_t p;

	width = 0;
	heigth = 0;
	i = 0;
	p = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			heigth++;
			width = (p > width) ? p : width;
			p = 0;
		}
		i++;
		p++;
	}
	param->map_width = width;
	param->map_heigth = heigth;
	if (!(ft_convert_map(map, param)))
		return (0);
	return (1);
}

int		ft_convert_map(char *map, t_img *param)
{
	char	**map_i;
	size_t	h;
	size_t	w;
	size_t	i;

	i = 0;
	w = 0;
	h = 0;
	if (!(map_i = malloc(sizeof(char *) * param->map_heigth)))
		return (ft_err_code(7));
	while (h++ < param->map_heigth)
	{
		if (!(map_i[h - 1] = malloc(sizeof(char) * param->map_width)))
			return (ft_err_code(7));
		while (w < param->map_width && map[i] != '\n')
			ft_convert_map_utils(&w, &i, &map_i[h - 1][w], &map[i]);
		while (w++ < param->map_width)
			map_i[h - 1][w - 1] = ' ';
		i++;
		w = 0;
	}
	param->map = map_i;
	if (!(ft_verif_map_h(param) && ft_verif_map_w(param)))
		return (0);
	return (1);
}

void	ft_convert_map_utils(size_t *w, size_t *i, char *a, char *b)
{
	*a = *b;
	*i = *i + 1;
	*w = *w + 1;
}
