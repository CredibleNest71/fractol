/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:37:14 by codespace         #+#    #+#             */
/*   Updated: 2023/09/21 15:34:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	count_digits(int n)
{
	unsigned int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		digits++;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

int	check_outlier(int n, int fd)
{
	if (!n)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	int		i;

	i = 12;
	if (check_outlier(n, fd))
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	str[i--] = 0;
	while (n > 0)
	{
		str[i] = '0' + n % 10;
		n /= 10;
		i--;
	}
	while (str[++i])
		write(fd, &str[i], 1);
}

int	print_nbr(va_list args)
{
	int	n;

	n = va_arg(args, int);
	ft_putnbr_fd(n, 1);
	return (count_digits(n));
}
