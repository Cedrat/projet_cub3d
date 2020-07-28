/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:07:39 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/20 19:34:55 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parsing(char *pathname, t_img *param)
{
	int		fd;
	char	*line;
	char	*map;

	if (!(map = malloc(sizeof(char))))
		return (ft_err_code(7));
	map[0] = '\0';
	if ((fd = open(pathname, O_RDONLY)) == -1)
		return (ft_err_code(8));
	if (!(ft_while_parsing(fd, line, &map, param)))
		return (0);
	if (!(ft_extract_map(param, map)))
		return (0);
	close(fd);
	return (1);
}

int	ft_while_parsing(int fd, char *line, char **map, t_img *param)
{
	int ret;
	int parsing_value;

	ret = 1;
	while (ret)
	{
		if ((ret = get_next_line(fd, &line)) == -1)
			return (ft_err_code(9));
		parsing_value = ft_extract_data(param, line);
		if (parsing_value == 2)
		{
			if (!(*map = ft_strjoin_f(*map, line)))
				return (ft_err_code(7));
			free(line);
			ft_while_while_parsing(fd, line, map, &ret);
		}
		else if (parsing_value == 0)
			return (0);
		else
			free(line);
	}
	return (1);
}

int	ft_while_while_parsing(int fd, char *line, char **map, int *ret)
{
	while (*ret)
	{
		if ((*ret = get_next_line(fd, &line)) == -1)
			return (ft_err_code(9));
		if (!(*map = ft_strjoin_f(*map, line)))
			return (ft_err_code(7));
		free(line);
	}
}
