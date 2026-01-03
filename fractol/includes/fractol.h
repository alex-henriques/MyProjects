/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:21:39 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/16 11:50:33 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "libft/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 256
# define ZOOM_FACTOR 1.1

# define KEY_ESC		65307
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_DOWN		65364
# define KEY_UP			65362
# define KEY_PLUS		65451
# define KEY_MINUS		65453
# define SCROLL_UP		5
# define SCROLL_DOWN	4
# define KEY_C			99
# define KEY_M			109
# define KEY_E			101
# define KEY_Q			113

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		type;
	int		mouse_tracking;
	int		colour;
	int		nbr_iter;
	double	zoom;
	double	offset_x;
	double	offset_y;
	double	julia_re;
	double	julia_im;
	double	colour_shift;
}	t_fractal;

//complex number operations

t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_square(t_complex a);
double		complex_abs(t_complex a);

//fractal sets

int			mandelbrot(t_complex c, int max_iters);
int			julia(t_complex z, t_complex c, int max_iters);
int			burning_ship(t_complex c, int max_iters);

//rendering

void		ft_calculate_draw_pixel(t_fractal *f, int x, int y);
void		render_fractal(t_fractal *f);
void		put_pixel(t_fractal *f, int x, int y, int colour);
int			ft_calculate_rbg(double t, int colour_scheme);
int			get_colour(int iterations, int max_iters, int colour_scheme);

// events

int			key_press(int keycode, t_fractal *f);
int			handle_mouse_tracking(t_fractal *f);
int			mouse_press(int button, int x, int y, t_fractal *f);
int			mouse_move(int x, int y, t_fractal *f);
int			close_window(t_fractal *f);

// initialisation

void		init_fractal(t_fractal *f, int type);
void		parse_args(t_fractal *f, int ac, char **av);

//main (fractol.c)

int			main(int ac, char **av);

//utils

//int			ft_strcmp(char *s1, char *s2);
double		ft_fabs(double x);
//double		ft_atof(const char *str);
double		ft_atof_ptr(const char *str);
double		ft_atof_fraction(const char *str, int *i);

#endif
