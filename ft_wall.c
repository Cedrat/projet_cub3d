/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:30:54 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/10 23:41:55 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_wall_n(t_img *img, int h, int x, int *y)
{
	int		i;
	double	step;
	t_wall	*n;
	int		pixx;
	int		**map;

	n = img->skin->N;
	pixx = floor(img->vect_x * n->width);
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
		ft_mlx_pixel_put(img, x, *y, map[pixx][(int)step]);
		step = i * n->height / h;
		i++;
		*y = *y + 1;
	}
}

int	ft_wall_s(t_img *img, int h, int x, int *y)
{
	int		i;
	double	step;
	t_wall	*s;
	int		pixx;
	int		**map;

	s = img->skin->S;
	map = s->color_tab;
	pixx = (int)(s->width - img->vect_x * s->width);
	if (h > img->res_y)
	{
		i = (h - img->res_y) / 2;
	}
	else
		i = 0;
	step = 0;
	while (i < h && *y < img->res_y)
	{
		ft_mlx_pixel_put(img, x, *y, map[pixx][(int)step]);
		step = i * s->height / h;
		i++;
		*y = *y + 1;
	}
}

int	ft_wall_e(t_img *img, int h, int x, int *y)
{
	int		i;
	double	step;
	t_wall	*e;
	int		pixx;
	int		**map;

	e = img->skin->E;
	map = e->color_tab;
	pixx = (int)(img->vect_y * e->width);
	if (h > img->res_y)
	{
		i = (h - img->res_y) / 2;
	}
	else
		i = 0;
	step = 0;
	while (i < h && *y < img->res_y)
	{
		ft_mlx_pixel_put(img, x, *y, map[pixx][(int)step]);
		step = i * e->height / h;
		i++;
		*y = *y + 1;
	}
}

int	ft_wall_w(t_img *img, int h, int x, int *y)
{
	int		i;
	double	step;
	t_wall	*w;
	int		pixx;
	int		**map;

	w = img->skin->W;
	map = w->color_tab;
	pixx = (int)(w->width - img->vect_y * w->width);
	if (h > img->res_y)
	{
		i = (h - img->res_y) / 2;
	}
	else
		i = 0;
	step = 0;
	while (i < h && *y < img->res_y)
	{
		ft_mlx_pixel_put(img, x, *y, map[pixx][(int)step]);
		step = i * w->height / h;
		i++;
		*y = *y + 1;
	}
}
