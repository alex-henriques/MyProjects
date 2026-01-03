/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:47:45 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/23 18:49:49 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

int	mandelbrot(t_complex c, int max_iters)
{
	t_complex	z;
	int			iter;

	z.re = 0;
	z.im = 0;
	iter = 0;
	while (iter < max_iters && (z.re * z.re + z.im * z.im) <= 4.0)
	{
		z = complex_add(complex_square(z), c);
		iter++;
	}
	return (iter);
}

int	julia(t_complex z, t_complex c, int max_iters)
{
	int		iter;
	double	smooth_iter;

	iter = 0;
	while (iter < max_iters && (z.re * z.re + z.im * z.im) <= 4.0)
	{
		z = complex_add(complex_square(z), c);
		iter++;
	}
	if (iter == max_iters)
		return (iter);
	smooth_iter = iter + 1 - log(log(z.re * z.re + z.im * z.im)) / log(2.0);
	return ((int)(smooth_iter * 256 / max_iters));
}

int	burning_ship(t_complex c, int max_iters)
{
	t_complex	z;
	int			iter;

	z.re = 0;
	z.im = 0;
	iter = 0;
	while (iter < max_iters && (z.re * z.re + z.im * z.im) <= 4.0)
	{
		z.re = ft_fabs(z.re);
		z.im = ft_fabs(z.im);
		z = complex_add(complex_square(z), c);
		iter++;
	}
	return (iter);
}
