/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:13:22 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/17 00:08:43 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_is_cub(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (!(len > 4 && file[len - 4] == '.' && file[len - 3] == 'c'
	&& file[len - 2] == 'u' && file[len - 1] == 'b'))
		return (ft_err_code(12));
	return (1);
}

int		ft_is_rgb(char *file)
{
	size_t i;
	size_t len;

	len = ft_strlen(file);
	i = 0;
	if (!(i = ft_is_nb(i, file)))
		return (0);
	if (file[i] == ',' && i < len)
		i++;
	if (!(i = ft_is_nb(i, file)))
		return (0);
	if (file[i] == ',' && i < len)
		i++;
	if (!(i = ft_is_nb(i, file)))
		return (0);
	if ( i < (len - 1))
		return (ft_err_code(13));
	return (1);
}

size_t	ft_is_nb(size_t i, char *file)
{
	int i_old;

	while (file[i] == ' ' && file[i])
		i++;
	i_old = i;
	while (file[i] >= '0' && file[i] <= '9' && file[i])
		i++;
	if (i_old == i)
		return (ft_err_code(13));
	while (file[i] == ' ' && file[i])
		i++;
	return (i);
}
