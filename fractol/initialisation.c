/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:55:44 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/23 18:28:17 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

void	init_fractal(t_fractal *f, int type)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		exit(1);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win)
		exit(1);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		exit(1);
	f->address = mlx_get_data_addr(f->img, &f->bits_per_pixel,
			&f->line_length, &f->endian);
	f->type = type;
	f->zoom = 1.0;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
	f->colour = 0;
	f->colour_shift = 0.0;
	f->mouse_tracking = 0;
	f->nbr_iter = 10;
}

void	parse_args(t_fractal *f, int ac, char **av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0 || ft_strcmp(av[1], "1") == 0)
		f->type = 1;
	else if (ft_strcmp(av[1], "julia") == 0 || ft_strcmp (av[1], "2") == 0)
	{
		f->type = 2;
		f->julia_re = -0.7;
		f->julia_im = 0.27015;
	}
	else if (ft_strcmp(av[1], "burningship") == 0
		|| ft_strcmp (av[1], "3") == 0)
		f->type = 3;
	else
	{
		ft_printf("Invalid fractal type\n");
		exit(1);
	}
	if (ac > 2 && f->type == 2)
	{
		f->julia_re = ft_atof_ptr(av[2]);
		if (ac > 3)
			f->julia_im = ft_atof_ptr(av[3]);
		else
			f->julia_im = 0.0;
	}
}
