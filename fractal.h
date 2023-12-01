/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mresch <mresch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:29:38 by mresch            #+#    #+#             */
/*   Updated: 2023/12/01 17:16:15 by mresch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "printf/ft_printf.h"
# define ITERATIONS 128
# define HEIGHT	600
# define WIDTH	600

typedef struct s_map{
	double	value;
	double	frommin;
	double	frommax;
	double	tomin;
	double	tomax;
}				t_map;
typedef struct s_complex{
	double	real;
	double	imag;
}				t_complex;
typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
typedef struct s_vars{
	void	*mlx;
	void	*win;
	t_data	*data;
	int		mode;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	imaginary;
	double	real;
	int		color;
	int		prev_max_it;
	int		explore;
	int		iterations;
}			t_vars;
int		print_correct_input(void);
int		get_input(int ac, char **av, t_vars *vars);
int		setup(t_vars *vars, t_data *img);
void	put_pixel(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		close_win(int keycode, t_vars *vars);
int		mandelbrot(double a, double b, t_vars *vars);
int		julia(double x, double y, t_vars *vars);
int		burning_ship(double x, double y, t_vars *vars);
double	map(t_map map);
double	atod(char *str);
int		color_pixel(int x, int y, int iter, t_vars *vars);
int		mouse_hook(int keycode, int x, int y, t_vars *vars);
int		close_win_button(t_vars *vars);
int		close_win(int keycode, t_vars *vars);
int		change_c(int x, int y, void *param);
#endif