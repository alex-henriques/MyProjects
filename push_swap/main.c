/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:46:55 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/16 15:09:53 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	push_swap(t_node **a, t_node **b)
{
	int	size;

	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size == 2)
		write_sa(a);
	if (size == 3)
		sort_3(a);
	else if (size == 5)
	{
		sort_5(a, b);
		if (!is_sorted(*a))
			sort_3(a);
		while (*b)
			pa(a, b);
	}
	else
	{
		index_stack(*a);
		radix_sort(a, b);
	}
}

/*int	main(int argc, char **argv) //ORIGINAL
{
	t_node	*a;
	t_node	*b;
	char	**arg;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (argc > 2)
	{
		arg = ft_push_swap_split(argc, argv);
		if (!arg)
			return (1);
		a = init_stack(argc - 1, &arg[1]);
		free(arg);
		if (!a)
		{
			ft_printf("Error\n");
			return (1);
		}
	}
	else
	{
		arg = ft_split(argv[1], ' ');
		if (!arg)
			return (1);
		a = init_stack(ft_spaces(argv[1]), arg);
		ft_free_split(arg);
		if (!a)
		{
			ft_printf("Error\n");
			return (1);
		}
	}
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}*/

int	process_arguments(int argc, char **argv, t_node **a)
{
	char	**arg;

	if (argc > 2)
	{
		arg = ft_push_swap_split(argc, argv);
		if (!arg)
			return (0);
		*a = init_stack(argc - 1, &arg[1]);
		free(arg);
	}
	else
	{
		arg = ft_split(argv[1], ' ');
		if (!arg)
			return (0);
		*a = init_stack(ft_spaces(argv[1]), arg);
		ft_free_split(arg);
	}
	if (!*a)
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!process_arguments(argc, argv, &a))
		return (1);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
