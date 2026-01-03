/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:52:54 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/13 13:53:16 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

int	main(int ac, char **av)
{
	t_fractal	f;

	if (ac < 2)
	{
		ft_printf("Usage: ./fractol <fractal_type>\n");
		ft_printf("Available fractals:\n");
		ft_printf("1 - Mandelbrot\n");
		ft_printf("2 - Julia\n");
		ft_printf("3 - Burning Ship\n");
		return (1);
	}
	parse_args(&f, ac, av);
	init_fractal(&f, f.type);
	render_fractal(&f);
	mlx_hook(f.win, 2, 1L << 0, key_press, &f);
	mlx_hook(f.win, 4, 1L << 2, mouse_press, &f);
	mlx_hook(f.win, 6, 1L << 6, mouse_move, &f);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_loop(f.mlx);
	return (0);
}
