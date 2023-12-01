/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:32:40 by codespace         #+#    #+#             */
/*   Updated: 2023/09/21 15:34:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	put_unum(unsigned long int nb)
{
	char	c;

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb > 9)
		put_unum((nb / 10));
	if (nb < 10)
	{
		c = '0' + nb;
		write(1, &c, 1);
		return ;
	}
	put_unum((nb % 10));
}

int	print_unum(va_list args)
{
	unsigned int	nb;
	int				count;

	nb = va_arg(args, unsigned int);
	put_unum(nb);
	count = 0;
	if (!nb)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	print_str(va_list args)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	print_c(va_list args)
{
	int	x;

	x = va_arg(args, int);
	write(1, &x, 1);
	return (1);
}

int	launch_print(char c, va_list args)
{
	if (c == 'c')
		return (print_c(args));
	else if (c == 's')
		return (print_str(args));
	else if (c == 'p')
		return (print_address(args));
	else if (c == 'd' || c == 'i')
		return (print_nbr(args));
	else if (c == 'u')
		return (print_unum(args));
	else if (c == 'x')
		return (print_hex(args, 0));
	else if (c == 'X')
		return (print_hex(args, 1));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (-1);
}
