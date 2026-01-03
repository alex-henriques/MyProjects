/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:15:12 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/16 12:00:27 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

double	ft_fabs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

/*double	ft_sqrt(double nb)
{
	double	sqrt;
	double	precision;

	if (nb <= 0.0)
		return (0.0);
	sqrt = nb / 2.0;
	precision = 0.000001;
	while (ft_fabs(sqrt * sqrt - nb) > precision)
		sqrt = (sqrt + nb / sqrt) / 2.0;
	return (sqrt);

}*/

/*double	ft_atof(const char *str) // ORIGINAL
{
	int		i;
	int		sign;
	double	res;
	double	div;
	double	frac;

	i = 0;
	sign = 1;
	res = 0.0;
	frac = 0.0;
	div = 1.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			frac = frac * 10 + (str[i++] - '0');
			div *= 10;
		}
		res += frac / div;
	}
	return (res * sign);
}*/

double	ft_atof_fraction(const char *str, int *i)
{
	double	frac;
	double	div;

	frac = 0.0;
	div = 1.0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			frac = frac * 10 + (str[*i] - '0');
			div *= 10;
			(*i)++;
		}
		return (frac / div);
	}
	return (0.0);
}

double	ft_atof_ptr(const char *str)
{
	int		i;
	int		sign;
	double	res;

	i = 0;
	sign = 1;
	res = 0.0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	res += ft_atof_fraction(str, &i);
	return (res * sign);
}

/*int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}*/
