/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:23:21 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/13 11:23:27 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rra(t_node **a)
{
	t_node	*prev_last;
	t_node	*last;

	if (!*a || !(*a)->next)
		return ;
	prev_last = NULL;
	last = *a;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *a;
	*a = last;
}

void	rrb(t_node **b)
{
	t_node	*prev_last;
	t_node	*last;

	if (!*b || !(*b)->next)
		return ;
	prev_last = NULL;
	last = *b;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *b;
	*b = last;
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}

void	write_rra(t_node **a)
{
	rra(a);
	ft_printf("rra\n");
}

void	write_rrb(t_node **b)
{
	rrb(b);
	ft_printf("rrb\n");
}
