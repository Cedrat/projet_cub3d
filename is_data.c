/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:13:22 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/14 01:53:59 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_is_cub(char *file)
{
    size_t len;
    len = ft_strlen(file);
    if (!(len > 4 && file[len - 4] == '.' && file[len - 3] == 'c'
    && file[len - 2] == 'u' && file[len - 1] == 'b'))
        return (ft_err_code(12));
    return (1);
}

int ft_is_rgb(char *file)
{
    size_t i;
    size_t len;
    size_t i_old;

    len = ft_strlen(file);
    i = 0;
    while (file[i] == ' ' && i < len)
        i++;
    i_old = i;
    while (file[i] >= '0' && file[i] <= '9' && i < len)
        i++;
    if (i_old == i)
        return(ft_err_code(13));
    while (file[i] == ' ' && i < len)
        i++;
    if (file[i] == ',' && i < len)
        i++;
    while (file[i] == ' ' && i < len)
        i++;
    i_old = i;
    while (file[i] >= '0' && file[i] <= '9' && i < len)
        i++;
    if (i_old == i)
        return(ft_err_code(13));
    while (file[i] == ' ' && i < len)
     i++;
    if (file[i] == ',' && i < len)
        i++;
    while (file[i] == ' ' && i < len)
        i++;
    i_old = i;
    while (file[i] >= '0' && file[i] <= '9' && i < len)
        i++;
    if (i_old == i || i < (len - 1))
    	return (ft_err_code(13));
    return (1);
}
