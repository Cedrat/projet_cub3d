/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:00:23 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/16 21:30:09 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h>

int	get_line(int fd, char **temp)
{
	char	buff[BUFFER_SIZE + 1];
	int		end;

	end = read(fd, buff, BUFFER_SIZE);
	if (end == -1)
	{
		free(*temp);
		return (-1);
	}
	buff[end] = '\0';
	if (end > 0)
		if (!(*temp = ft_strjoin_f(*temp, buff)))
			return (-1);
	if (ft_strchr(*temp, '\n'))
		return (1);
	else if (end != BUFFER_SIZE)
		return (0);
	else
		return (get_line(fd, *(&temp)));
}

int	append_line(int fd, char **line)
{
	char			*str;
	static	char	temp[BUFFER_SIZE + 1];
	int				return_value;
	size_t			x;

	x = 0;
	return_value = 1;
	if (!(str = ft_substr(temp, 0, ft_strlen(temp))))
		return (-1);
	if (!(ft_strchr(str, '\n')))
		if ((return_value = get_line(fd, &str)) == -1)
			return (-1);
	while (str[x] != '\n' && str[x])
		x++;
	if (!(*line = ft_substr(str, 0, x + 1)))
		return (-1);
	if (str[0] && return_value != 0)
		ft_strlcpy(temp, str + x + 1, ft_strlen(str) - (x));
	free(str);
	if (return_value == 0)
	{
		temp[0] = '\0';
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	if (BUFFER_SIZE < 1)
		return (-1);
	return (append_line(fd, &(*line)));
}
