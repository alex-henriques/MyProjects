/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:54:02 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/23 18:59:55 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

int	handle_mouse_tracking(t_fractal *f)
{
	if (f->mouse_tracking == 0)
	{
		f->mouse_tracking = 1;
		ft_printf("Mouse tracking: ON\n");
	}
	else
	{
		f->mouse_tracking = 0;
		ft_printf("Mouse tracking: OFF\n");
	}
	return (0);
}

int	mouse_press(int button, int x, int y, t_fractal *f)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP)
		f->zoom *= 1.1;
	else if (button == SCROLL_DOWN)
		f->zoom /= 1.1;
	render_fractal(f);
	return (0);
}

int	mouse_move(int x, int y, t_fractal *f)
{
	if (f->type == 2 && f->mouse_tracking)
	{
		f->julia_re = (x - WIDTH / 2.0) * 2.5 / WIDTH;
		f->julia_im = -(y - HEIGHT / 2.0) * 2.5 / HEIGHT;
		render_fractal(f);
	}
	return (0);
}

/*int	close_window(t_fractal *f) // use it in case the new one is wrong
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}*/

int	close_window(t_fractal *f)
{
	if (!f)
		return (1);
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
}
