/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 01:02:02 by federico          #+#    #+#             */
/*   Updated: 2024/08/15 02:08:33 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack_node **top_a, int print)
{
	t_stack_node	*last;
	t_stack_node	*temp;

	if (!top_a || !*top_a || !(*top_a)->next)
		return ;
	last = find_last(*top_a);
	last->next = *top_a;
	temp = (*top_a)->next;
	(*top_a)->next = NULL;
	(*top_a)->previous = last;
	*top_a = temp;
	(*top_a)->previous = NULL;
	if (print)
		write(1, "ra\n", 3);
	return ;
}

void	rotate_b(t_stack_node **top_b, int print)
{
	t_stack_node	*last;
	t_stack_node	*temp;

	if (!top_b || !*top_b || !(*top_b)->next)
		return ;
	last = find_last(*top_b);
	last->next = *top_b;
	temp = (*top_b)->next;
	(*top_b)->next = NULL;
	(*top_b)->previous = last;
	*top_b = temp;
	(*top_b)->previous = NULL;
	if (print)
		write(1, "rb\n", 3);
	return ;
}

void	rotate_both(t_stack_node **top_a, t_stack_node **top_b)
{
	rotate_a(top_a, FALSE);
	rotate_b(top_b, FALSE);
	write(1, "rr\n", 3);
	return ;
}
