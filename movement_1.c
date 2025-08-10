/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:01:07 by federico          #+#    #+#             */
/*   Updated: 2024/08/15 03:08:32 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack_node **top_a, int print)
{
	t_stack_node	*temp_top;
	t_stack_node	*temp_sec;

	if (!top_a || !*top_a || !(*top_a)->next)
		return ;
	temp_top = *top_a;
	temp_sec = (*top_a)->next;
	if ((*top_a)->next->next)
		(*top_a)->next->next->previous = (*top_a);
	(*top_a)->previous = (*top_a)->next;
	(*top_a)->next = (*top_a)->next->next;
	*top_a = temp_sec;
	(*top_a)->previous = NULL;
	(*top_a)->next = temp_top;
	if (print)
		write(1, "sa\n", 3);
	return ;
}

void	swap_b(t_stack_node **top_b, int print)
{
	t_stack_node	*temp_top;
	t_stack_node	*temp_sec;

	if (!top_b || !*top_b || !(*top_b)->next)
		return ;
	temp_top = *top_b;
	temp_sec = (*top_b)->next;
	if ((*top_b)->next->next)
		(*top_b)->next->next->previous = (*top_b);
	(*top_b)->previous = (*top_b)->next;
	(*top_b)->next = (*top_b)->next->next;
	*top_b = temp_sec;
	(*top_b)->previous = NULL;
	(*top_b)->next = temp_top;
	if (print)
		write(1, "sb\n", 3);
	return ;
}

void	swap_both(t_stack_node **top_a, t_stack_node **top_b)
{
	swap_a(top_a, FALSE);
	swap_b(top_b, FALSE);
	write(1, "ss\n", 3);
	return ;
}

void	push_a(t_stack_node **top_a, t_stack_node **top_b)
{
	t_stack_node	*temp_b;
	t_stack_node	*temp_a;

	if (!top_b || !*top_b)
		return ;
	temp_b = *top_b;
	*top_b = (*top_b)->next;
	if (*top_b)
		(*top_b)->previous = NULL;
	if (!*top_a)
	{
		*top_a = temp_b;
		(*top_a)->previous = NULL;
		(*top_a)->next = NULL;
		write(1, "pa\n", 3);
		return ;
	}
	temp_a = *top_a;
	(*top_a)->previous = temp_b;
	*top_a = temp_b;
	(*top_a)->previous = NULL;
	(*top_a)->next = temp_a;
	write(1, "pa\n", 3);
	return ;
}

void	push_b(t_stack_node **top_a, t_stack_node **top_b)
{
	t_stack_node	*temp_a;
	t_stack_node	*temp_b;

	if (!top_a || !*top_a)
		return ;
	temp_a = *top_a;
	*top_a = (*top_a)->next;
	if (*top_a)
		(*top_a)->previous = NULL;
	if (!*top_b)
	{
		*top_b = temp_a;
		(*top_b)->previous = NULL;
		(*top_b)->next = NULL;
		write(1, "pb\n", 3);
		return ;
	}
	temp_b = *top_b;
	(*top_b)->previous = temp_a;
	*top_b = temp_a;
	(*top_b)->previous = NULL;
	(*top_b)->next = temp_b;
	write(1, "pb\n", 3);
	return ;
}
