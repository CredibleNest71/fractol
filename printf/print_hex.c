/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:39:32 by codespace         #+#    #+#             */
/*   Updated: 2023/09/21 15:21:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_putnbr_hex(unsigned long int nbr, char *base, int *count)
{
	unsigned long int	nb;

	nb = (unsigned int)nbr;
	if (nb == 0)
	{
		*count += 1;
		write(1, "0", 1);
		return ;
	}
	if (nb > 15)
		ft_putnbr_hex((nb / 16), base, count);
	if (nb < 16)
	{
		*count += 1;
		write(1, &base[nb], 1);
		return ;
	}
	ft_putnbr_hex((nb % 16), base, count);
}

int	print_hex(va_list args, int major)
{
	int	n;
	int	count;

	count = 0;
	n = va_arg(args, int);
	if (major)
		ft_putnbr_hex(n, "0123456789ABCDEF", &count);
	else
	{
		ft_putnbr_hex(n, "0123456789abcdef", &count);
	}
	return (count);
}

void	put_address(unsigned long int nb, char *base, int *count)
{
	if (nb == 0)
	{
		*count += 1;
		write(1, "0", 1);
		return ;
	}
	if (nb > 15)
		put_address((nb / 16), base, count);
	if (nb < 16)
	{
		*count += 1;
		write(1, &base[nb], 1);
		return ;
	}
	put_address((nb % 16), base, count);
}

int	print_address(va_list args)
{
	size_t	address;
	int		count;

	count = 0;
	address = va_arg(args, long int);
	if (!address)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	put_address(address, "0123456789abcdef", &count);
	return (count + 2);
}
