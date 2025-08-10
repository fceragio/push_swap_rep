/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 02:23:28 by federico          #+#    #+#             */
/*   Updated: 2024/08/17 18:39:23 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_and_sort_stacks(t_stack_node **a, t_stack_node **b,
		char **argv, int argc)
{
	int				i;

	i = 1;
	while (i < argc)
	{
		create_append_node(a, argv[i]);
		i++;
	}
	sort(a, b);
	free_stack(*a);
	return ;
}

void	push_excess(t_stack_node **a, t_stack_node **b)
{
	while (stack_size(*a) > 3 && !stack_is_ordered(*a))
		push_b(a, b);
	sort_3nodes(a);
	stacks_refresh(a, b);
	return ;
}

void	stacks_refresh(t_stack_node **a, t_stack_node **b)
{
	assign_positions(a, b);
	assign_pushing_prices(a, b);
	assign_smallest_bigger(a, b);
	assign_total(b);
}

void	sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;

	if (stack_size(*a) == 2)
		sort_2nodes(a);
	if (stack_size(*a) == 3)
		sort_3nodes(a);
	if (stack_size(*a) > 3)
	{
		sort_more_nodes_2(a, b);
		smallest = find_ultimate_smallest(*a);
		stacks_refresh(a, b);
		while (!stack_is_ordered(*a))
		{
			if (smallest->upper_half)
				rotate_a(a, TRUE);
			else
				reverse_rotate_a(a, TRUE);
		}
	}
}
