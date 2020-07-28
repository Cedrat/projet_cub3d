/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 20:05:50 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/23 19:33:38 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*ft_init_s_img(void)
{
	t_img *img;

	if (!(img = malloc(sizeof(t_img))))
		return (0);
	if (!(img->draw_sp = malloc(sizeof(t_draw_sp))))
		return (0);
	if (!(img->skin = malloc(sizeof(t_textures))))
		return (0);
	if (!(img->skin->N = malloc(sizeof(t_wall))))
		return (0);
	if (!(img->skin->E = malloc(sizeof(t_wall))))
		return (0);
	if (!(img->skin->S = malloc(sizeof(t_wall))))
		return (0);
	if (!(img->skin->W = malloc(sizeof(t_wall))))
		return (0);
	if (!(img->skin->Sp = malloc(sizeof(t_wall))))
		return (0);
	return (img);
}

int		ft_extract_img(t_img *param, char *line, char face)
{
	char *path;

	if ((path = ft_path_extract(line)) == "fail")
		return (ft_err_code(7));
	if (!(ft_create_img(param, path, face)))
		return (0);
	return (1);
}

char	*ft_path_extract(char *line)
{
	size_t	i;
	size_t	size;
	char	*path;
	size_t	start;

	i = 0;
	size = 0;
	while (line[i] == ' ')
		i++;
	start = i;
	while (line[i] != ' ' && line[i] != ' ' && line[i] != '\n')
	{
		i++;
		size++;
	}
	if (!(path = ft_substr(line, start, size)))
		return ("fail");
	return (path);
}
