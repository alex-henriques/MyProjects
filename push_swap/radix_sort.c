/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:07:32 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/13 11:07:43 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	index_stack(t_node *a)
{
	t_node	*ptr_i;
	t_node	*ptr_j;
	int		i;

	i = 0;
	ptr_i = a;
	while (ptr_i)
	{
		ptr_j = a;
		while (ptr_j)
		{
			if (ptr_i->value > ptr_j->value)
				i++;
			ptr_j = ptr_j->next;
		}
		ptr_i->index = i;
		ptr_i = ptr_i->next;
		i = 0;
	}
}

static int	get_maxbit(t_node **a)
{
	int	max_bits;
	int	max_num;

	max_bits = 0;
	max_num = stack_size(*a) - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	if (is_sorted(*a))
		return ;
	max_bits = get_maxbit(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = stack_size(*a);
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				write_ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
