/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:30:54 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/24 18:19:27 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/cub3d.h"

void	ft_wall_n(t_img *img, int h, int x, int *y)
{
	int		i;
	double	step;
	t_wall	*n;
	int		pixx;
	int		**map;

	n = img->skin->n;
	pixx = (img->vect_x * n->width);
	if (h > img->res_y)
	{
		i = (h - img->res_y) / 2;
	}
	else
		i = 0;
	map = n->color_tab;
	step = 0;
	while (i < h && *y < img->res_y)
	{
		step = i * n->height / h;
		ft_mlx_pixel_put(img, x, *y, map[pixx][(int)step]);
		i++;
		*y = *y + 1;
	}
}

void	ft_wall_s(t_img *img, int h, int x, int *y)
{
	int		i;
	double	step;
	t_wall	*s;
	int		pixx;
	int		**map;

	s = img->skin->s;
	map = s->color_tab;
	pixx = (s->width - img->vect_x * s->width);
	if (h > img->res_y)
	{
		i = (h - img->res_y) / 2;
	}
	else
		i = 0;
	step = 0;
	while (i < h && *y < img->res_y)
	{
		step = i * s->height / h;
		ft_mlx_pixel_put(img, x, *y, map[pixx][(int)step]);
		i++;
		*y = *y + 1;
	}
}

void	ft_wall_e(t_img *img, int h, int x, int *y)
{
	int		i;
	double	step;
	t_wall	*e;
	int		pixx;
	int		**map;

	e = img->skin->e;
	map = e->color_tab;
	pixx = (img->vect_y * e->width);
	if (h > img->res_y)
	{
		i = (h - img->res_y) / 2;
	}
	else
		i = 0;
	step = 0;
	while (i < h && *y < img->res_y)
	{
		step = i * e->height / h;
		ft_mlx_pixel_put(img, x, *y, map[pixx][(int)step]);
		i++;
		*y = *y + 1;
	}
}

void	ft_wall_w(t_img *img, int h, int x, int *y)
{
	int		i;
	double	step;
	t_wall	*w;
	int		pixx;
	int		**map;

	w = img->skin->w;
	map = w->color_tab;
	pixx = w->width - img->vect_y * w->width;
	if (h > img->res_y)
	{
		i = (h - img->res_y) / 2;
	}
	else
		i = 0;
	step = 0;
	while (i < h && *y < img->res_y)
	{
		step = i * w->height / h;
		ft_mlx_pixel_put(img, x, *y, map[pixx][(int)step]);
		i++;
		*y = *y + 1;
	}
}
