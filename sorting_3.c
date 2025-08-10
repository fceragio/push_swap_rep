/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:35:40 by federico          #+#    #+#             */
/*   Updated: 2024/08/15 03:32:33 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_positions(t_stack_node **a, t_stack_node **b)
{
	assign_single_positions(a);
	assign_single_positions(b);
}

void	assign_single_positions(t_stack_node **top)
{
	t_stack_node	*temp;
	int				i;

	i = 0;
	temp = *top;
	while (*top)
	{
		(*top)->position = i;
		if (i <= (stack_size(temp) / 2))
			(*top)->upper_half = TRUE;
		else
			(*top)->upper_half = FALSE;
		i++;
		*top = (*top)->next;
	}
	*top = temp;
}

void	assign_pushing_prices(t_stack_node **a, t_stack_node **b)
{
	assign_pushing_single_price(a);
	assign_pushing_single_price(b);
}

void	assign_pushing_single_price(t_stack_node **top)
{
	t_stack_node	*temp;
	int				i;

	i = 0;
	temp = *top;
	if (*top)
	{
		(*top)->price = i;
		*top = (*top)->next;
	}
	while (*top)
	{
		shortening_pushingsingle(top, temp, &i);
		(*top)->price = i;
		*top = (*top)->next;
	}
	*top = temp;
}

void	sort_more_nodes_2(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	push_excess(a, b);
	while (*b)
	{
		cheapest = find_cheapest(b);
		while (*a != cheapest)
		{
			shortening_sort_2(a, b, cheapest);
		}
		stacks_refresh(a, b);
	}
}
