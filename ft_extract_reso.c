/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_reso.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:21:28 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/18 23:05:37 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_extract_reso(char *line, t_img *param)
{
	size_t	i;
	int		temp_resx;
	int		temp_resy;
	void	*mlx_ptr;

	if (!(mlx_ptr = mlx_init()))
		ft_err_code(ft_err_code(11));
	mlx_get_screen_size(mlx_ptr, &temp_resx, &temp_resy);
	i = 0;
	param->res_y = 0;
	param->res_x = ft_atoi(line);
	while (line[i] == ' ')
		i++;
	while ('0' <= line[i] && line[i] <= '9' && line[i])
		i++;
	param->res_y = ft_atoi(&line[i]);
	if (param->res_y <= 0 || param->res_x <= 0)
		return (ft_err_code(10));
	param->res_y = (temp_resy < param->res_y) ? temp_resy : param->res_y;
	param->res_x = (temp_resx < param->res_x) ? temp_resx : param->res_x;
	return (1);
}
