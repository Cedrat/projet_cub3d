/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 00:03:24 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/10 01:07:42 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_view(t_img *img, int res_x, t_draw_sp *dsp)
{
	double angle;
	double alpha;
	size_t x;
	double angle_x;
	double ratio;
	double angle_prec;

	ratio = 0.5/tan(img->angle_view/2);
	angle_prec = 0;
	x = 0;
	while (x < img->res_x)
	{
		angle_x = 2*(img->angle_view/2 - atan((0.5 - (double)x/img->res_x)/ratio)) - angle_prec;
		angle_prec = angle_x;
		angle = img->angle_start + angle_x;
		alpha = img->angle_view/2 - angle_x;
		img->z_buffer[x] = ft_distance(img->map, angle, img);
		ft_create_wall(img->z_buffer[x] * cos(alpha), x, img);
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
	h = floor(img->res_x/(dist_wall));
	y = 0;
	while (y < (img->res_y/ 2 - h / 2) && y < img->res_y)
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
