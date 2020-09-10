/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance_to_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:30:59 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/10 17:14:59 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_distance(char **map, double angle, t_img *img, t_dda *dda)
{
	init_t_dda(angle, img, dda);
	while (map[dda->mapy][dda->mapx] != '1')
	{
		dda->nextwallx = ft_next_intersect(dda->dir_x, dda->mapx, dda->posrayx);
		dda->nextwally = ft_next_intersect(dda->dir_y, dda->mapy, dda->posrayy);
		dda->disttox = ft_abs(dda->nextwallx / dda->dir_x);
		dda->disttoy = ft_abs(dda->nextwally / dda->dir_y);
		if (dda->disttox < dda->disttoy || (dda->disttoy == 0))
		{
			dda->posrayy += dda->nextwallx * dda->tan_angle;
			dda->posrayx += dda->nextwallx;
			dda->mapx += (dda->dir_x > 0) ? 1 : -1;
		}
		else
		{
			dda->posrayx += dda->nextwally / dda->tan_angle;
			dda->posrayy += dda->nextwally;
			dda->mapy += (dda->dir_y > 0) ? 1 : -1;
		}
	}
	img->side = wall_side(dda->dir_x, dda->dir_y, dda->disttox, dda->disttoy);
	img->vect_x = ft_floatypart(dda->posrayx);
	img->vect_y = ft_floatypart(dda->posrayy);
	return (hypot((dda->posrayx - img->pos_x), (dda->posrayy - img->pos_y)));
}

void	init_t_dda(double angle, t_img *img, t_dda *dda)
{
	dda->dir_x = cos(angle);
	dda->dir_y = sin(angle);
	dda->tan_angle = tan(angle);
	dda->posrayx = img->pos_x;
	dda->posrayy = img->pos_y;
	dda->mapx = (int)(dda->posrayx);
	dda->mapy = (int)(dda->posrayy);
}

char	wall_side(double dir_x, double dir_y, double dist_to_x,
		double dist_to_y)
{
	if (dir_y < 0 && ft_abs(dist_to_x) > ft_abs(dist_to_y))
		return ('N');
	else if (dir_y > 0 && ft_abs(dist_to_x) > ft_abs(dist_to_y))
		return ('S');
	else if (dir_x > 0)
		return ('E');
	else
		return ('W');
}

double	ft_next_intersect(double direction, int map, double player_pos)
{
	double nextwall;

	if (direction >= 0)
		nextwall = 1 + (map - player_pos);
	else
		nextwall = map - player_pos;
	if (nextwall == 0)
		nextwall = -1;
	return (nextwall);
}
