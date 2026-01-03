/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:01:12 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/20 17:01:21 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

static int	key_press2(int keycode, t_fractal *f)
{
	if (keycode == KEY_Q)
		f->nbr_iter += 1;
	else if (keycode == KEY_E)
		f->nbr_iter -= 1;
	return (0);
}

int	key_press(int keycode, t_fractal *f)
{
	if (keycode == KEY_ESC)
		close_window(f);
	else if (keycode == KEY_LEFT)
		f->offset_x -= 0.1 / f->zoom;
	else if (keycode == KEY_RIGHT)
		f->offset_x += 0.1 / f->zoom;
	else if (keycode == KEY_DOWN)
		f->offset_y += 0.1 / f->zoom;
	else if (keycode == KEY_UP)
		f->offset_y -= 0.1 / f->zoom;
	else if (keycode == KEY_PLUS)
		f->zoom *= 1.0 + (0.1 / f->zoom);
	else if (keycode == KEY_MINUS)
		f->zoom /= 1.0 + (0.1 / f->zoom);
	else if (keycode == KEY_C)
		f->colour = (f->colour + 1) % 5;
	else if (keycode == KEY_M)
		handle_mouse_tracking(f);
	else
		key_press2(keycode, f);
	render_fractal(f);
	return (0);
}
