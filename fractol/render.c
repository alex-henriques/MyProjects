/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:10:33 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/23 18:57:51 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void	put_pixel(t_fractal *f, int x, int y, int colour)
{
	char	*dest;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dest = f->address + (y * f->line_length + x * (f->bits_per_pixel / 8));
		*(unsigned int *)dest = colour;
	}
}

/*int	get_colour(int iteractions, int max_iters, int colour_scheme) //ORIGINAL
{
	double	t;
	int		red;
	int		green;
	int		blue;

	if (iteractions == max_iters)
		return (0x000000);
	t = (double)iteractions / max_iters;
	t = pow(t, 0.5);
	if (colour_scheme == 0)
	{
		red = (int)(9 * (1 - t) * t * t * t * 255);
		green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	else if (colour_scheme == 1)
	{
		red = (int)(9 * (1 - t) * (1 - t) * t * 255);
		green = (int)(15 * (1 - t) * t * t * 255);
		blue = (int)(8.5 * t * t * t * 255);
	}
	else
	{
		red = (int)(9 * t * t * 255);
		green = (int)(15 * (1 - t) * t * 255);
		blue = (int)(8.5 * (1 - t) * (1 - t) * 255);
	}
	return (red << 16 | green << 8 | blue);
}*/

int	ft_calculate_rbg(double t, int colour_scheme)
{
	int	red;
	int	blue;
	int	green;

	if (colour_scheme == 0)
	{
		red = (int)(9 * (1 - t) * t * t * t * 255);
		green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	else if (colour_scheme == 1)
	{
		red = (int)(9 * (1 - t) * (1 - t) * t * 255);
		green = (int)(15 * (1 - t) * t * t * 255);
		blue = (int)(8.5 * t * t * t * 255);
	}
	else
	{
		red = (int)(9 * t * t * 255);
		green = (int)(15 * (1 - t) * t * 255);
		blue = (int)(8.5 * (1 - t) * (1 - t) * 255);
	}
	return (red << 16 | green << 8 | blue);
}

int	get_colour(int iterations, int max_iters, int colour_scheme)
{
	double	t;

	if (iterations == max_iters)
		return (0x000000);
	t = (double)iterations / max_iters;
	t = pow(t, 0.5);
	return (ft_calculate_rbg(t, colour_scheme));
}

/*void	render_fractal(t_fractal *f) //ORIGINAL
{
	t_complex	c;
	int			x;
	int			y;
	int			iter;

	mlx_clear_window(f->mlx, f->win);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = (x - WIDTH / 2.0) * 3.0 / (WIDTH * f->zoom) + f->offset_x;
			c.im = (y - HEIGHT / 2.0) * 3.0 / (HEIGHT * f->zoom) + f->offset_y;
			if (f->type == 1)
				iter = mandelbrot(c, MAX_ITER);
			else if (f->type == 2)
				iter = julia(c, (t_complex){f->julia_re, f->julia_im},
						MAX_ITER);
			else if (f->type == 3)
				iter = burning_ship(c, MAX_ITER);
			put_pixel(f, x, y, get_colour(iter, MAX_ITER, f->colour));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}*/

void	ft_calculate_draw_pixel(t_fractal *f, int x, int y)
{
	t_complex	c;
	int			iter;

	c.re = (x - WIDTH / 2.0) * 3.0 / (WIDTH * f->zoom) + f->offset_x;
	c.im = -(y - HEIGHT / 2.0) * 3.0 / (HEIGHT * f->zoom) + f->offset_y;
	if (f->type == 1)
		iter = mandelbrot(c, f->nbr_iter);
	else if (f->type == 2)
		iter = julia(c, (t_complex){f->julia_re, f->julia_im},
				f->nbr_iter);
	else if (f->type == 3)
		iter = burning_ship(c, f->nbr_iter);
	put_pixel(f, x, y, get_colour(iter, f->nbr_iter, f->colour));
}

void	render_fractal(t_fractal *f)
{
	int	x;
	int	y;

	mlx_clear_window(f->mlx, f->win);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_calculate_draw_pixel(f, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
