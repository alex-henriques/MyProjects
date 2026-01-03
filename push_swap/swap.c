/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:37:20 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/13 11:37:25 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sa(t_node **a)
{
	t_node	*temp;

	if (!*a || !(*a)->next)
		return ;
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
}

void	sb(t_node **b)
{
	t_node	*temp;

	if (!*b || !(*b)->next)
		return ;
	temp = (*b)->next;
	(*b)->next = temp->next;
	temp->next = *b;
	*b = temp;
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}

void	write_sa(t_node **a)
{
	sa(a);
	ft_printf("sa\n");
}

void	write_sb(t_node **b)
{
	sb(b);
	ft_printf("sb\n");
}
