/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:42:13 by mresch            #+#    #+#             */
/*   Updated: 2023/12/01 17:26:58 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_complex	c_squared(t_complex c)
{
	t_complex	z;

	z.real = (c.real * c.real) - (c.imag * c.imag);
	z.imag = 2 * c.real * c.imag;
	return (z);
}

t_complex	c_add(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.real = a.real + b.real;
	ret.imag = a.imag + b.imag;
	return (ret);
}

double	absolute(t_complex c)
{
	return (sqrt(c.real * c.real + c.imag * c.imag));
}

int	mandelbrot(double x, double y, t_vars *vars)
{
	t_complex	c;
	t_complex	z;
	int			i;

	vars->imaginary = 0;
	c.real = x;
	c.imag = y;
	z.real = 0;
	z.imag = 0;
	i = 0;
	while (i < vars->iterations)
	{
		if (absolute(z) >= 2)
			return (i);
		z = c_add(c_squared(z), c);
		i++;
	}
	return (0);
}

int	julia(double x, double y, t_vars *vars)
{
	t_complex	c;
	t_complex	z;
	int			i;

	z.real = x;
	z.imag = y;
	c.real = vars->real;
	c.imag = vars->imaginary;
	i = 0;
	while (i < vars->iterations)
	{
		if (absolute(z) >= 2)
			return (i);
		z = c_add(c_squared(z), c);
		i++;
	}
	return (0);
}
int	burning_ship(double x, double y, t_vars *vars)
{
	t_complex	c;
	t_complex	z;
	int			i;

	z.real = x;
	z.imag = y;
	c.real = vars->real;
	c.imag = vars->imaginary;
	i = 0;
	while (i < vars->iterations)
	{
		if (absolute(z) >= 2)
			return (i);
		if (z.imag < 0)
			z.imag *= -1;
		z = c_add(c_squared(z), c);
		i++;
	}
	return (0);
}