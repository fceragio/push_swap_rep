/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:33:04 by federico          #+#    #+#             */
/*   Updated: 2024/08/17 18:41:09 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*find_biggest_for3nodes(t_stack_node **a)
{
	t_stack_node	*temp;

	temp = *a;
	if (temp->content > temp->next->content)
	{
		if (temp->content > temp->next->next->content)
			return (temp);
		return (temp->next->next);
	}
	if (temp->next->content > temp->next->next->content)
		return (temp->next);
	return (temp->next->next);
}

void	sort_2nodes(t_stack_node **a)
{
	if ((*a)->content > (*a)->next->content)
		swap_a(a, TRUE);
	return ;
}

void	sort_3nodes(t_stack_node **a)
{
	t_stack_node	*biggest_of_3;

	if (!stack_is_ordered(*a))
	{
		biggest_of_3 = find_biggest_for3nodes(a);
		if (biggest_of_3 == *a)
			rotate_a(a, TRUE);
		else if (biggest_of_3 == (*a)->next)
			reverse_rotate_a(a, TRUE);
		if ((*a)->content > (*a)->next->content)
			swap_a(a, TRUE);
		return ;
	}
}

void	shortening_sort_2(t_stack_node **a, t_stack_node **b,
			t_stack_node *cheapest)
{
	if (*a != cheapest->smallest_bigger && *b != cheapest
		&& cheapest->upper_half && cheapest->smallest_bigger->upper_half)
		rotate_both(a, b);
	else if (*a != cheapest->smallest_bigger && *b != cheapest
		&& !cheapest->upper_half && !cheapest->smallest_bigger->upper_half)
		reverse_rotate_both(a, b);
	else if (*a != cheapest->smallest_bigger
		&& cheapest->smallest_bigger->upper_half)
		rotate_a(a, TRUE);
	else if (*a != cheapest->smallest_bigger
		&& !cheapest->smallest_bigger->upper_half)
		reverse_rotate_a(a, TRUE);
	else if (*b != cheapest && cheapest->upper_half)
		rotate_b(b, TRUE);
	else if (*b != cheapest && !cheapest->upper_half)
		reverse_rotate_b(b, TRUE);
	else if (*a == cheapest->smallest_bigger && *b == cheapest)
	{
		push_a(a, b);
	}
}

void	shortening_pushingsingle(t_stack_node **top, t_stack_node *temp, int *i)
{
	if (*top && (*top) == find_last(temp))
		(*i) = 1;
	else if (*top && (*top)->position <= stack_size(temp) / 2)
		(*i)++;
	else if (*top && !(stack_size(*top) % 2)
		&& (*top)->position > stack_size(temp) / 2)
		(*i)--;
	else if (*top && (stack_size(*top) % 2)
		&& (*top)->position > ((stack_size(temp) / 2) + 1))
		(*i)--;
}
