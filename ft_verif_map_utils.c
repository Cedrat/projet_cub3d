/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:37:25 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/22 01:44:36 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_ispos(int ok, char face)
{
	if ((ok == 0 || ok == 1) && (face == 'N' || face == 'S' || face == 'W' ||
	face == 'E'))
		return (1);
	else
		return (0);
}

int		ft_initial(int *ok, size_t *h, size_t *w)
{
	if (*ok == 0)
		return (ft_err_code(5));
	*ok = -1;
	*h = 0;
	*w = *w + 1;
}

int		ft_verif(char map, int *ok)
{
	if (*ok == -1 && (map == '0' || map == '2'))
		return (ft_err_code(4));
	else if (*ok == -1 && (map == 'N' || map == 'S'
	|| map == 'W' || map == 'E'))
		return (ft_err_code(5));
	else if (*ok == -1 && map == '1')
		*ok = 1;
	else if (*ok == 1 && (map == '0'))
		*ok = 0;
	else if (*ok == 0 && map == '1')
		*ok = 1;
	else if (*ok == 1 && map == ' ')
		*ok = -1;
	else if (*ok == 0 && map == ' ')
		return (ft_err_code(5));
	return (1);
}

void	ft_initialize_data(size_t *nbr_flags, int *ok, size_t *h, size_t *w)
{
	*nbr_flags = 0;
	*ok = -1;
	*h = 0;
	*w = 0;
}
