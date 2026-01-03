/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:25:37 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/13 11:30:13 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ra(t_node **a)
{
	t_node	*last;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = *a;
	*a = (*a)->next;
	last->next->next = NULL;
}

void	rb(t_node **b)
{
	t_node	*last;

	if (!*b || !(*b)->next)
		return ;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = *b;
	*b = (*b)->next;
	last->next->next = NULL;
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

void	write_ra(t_node **a)
{
	ra(a);
	ft_printf("ra\n");
}

void	write_rb(t_node **b)
{
	rb(b);
	ft_printf("rb\n");
}
