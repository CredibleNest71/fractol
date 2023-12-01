/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooksundso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:22:49 by mresch            #+#    #+#             */
/*   Updated: 2023/12/01 17:26:36 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	double	range;
	int		mode;

	mode = 0;
	if (keycode == 3)
		vars->mode = (vars->mode + 1) % 3;
	if (keycode == 2)
		vars->color = (vars->color + 1) % 3;
	if (keycode == 1)
		vars->explore = !(vars->explore);
	if (keycode == 5)
		mode = -1;
	else if (keycode == 4)
		mode = 1;
	range = vars->x_max - vars->x_min;
	vars->x_min += (range / 20 * mode) * ((double)x / WIDTH);
	vars->x_max -= (range / 20 * mode) * ((double)1 - ((double)x / WIDTH));
	range = vars->y_max - vars->y_min;
	vars->y_min += (range / 20 * mode) * ((double)y / HEIGHT);
	vars->y_max -= (range / 20 * mode) * ((double)1 - ((double)y / HEIGHT));
	return (0);
}

int	close_win_button(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->data->img);
	vars->mlx = 0;
	vars->win = 0;
	return (0);
}

static int	key_move(t_vars *vars, int keycode)
{
	double		*min;
	double		*max;
	int			direction;

	direction = 1;
	min = &vars->x_min;
	max = &vars->x_max;
	if (keycode == 65362 || keycode == 65364)
	{
		min = &vars->y_min;
		max = &vars->y_max;
	}
	if (keycode == 65363 || keycode == 65364)
		direction = -1;
	*min += ((*max - *min) / 20) * direction;
	*max += ((*max - *min) / 20) * direction;
	return (1);
}

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 65438)
		setup(vars, vars->data);
	else if (keycode == 65307)
		return (close_win_button(vars));
	else if (keycode == 65451)
		vars->iterations += 32;
	else if (keycode == 65453)
		vars->iterations -= 32;
	else
		key_move(vars, keycode);
	return (0);
}

int	change_c(int x, int y, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (vars->explore)
	{
		vars->imaginary = map((t_map){y, 0, HEIGHT, -2, 2});
		vars->real = map((t_map){x, 0, WIDTH, -2, 2});
	}
	return (1);
}
