/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:13:22 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/12 15:29:19 by lnoaille         ###   ########.fr       */
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
