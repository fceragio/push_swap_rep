/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:07:26 by federico          #+#    #+#             */
/*   Updated: 2024/08/15 03:30:11 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node *top)
{
	t_stack_node	*temp;

	while (top != NULL)
	{
		temp = top->next;
		free(top);
		top = temp;
	}
}

int	stack_is_ordered(t_stack_node *top)
{
	t_stack_node	*temp;

	temp = top;
	top = top->next;
	while (top)
	{
		if (temp->content < top->content)
		{
			temp = top;
			top = top->next;
		}
		else
			return (FALSE);
	}
	return (TRUE);
}

int	stack_size(t_stack_node *top)
{
	int	size;

	size = 0;
	while (top)
	{
		size++;
		top = top->next;
	}
	return (size);
}

t_stack_node	*find_last(t_stack_node *top)
{
	t_stack_node	*result;

	result = top;
	if (result == NULL)
		return (NULL);
	while (result->next)
	{
		result = result->next;
	}
	return (result);
}

void	create_append_node(t_stack_node **a, char *arg)
{
	t_stack_node	*result;
	t_stack_node	*last_node;

	result = malloc(sizeof(t_stack_node));
	if (result == NULL)
	{
		free_stack(*a);
		exit(1);
	}
	result->content = (int)ch_num(arg);
	last_node = find_last(*a);
	if (last_node == NULL)
	{
		*a = result;
		result->previous = NULL;
		result->next = NULL;
		return ;
	}
	result->previous = last_node;
	last_node->next = result;
	result->next = NULL;
	return ;
}
