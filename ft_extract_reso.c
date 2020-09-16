/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_reso.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:21:28 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/17 00:23:34 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_extract_reso(char *line, t_img *param)
{
	size_t	i;
	int		temp_resx;
	int		temp_resy;

	if (param->secu->res != 0)
		return (ft_err_code(14));
	if (!(ft_is_res(line)))
		return (0);
	mlx_get_screen_size(param->mlx_ptr, &temp_resx, &temp_resy);
	i = 0;
	param->res_y = 0;
	param->res_x = ft_atoi(line);
	i = ft_is_nb(i, line);
	param->res_y = ft_atoi(&line[i]);
	if (param->res_y <= 0 || param->res_x <= 0)
		return (ft_err_code(10));
	if (param->save == 0)
	{
		param->res_y = (temp_resy < param->res_y) ? temp_resy : param->res_y;
		param->res_x = (temp_resx < param->res_x) ? temp_resx : param->res_x;
		param->res_y = (param->res_y < 60) ? 60 : param->res_y;
		param->res_x = (param->res_x < 60) ? 60 : param->res_x;
	}
	param->secu->res++;
	return (1);
}

int	ft_is_res(char *line)
{
	size_t i;
	size_t len;
	size_t old_i;

	i = 0;
	len = ft_strlen(line);
	while (line[i] == ' ' && i < len)
		i++;
	if (line[i] > '9' || line[i] < '0')
		return (ft_err_code(10));
	old_i = i;
	while (line[i] <= '9' && line[i] >= '0' && i < len)
		i++;
	if (old_i == i)
		return (ft_err_code(10));
	while (line[i] == ' ' && i < len)
		i++;
	if (line[i] > '9' || line[i] < '0')
		return (ft_err_code(10));
	old_i = i;
	while (line[i] <= '9' && line[i] >= '0' && i < len)
		i++;
	if (old_i == i || i < (len - 1))
		return (ft_err_code(10));
}
