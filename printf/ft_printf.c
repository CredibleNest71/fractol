/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:50:36 by codespace         #+#    #+#             */
/*   Updated: 2023/10/02 13:48:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include "libft/libft.h"

int	in_set(char c)
{
	int		i;
	char	*set;

	set = "cspdiuxX%";
	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

int	ft_printf(const char *in, ...)
{
	va_list	args;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	va_start(args, in);
	while (in[i])
	{
		if (in[i] == '%' && in_set(in[i + 1]))
		{
			ret += launch_print(in[i + 1], args);
			i += 2;
			continue ;
		}
		write(1, &in[i], 1);
		ret++;
		i++;
	}
	va_end(args);
	return (ret);
}
