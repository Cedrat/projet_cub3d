/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:36:45 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/20 17:42:30 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_extract_data(t_img *param, char *line)
{
	size_t i;

	i = 0;
	while (line[i] == ' ' && line[i] != '\0')
		i++;
	if (line[i] == 'R' && line[i + 1] != '\0' && line[i + 1] != '\n'
		&& (!(ft_extract_reso(&line[i + 1], param))))
		return (0);
	else if (line[i] == 'C' && line[i + 1] != '\0' && line[i + 1] != '\n'
		&& (!(ft_extract_color(&line[i], param))))
		return (0);
	else if (line[i] == 'F' && line[i + 1] != '\0' && line[i + 1] != '\n'
		&& ((!ft_extract_color(&line[i], param))))
		return (0);
	else if (line[i] == 'N' && line[i + 1] == 'O'
		&& (!(ft_extract_img(param, &line[i + 2], line[i]))))
		return (0);
	else if (line[i] == 'S' && line[i + 1] == 'O'
		&& (!(ft_extract_img(param, &line[i + 2], line[i]))))
		return (0);
	else if (line[i] == 'W' && line[i + 1] == 'E'
		&& (!(ft_extract_img(param, &line[i + 2], line[i]))))
		return (0);
	else
		return (ft_extract_data_next(param, line, i));
}

int	ft_extract_data_next(t_img *param, char *line, int i)
{
	if (line[i] == 'E' && line[i + 1] == 'A'
		&& (!(ft_extract_img(param, &line[i + 2], line[i]))))
		return (0);
	else if (line[i] == 'S' && line[i + 1] != 'O'
	&& (!(ft_extract_img(param, &line[i + 1], 'p'))))
		return (0);
	else if (line[i] == '\n')
		return (1);
	else if (line[i] == '1' || line[i] == '0')
		return (2);
	else
		return (1);
}
