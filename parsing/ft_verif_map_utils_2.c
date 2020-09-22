/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 01:43:30 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/22 17:58:46 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/cub3d.h"

int	ft_pos_and_angle(size_t heigth, size_t width, t_img *param, char cardinal)
{
	param->pos_x = width + 0.5;
	param->pos_y = heigth + 0.5;
	param->angle_view = M_PI / 180 * 60;
	if (cardinal == 'N')
		param->angle_start = 3 * M_PI / 2 - (param->angle_view / 2);
	else if (cardinal == 'E')
		param->angle_start = -param->angle_view / 2;
	else if (cardinal == 'S')
		param->angle_start = M_PI / 2 - param->angle_view / 2;
	else if (cardinal == 'W')
		param->angle_start = M_PI - param->angle_view / 2;
	return (1);
}

int	return_free(void *ptr)
{
	free(ptr);
	return (0);
}
