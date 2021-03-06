/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 20:05:50 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/18 12:35:24 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/cub3d.h"

t_img	*ft_init_s_img(void)
{
	t_img *img;

	if (!(img = malloc(sizeof(t_img))))
		return (0);
	if (!(img->secu = malloc(sizeof(t_secu))))
		return (0);
	ft_init_secu(img->secu);
	if (!(img->draw_sp = malloc(sizeof(t_draw_sp))))
		return (0);
	if (!(img->skin = malloc(sizeof(t_textures))))
		return (0);
	if (!(img->dda = malloc(sizeof(t_dda))))
		return (0);
	if (!(img->skin->n = malloc(sizeof(t_wall))))
		return (0);
	if (!(img->skin->e = malloc(sizeof(t_wall))))
		return (0);
	if (!(img->skin->s = malloc(sizeof(t_wall))))
		return (0);
	if (!(img->skin->w = malloc(sizeof(t_wall))))
		return (0);
	if (!(img->skin->sp = malloc(sizeof(t_wall))))
		return (0);
	return (img);
}

int		ft_extract_img(t_img *param, char *line, char face)
{
	char *path;

	if (!(check_secu_tex(param, face)))
		return (0);
	if ((ft_strcmp(path = ft_path_extract(line), "fail") == 0))
		return (ft_err_code(7));
	if (!(ft_create_img(param, path, face)))
	{
		free(path);
		return (0);
	}
	if (face == 'N')
		param->secu->tex_n++;
	else if (face == 'E')
		param->secu->tex_e++;
	else if (face == 'S')
		param->secu->tex_s++;
	else if (face == 'W')
		param->secu->tex_w++;
	else if (face == 'p')
		param->secu->tex_sp++;
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

void	ft_init_secu(t_secu *secu)
{
	secu->floor = 0;
	secu->ceil = 0;
	secu->res = 0;
	secu->tex_n = 0;
	secu->tex_s = 0;
	secu->tex_e = 0;
	secu->tex_w = 0;
	secu->tex_sp = 0;
	secu->map = 0;
}

int		check_secu_tex(t_img *param, char face)
{
	if (face == 'N' && param->secu->tex_n != 0)
		return (ft_err_code(14));
	else if (face == 'S' && param->secu->tex_s != 0)
		return (ft_err_code(14));
	else if (face == 'W' && param->secu->tex_w != 0)
		return (ft_err_code(14));
	else if (face == 'E' && param->secu->tex_e != 0)
		return (ft_err_code(14));
	else if (face == 'p' && param->secu->tex_sp != 0)
		return (ft_err_code(14));
	return (1);
}
