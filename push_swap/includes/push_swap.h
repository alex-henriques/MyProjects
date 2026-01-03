/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehenri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:34:46 by alehenri          #+#    #+#             */
/*   Updated: 2025/05/16 15:10:28 by alehenri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

// stack (operations)
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	write_sa(t_node **a);
void	write_sb(t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	write_ra(t_node **a);
void	write_rb(t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	write_rra(t_node **a);
void	write_rrb(t_node **b);

// utils
int		stack_size(t_node *stack);
int		is_sorted(t_node *a);
void	free_stack(t_node **stack);
int		ft_spaces(const char *str);
char	**ft_push_swap_split(int argc, char **argv);

//RadixSort
void	index_stack(t_node *a);
void	radix_sort(t_node **a, t_node **b);

//small sort
int		get_min(t_node *stack);
void	sort_3(t_node **a);
void	sort_5(t_node **a, t_node **b);

//error
int		is_number(char *str);
int		has_duplicates(t_node *stack);
void	exit_error(t_node **stack);

//parsing
t_node	*init_stack(int argc, char **argv);
void	add_node(t_node **stack, int value);
int		process_init_stack(char *arg, t_node **stack);

// main
void	push_swap(t_node **a, t_node **b);
int		main(int argc, char **argv);
void	ft_free_split(char **split);
int		process_arguments(int argc, char **argv, t_node **a);

#endif
