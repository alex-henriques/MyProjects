/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:26:16 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/13 12:34:00 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	get_min(t_node *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

void	sort_3(t_node **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		write_sa(a);
	else if (top > mid && mid > bot)
	{
		write_sa(a);
		write_rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		write_ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		write_sa(a);
		write_ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		write_rra(a);
	else if (top < mid && mid < bot)
		write_sa(a);
}

static int	find_min_position(t_node *stack)
{
	t_node	*current;
	int		min;
	int		rotations;

	min = get_min(stack);
	rotations = 0;
	current = stack;
	while (current->value != min)
	{
		current = current->next;
		rotations++;
	}
	return (rotations);
}

void	sort_5(t_node **a, t_node **b)
{
	int	rotations;

	while (stack_size(*a) > 3)
	{
		rotations = find_min_position(*a);
		if (rotations <= stack_size(*a) / 2)
		{
			while ((*a)->value != get_min(*a))
				write_ra(a);
		}
		else
		{
			while ((*a)->value != get_min(*a))
				write_rra(a);
		}
		pb(a, b);
	}
}
