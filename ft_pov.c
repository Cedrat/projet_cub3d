/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 00:03:24 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/03 03:43:51 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_view(t_img *img, int res_x, t_draw_sp *dsp)
{
	double angle;
	double alpha;
	double x;

	x = 0;
	while (x < img->res_x)
	{
		angle = img->angle_start + ((x / img->res_x) * img->angle_view);
		alpha = img->angle_view / 2 - (angle - img->angle_start);
		img->z_buffer[(int)x] = ft_abs(ft_distance(img->map, angle, img));
		ft_create_wall(img->z_buffer[(int)x] * cos(alpha), x, img);
		x++;
	}
	ft_dist_to_p(img, img->draw_sp, img->pos_x, img->pos_y);
	is_view(img, dsp);
}

void	ft_create_wall(double dist_wall, int pixel, t_img *img)
{
	int h;
	int y;
	int i;

	i = 0;
	h = (int)(img->res_y / (dist_wall));
	y = 0;
	while (y < (img->res_y / 2 - h / 2) && y < img->res_y)
	{
		ft_mlx_pixel_put(img, pixel, y, img->skin->c);
		y++;
	}
	if (img->side == 'N')
		ft_wall_n(img, h, pixel, &y);
	else if (img->side == 'W')
		ft_wall_w(img, h, pixel, &y);
	else if (img->side == 'E')
		ft_wall_e(img, h, pixel, &y);
	else
		ft_wall_s(img, h, pixel, &y);
	while (y < img->res_y)
	{
		ft_mlx_pixel_put(img, pixel, y, img->skin->f);
		y++;
	}
}
