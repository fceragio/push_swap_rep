/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:36:03 by federico          #+#    #+#             */
/*   Updated: 2024/09/19 21:40:10 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*create_int_array(char **args, int argc)
{
	int	i;
	int	j;
	int	*result;

	i = 1;
	j = 0;
	result = (int *)malloc(sizeof(int) * (argc - 1));
	if (result == NULL)
		return (NULL);
	while (i < argc)
	{
		if (ch_num(args[i]) == NOT_INT)
		{
			free(result);
			return (NULL);
		}
		result[j] = (int)(ch_num(args[i]));
		j++;
		i++;
	}
	return (result);
}

static int	check_nondigits(char **args, int argc)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (args[i][j] == '+' || args[i][j] == '-')
		{
			j++;
			if (!args[i][j])
				return (TRUE);
		}
		while (args[i][j])
		{
			if (args[i][j] < '0' || args[i][j] > '9')
				return (TRUE);
			j++;
		}
		j = 0;
		i++;
	}
	return (FALSE);
}

static int	check_double_int(int *array, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < argc)
	{
		while ((i + j) < argc)
		{
			if (array[i] == array[i + j])
			{
				free(array);
				return (TRUE);
			}
			j++;
		}
		j = 1;
		i++;
	}
	free(array);
	return (FALSE);
}

long long	ch_num(char	*text)
{
	int			neg;
	long long	num;

	neg = FALSE;
	num = 0;
	if (*text == '-')
	{
		neg = TRUE;
		text++;
	}
	else if (*text == '+')
		text++;
	while (*text)
	{
		num = (num * 10) + (*text - '0');
		if (num > NOT_INT)
			return (NOT_INT);
		text++;
	}
	if (((neg == TRUE) && ((-num) < INT_MIN))
		|| (neg == FALSE && num > INT_MAX))
		return (NOT_INT);
	if (neg == TRUE)
		return (-num);
	return (num);
}

int	check_bad_arg(char **args, int argc)
{
	int	*nums;

	nums = NULL;
	if (check_nondigits(args, argc))
		return (TRUE);
	nums = create_int_array(args, argc);
	if (nums)
	{
		if (check_double_int(nums, (argc - 1)))
		{
			return (TRUE);
		}
		else
		{
			return (FALSE);
		}
	}
	else
	{
		return (TRUE);
	}
}
