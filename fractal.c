/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:35:49 by mresch            #+#    #+#             */
/*   Updated: 2023/12/01 17:15:05 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	setup(t_vars *vars, t_data *img)
{
	static int	first = 0;

	vars->x_min = -2;
	vars->x_max = 2;
	vars->y_min = -2 * (double)HEIGHT / (double)WIDTH;
	vars->y_max = 2 * (double)HEIGHT / (double)WIDTH;
	if (!first)
	{
		vars->data = img;
		vars->mlx = mlx_init();
		vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Fractal");
		img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
		img->addr = mlx_get_data_addr(img->img, \
		&img->bits_per_pixel, &img->line_length, &img->endian);
	}
	vars->mode = 0;
	vars->explore = 0;
	vars->imaginary = 0.66;
	vars->real = -0.1;
	vars->color = 0;
	vars->iterations = 64;
	first++;
	return (0);
}

int	render_img(t_data *img, int (*mode)(), t_vars *vars)
{
	int		iter;
	int		maxiter;
	int		x;
	int		y;

	x = -1;
	maxiter = 0;
	while (x++ < img->line_length / 4)
	{
		y = -1;
		while (y++ < HEIGHT)
		{
			iter = mode(map((t_map){x, 0, WIDTH, vars->x_min, vars->x_max}), \
			map((t_map){y, 0, HEIGHT, vars->y_min, vars->y_max}), vars);
			if (iter > maxiter)
				maxiter = iter;
			if (!iter)
				put_pixel(img, x, y, create_trgb(255, 0, 0, 0));
			else
				color_pixel(x, y, iter, vars);
		}
	}
	vars->prev_max_it = maxiter;
	return (0);
}

int	render_frame(t_vars *vars)
{
	int	(*func)();

	if (vars->mode == 1)
		func = julia;
	else if (vars->mode == 2)
		func = burning_ship;
	else
		func = mandelbrot;
	if (vars->win)
		render_img(vars->data, func, vars);
	if (vars->win)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;

	setup(&vars, &img);
	if (get_input(ac, av, &vars))
	{
		mlx_destroy_window(vars.mlx, vars.win);
		vars.mlx = NULL;
		vars.win = NULL;
		return (1);
	}
	if (!mlx_hook(vars.win, 2, 1L << 0, close_win, &vars) || \
		!mlx_hook(vars.win, 17, 1L << 0, close_win_button, &vars))
		return (ft_printf("terminated\n"));
	mlx_hook(vars.win, 6, 1L << 6, change_c, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
