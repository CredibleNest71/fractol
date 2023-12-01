/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputundso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:35:02 by mresch            #+#    #+#             */
/*   Updated: 2023/12/01 16:59:50 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	print_correct_input(void)
{
	ft_printf("INVALID INPUT\n");
	ft_printf("please use the following parameters:\n");
	ft_printf("./fractal mandel\n");
	ft_printf("./fractal julia [real] [imaginary]\n");
	return (1);
}

int	get_input(int ac, char **av, t_vars *vars)
{
	if (ac > 4 || ac == 1 || ac == 3)
		return (print_correct_input());
	if (ac >= 2 && !ft_strncmp(av[1], "julia", 5))
	{
		vars->mode = 1;
		if (ac == 4)
		{
			vars->real = atod(av[2]);
			vars->imaginary = atod(av[3]);
		}
		return (0);
	}
	if (ac >= 2 && !ft_strncmp(av[1], "mandel", 6))
		return (0);
	return (1);
}
