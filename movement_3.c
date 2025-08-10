/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:32:21 by federico          #+#    #+#             */
/*   Updated: 2024/08/07 15:33:48 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack_node **top_a, int print)
{
	t_stack_node	*last;

	if (!top_a || !*top_a || !(*top_a)->next)
		return ;
	last = find_last(*top_a);
	last->previous->next = NULL;
	last->next = *top_a;
	last->previous = NULL;
	(*top_a)->previous = last;
	*top_a = last;
	if (print)
		write(1, "rra\n", 4);
	return ;
}

void	reverse_rotate_b(t_stack_node **top_b, int print)
{
	t_stack_node	*last;

	if (!top_b || !*top_b || !(*top_b)->next)
		return ;
	last = find_last(*top_b);
	last->previous->next = NULL;
	last->next = *top_b;
	last->previous = NULL;
	(*top_b)->previous = last;
	*top_b = last;
	if (print)
		write(1, "rrb\n", 4);
	return ;
}

void	reverse_rotate_both(t_stack_node **top_a, t_stack_node **top_b)
{
	reverse_rotate_a(top_a, FALSE);
	reverse_rotate_b(top_b, FALSE);
	write(1, "rrr\n", 4);
	return ;
}
