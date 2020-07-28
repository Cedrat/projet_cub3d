/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance_to_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:30:59 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/28 03:10:04 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



double ft_distance(char **map, double angle, t_img *img)
{
	double posx = img->pos_x;
	double posy = img->pos_y;
	double posrayx = posx;
	double posrayy = posy;
	double nextwallx;
	double nextwally;
	double directionx = cos(angle);
	double directiony = sin(angle);
	int mapx = (int)posx;
	int mapy = (int)posy;
	double disttowall = 0;
	int hit = 0;
	int c = 0;
	double disttoy = 0;
	double disttox = 0;
	// printf("pos debut :%f|%f\n\n" , posrayx , posrayy);
	// printf("pos  x = %f\npos  y = %f\n\n", posx, posy);
	while (hit == 0)
	{
		if (directionx >= 0)
			nextwallx = 1 + ((int)posrayx - posrayx);// 	nextwallx = ((int)posrayx - posrayx) + 1;
		else
			nextwallx =  (int)posrayx - posrayx;
		if (directiony >= 0)									 //passage ok
			nextwally = 1 + ((int)posrayy - posrayy);// 	nextwally = ((int)posrayy - posrayy) + 1;
		else
			nextwally = ((int)posrayy) - posrayy;
		if (nextwally == 0)
		 	nextwally = -1;
		if (nextwallx == 0)
			nextwallx = -1;
		// printf("nextwall x = %f\nnextwall y = %f\n", nextwallx, nextwally);
		// printf("direction x = %f\ndirSection y = %f\n", directionx, directiony);
		disttox = ft_abs(nextwallx) / cos(angle);
		disttoy = ft_abs(nextwally) / sin(angle);
		// printf("disttox x = %f\ndisttoy y = %f\n", disttox, disttoy);
		if ((ft_abs(disttox) < ft_abs(disttoy)) || (disttoy == 0))
		{
			posrayy += nextwallx * tan(angle);
			posrayx = posrayx + nextwallx;
			mapx += (directionx > 0) ? 1 : -1;
		}
		else
		{
			posrayx += nextwally * tan((M_PI/2 - angle));
			posrayy = nextwally + posrayy;
			mapy += (directiony > 0) ? 1 : -1;
		}
		// printf("pos rayon x = %f\npos rayon y = %f\n\n", posrayx, posrayy);
		if (map[mapy][mapx] == '1')
			hit = 1;
	}
	if (directiony < 0 && ft_abs(disttox) > ft_abs(disttoy))
		img->side = 'N';
	else if (directiony > 0 && ft_abs(disttox) > ft_abs(disttoy))
		img->side = 'S';
	else if (directionx > 0)
		img->side = 'E';
	else
		img->side = 'W';
	img->vect_x = ft_floatypart(posrayx);
	img->vect_y = ft_floatypart(posrayy);
	disttowall = hypot((posrayx - posx),(posrayy - posy));
	return (disttowall);
}
