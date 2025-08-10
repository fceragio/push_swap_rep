/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:59:43 by federico          #+#    #+#             */
/*   Updated: 2024/08/15 03:28:42 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# define NOT_INT 3333333333
# define TRUE 1
# define FALSE 0

typedef struct s_stack_node
{
	struct s_stack_node	*previous;
	int					content;
	int					position;
	int					price;
	int					total_price;
	int					upper_half;
	struct s_stack_node	*smallest_bigger;
	struct s_stack_node	*next;
}					t_stack_node;

void			free_all(char **result, int i);
long long		ch_num(char	*text);
int				check_bad_arg(char **args, int argc);
char			**split(char *str, int *argc);
t_stack_node	*find_last(t_stack_node *top);
void			free_stack(t_stack_node *top);
void			create_append_node(t_stack_node **a, char *arg);
int				stack_is_ordered(t_stack_node *top);
int				stack_size(t_stack_node *top);
void			swap_a(t_stack_node **top_a, int print);
void			swap_b(t_stack_node **top_b, int print);
void			swap_both(t_stack_node **top_a, t_stack_node **top_b);
void			push_a(t_stack_node **top_a, t_stack_node **top_b);
void			push_b(t_stack_node **top_a, t_stack_node **top_b);
void			rotate_a(t_stack_node **top_a, int print);
void			rotate_b(t_stack_node **top_b, int print);
void			rotate_both(t_stack_node **top_a, t_stack_node **top_b);
void			reverse_rotate_a(t_stack_node **top_a, int print);
void			reverse_rotate_b(t_stack_node **top_b, int print);
void			reverse_rotate_both(t_stack_node **top_a, t_stack_node **top_b);
void			create_and_sort_stacks(t_stack_node **a, t_stack_node **b,
					char **argv, int argc);
void			sort(t_stack_node **a, t_stack_node **b);
void			sort_2nodes(t_stack_node **a);
void			sort_3nodes(t_stack_node **a);
void			push_excess(t_stack_node **a, t_stack_node **b);
void			assign_positions(t_stack_node **a, t_stack_node **b);
void			assign_pushing_prices(t_stack_node **a, t_stack_node **b);
void			sort_more_nodes_2(t_stack_node **a, t_stack_node **b);
void			assign_smallest_bigger(t_stack_node **a, t_stack_node **b);
void			stacks_refresh(t_stack_node **a, t_stack_node **b);
void			assign_total(t_stack_node **b);
void			assign_pushing_single_price(t_stack_node **top);
void			assign_single_positions(t_stack_node **top);
t_stack_node	*find_cheapest(t_stack_node **b);
t_stack_node	*find_ultimate_smallest(t_stack_node *a);
void			shortening_sort_2(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest);
void			shortening_pushingsingle(t_stack_node **top,
					t_stack_node *temp, int *i);
// void			print_stack(t_stack_node *top);

#endif