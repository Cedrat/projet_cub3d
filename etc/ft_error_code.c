/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:14:30 by lnoaille          #+#    #+#             */
/*   Updated: 2020/09/24 19:33:49 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header/cub3d.h"

int	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (write(1, &str[i], 1) == -1)
			return (ft_err_code(-1));
		i++;
	}
	return (1);
}

int	ft_err_code(int i)
{
	if (i == -1 && !(ft_putstr("Error\nwrite failed.. Serious ?\n")))
		return (0);
	else if (i == 0 && !(ft_putstr("Error\nWrong data for res\n")))
		return (ft_err_code(-1));
	else if (i == 1 && !(ft_putstr("Error\nduplicate data\n")))
		return (ft_err_code(-1));
	else if (i == 2 && !(ft_putstr("Error\ninvalid map\n")))
		return (ft_err_code(-1));
	else if (i == 3 && !(ft_putstr("Error\nFile not exist\n")))
		return (ft_err_code(-1));
	else if (i == 4 && !(ft_putstr("Error\ninvalid map\n")))
		return (ft_err_code(-1));
	else if (i == 5 && !(ft_putstr("Error\nplayer out of map\n")))
		return (ft_err_code(-1));
	else if (i == 6 && !(ft_putstr("Error\nnumber of start pos invalid\n")))
		return (ft_err_code(-1));
	else if (i == 7 && !(ft_putstr("Error\nmalloc failed\n")))
		return (ft_err_code(-1));
	else if (i == 8 && !(ft_putstr("Error\nFile not exist or invalid xpm \n")))
		return (ft_err_code(-1));
	else if (i == 9 && !(ft_putstr("Error\ngnl failed\n")))
		return (ft_err_code(-1));
	else
		return (ft_err_code_2(i));
}

int	ft_err_code_2(int i)
{
	if (i == 10 && !(ft_putstr("Error\ninvalid reso\n")))
		return (ft_err_code(-1));
	else if (i == 11 && !(ft_putstr("Error\nfailed mlxlib\n")))
		return (ft_err_code(-1));
	else if (i == 12 && !(ft_putstr("Error\ninvalid file or extension\n")))
		return (ft_err_code(-1));
	else if (i == 13 && !(ft_putstr("Error\ninvalid rgb\n")))
		return (ft_err_code(-1));
	else if (i == 14 && !(ft_putstr("Error\ndata in double\n")))
		return (ft_err_code(-1));
	else if (i == 15 && !(ft_putstr("Error\nmissing data\n")))
		return (ft_err_code(-1));
	else if (i == 16 && !(ft_putstr("Error\nimpossible to create fd\n")))
		return (ft_err_code(-1));
	else if (i == 17 && !(ft_putstr("Error\ninvalid args\n")))
		return (ft_err_code(-1));
	else if (i == 18 && !(ft_putstr("Error\nres not supported with --save\n")))
		return (ft_err_code(-1));
	return (0);
}
