/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:48:21 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/13 12:50:36 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return (result);
}

t_complex	complex_square(t_complex a)
{
	t_complex	result;

	result.re = a.re * a.re - a.im * a.im;
	result.im = 2 * a.re * a.im;
	return (result);
}

double	complex_abs(t_complex a)
{
	return (sqrt(a.re * a.re + a.im * a.im));
}
