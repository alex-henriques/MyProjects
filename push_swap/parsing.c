/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:51:42 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/16 15:10:06 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/*t_node	*init_stack(int argc, char **argv) // Original
{
	t_node	*a;
	long	num;
	int		i;

	a = NULL;
	i = 0;
	while (i < argc)
	{
		if (!argv[i] || !is_number(argv[i]))
		{
			free_stack(&a);
			return (NULL);
		}
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free_stack(&a);
			return (NULL);
		}
		add_node(&a, (int)num);
		i++;
	}
	if (has_duplicates(a))
	{
		free_stack(&a);
		return (NULL);
	}
	return (a);
}*/

void	add_node(t_node **stack, int value)
{
	t_node	*new;
	t_node	*temp;

	new = malloc(sizeof(t_node));
	if (!new)
		exit_error(stack);
	new->value = value;
	new->next = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

int	process_init_stack(char *arg, t_node **stack)
{
	long	num;

	if (!arg || !is_number(arg))
	{
		free_stack(stack);
		return (0);
	}
	num = ft_atol(arg);
	if (num > INT_MAX || num < INT_MIN)
	{
		free_stack(stack);
		return (0);
	}
	add_node(stack, (int)num);
	return (1);
}

t_node	*init_stack(int argc, char **argv)
{
	t_node	*a;
	int		i;

	a = NULL;
	i = 0;
	while (i < argc)
	{
		if (!process_init_stack(argv[i], &a))
			return (NULL);
		i++;
	}
	if (has_duplicates(a))
	{
		free_stack(&a);
		return (NULL);
	}
	return (a);
}
