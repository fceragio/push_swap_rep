/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:53:06 by federico          #+#    #+#             */
/*   Updated: 2024/08/15 02:37:29 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_smallest_bigger(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp_a;
	t_stack_node	*temp_b;
	t_stack_node	*smallest_fornow;

	temp_b = *b;
	while (*b)
	{
		temp_a = *a;
		smallest_fornow = NULL;
		while (temp_a)
		{
			if ((*b)->content < temp_a->content && !smallest_fornow)
				smallest_fornow = temp_a;
			else if ((*b)->content < temp_a->content
				&& temp_a->content < smallest_fornow->content)
				smallest_fornow = temp_a;
			temp_a = temp_a->next;
		}
		if (!smallest_fornow)
			smallest_fornow = find_ultimate_smallest(*a);
		(*b)->smallest_bigger = smallest_fornow;
		*b = (*b)->next;
	}
	*b = temp_b;
}

void	assign_total(t_stack_node **b)
{
	t_stack_node	*temp;

	temp = *b;
	while (*b)
	{
		(*b)->total_price = (*b)->price + (*b)->smallest_bigger->price;
		*b = (*b)->next;
	}
	*b = temp;
}

t_stack_node	*find_cheapest(t_stack_node **b)
{
	t_stack_node	*temp;
	t_stack_node	*cheapest;

	if (!(*b))
		return (NULL);
	temp = *b;
	cheapest = *b;
	while (*b)
	{
		if ((*b)->next && (*b)->next->total_price == cheapest->total_price)
		{
			if (cheapest->upper_half != cheapest->smallest_bigger->upper_half)
				cheapest = (*b)->next;
		}
		else if ((*b)->next && (*b)->next->total_price < cheapest->total_price)
			cheapest = (*b)->next;
		*b = (*b)->next;
	}
	*b = temp;
	return (cheapest);
}

t_stack_node	*find_ultimate_smallest(t_stack_node *a)
{
	t_stack_node	*result;
	t_stack_node	*temp;

	temp = a;
	result = temp;
	while (temp)
	{
		if (temp->next && temp->next->content < result->content)
			result = temp->next;
		temp = temp->next;
	}
	return (result);
}
