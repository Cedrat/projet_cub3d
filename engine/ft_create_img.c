/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 20:12:51 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/18 12:45:38 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/cub3d.h"

int	ft_create_img(t_img *param, char *temp, char side)
{
	t_wall *face;

	if (side == 'N')
		face = param->skin->n;
	else if (side == 'E')
		face = param->skin->e;
	else if (side == 'W')
		face = param->skin->w;
	else if (side == 'S')
		face = param->skin->s;
	else if (side == 'p')
		face = param->skin->sp;
	else
		return (0);
	if ((face->img = mlx_xpm_file_to_image(param->mlx_ptr, temp,
		&face->width, &face->height)) == NULL)
		return (ft_err_code(8));
	free(temp);
	if (!(face->color_tab = ft_color_tab(face)))
		return (ft_err_code(7));
	return (1);
}

int	**ft_color_tab(t_wall *face)
{
	int	x;
	int	y;
	int	**color_tab;

	x = 0;
	y = 0;
	face->img_addr = (int *)mlx_get_data_addr(face->img,
		&face->bpp, &face->size_line, &face->endian);
	if (!(color_tab = malloc(sizeof(int *) * face->width)))
		return (NULL);
	while (x < face->width)
	{
		if (!(color_tab[x] = malloc(sizeof(int) * face->height)))
			return (NULL);
		while (y < face->height)
		{
			color_tab[x][y] = *((int *)(face->img_addr +
				(y * face->size_line) + (x * face->bpp / 8)));
			y++;
		}
		y = 0;
		x++;
	}
	return (color_tab);
}
