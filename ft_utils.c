/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoaille <lnoaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 20:19:24 by lnoaille          #+#    #+#             */
/*   Updated: 2020/07/22 17:36:46 by lnoaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_atoi(const char *str)
{
	int count;
	int neg;
	int number;

	number = 0;
	neg = 1;
	count = 0;
	while (str[count] == ' ' || str[count] == '\f' || str[count] == '\n'
	|| str[count] == '\r' || str[count] == '\v' || str[count] == '\t')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			neg = -1;
		count++;
	}
	while ('0' <= str[count] && str[count] <= '9' && str[count])
	{
		number = number * 10 + (str[count] - '0');
		count++;
	}
	return (number * neg);
}

int		ft_create_rgb(int r, int g, int b)
{
	int rgb;

	rgb = b + g * 256 + r * 256 * 256;
	return (rgb);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int divider;
	unsigned int nb2;
	unsigned int abs_nb;

	divider = 1;
	if (n < 0)
	{
		abs_nb = -n;
		ft_putchar_fd('-', fd);
	}
	else
		abs_nb = n;
	nb2 = abs_nb;
	while (nb2 > 9)
	{
		divider = divider * 10;
		nb2 = nb2 / 10;
	}
	while (divider)
	{
		ft_putchar_fd((abs_nb / divider) + '0', fd);
		abs_nb = abs_nb % divider;
		divider = divider / 10;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

double	ft_abs(double a)
{
	if (a < 0)
		a = -a;
	return (a);
}
