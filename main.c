/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:00:02 by federico          #+#    #+#             */
/*   Updated: 2024/08/17 00:40:46 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shortening_main(int argc, int param_argc, char **param_argv)
{
	if (check_bad_arg(param_argv, param_argc))
	{
		write(2, "Error\n", 6);
		if (argc == 2)
			free_all(param_argv, param_argc);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				param_argc;
	char			**param_argv;

	param_argc = argc;
	if (argc == 2)
	{
		param_argv = split(argv[1], &param_argc);
		if (param_argv == NULL)
			return (1);
	}
	else
		param_argv = argv;
	if (param_argc <= 1)
		return (1);
	shortening_main(argc, param_argc, param_argv);
	a = NULL;
	b = NULL;
	create_and_sort_stacks(&a, &b, param_argv, param_argc);
	if (argc == 2)
		free_all(param_argv, param_argc);
	return (0);
}

// void	print_stack(t_stack_node *top)
// {
// 	while (top)
// 	{
// 		if (top->previous && top->next)
// 			printf("%d<<< %d >>>%d\n",
// 					top->previous->content, top->content, top->next->content);
// 		else if (top->previous)
// 			printf("%d<<< %d >>>    NULL\n",
// 					top->previous->content, top->content);
// 		else if (top->next)
// 			printf("NULL    <<< %d >>>%d\n", top->content, top->next->content);
// 		else
// 			printf("NULL    <<< %d >>>     NULL\n", top->content);
// 		top = top->next;
// 	}
// }
