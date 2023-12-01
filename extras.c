/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:12:59 by mresch            #+#    #+#             */
/*   Updated: 2023/12/01 15:19:12 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_length);
	dest = dest + x * (data->bits_per_pixel / 8);
	*(unsigned int *)dest = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double	map(t_map map)
{
	double	ret;

	ret = (map.value - map.frommin) / (map.frommax - map.frommin) * \
	(map.tomax - map.tomin) + map.tomin;
	return (ret);
}

double	atod(char *str)
{
	int		i;
	double	ret;
	int		j;
	int		sign;

	ret = 0;
	sign = 1;
	j = 1;
	i = 0;
	while (str[i] && str[i] != '.')
	{
		if (str[i] == '-')
			sign = -1;
		if ('0' <= str[i] && str[i] <= '9')
			ret = ret * 10 + (str[i] - '0');
		i++;
	}
	while (str[i++])
	{
		j *= 10;
		if ('0' <= str[i] && str[i] <= '9')
			ret = ret + ((double)(str[i] - '0')) / j;
	}
	return (ret * sign);
}

int	color_pixel(int x, int y, int iter, t_vars *vars)
{
	int	col;

	col = 0;
	if (vars->color == 1)
	{
		if (iter > vars->prev_max_it)
			iter = vars->prev_max_it;
		iter = map((t_map){pow(iter + 2, 2), 0, \
		pow(vars->prev_max_it, 2), 0, 255});
		col = create_trgb(1, iter, iter / 2, iter / 4);
	}
	else if (vars->color == 2)
	{
		iter = map((t_map){log(iter), 0, log(vars->iterations), 0, 255});
		col = create_trgb(1, iter, 0, sqrt(iter * 10));
	}
	else
		col = create_trgb(1, (iter * 50) % 255, \
		(iter * 40) % 255, (iter * 30) % 255);
	put_pixel(vars->data, x, y, col);
	return (0);
}
