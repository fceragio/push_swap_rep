/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: federico <federico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:29:18 by federico          #+#    #+#             */
/*   Updated: 2024/08/14 20:08:55 by federico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(char **result, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(result[j]);
		j++;
	}
	free(result);
}

static int	count_parts(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] != 0)
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		else
		{
			result++;
			i++;
			while (str[i] && str[i] != ' ' && (str[i] < 9 || str[i] > 13))
			{
				i++;
			}
		}
	}
	if (result == 0)
		exit(1);
	return (result);
}

static int	measure_part(char *str, int *start)
{
	int	length;

	length = 0;
	while (str[*start] == ' ' || (str[*start] >= 9 && str[*start] <= 13))
		(*start)++;
	while (str[*start] && str[*start] != ' '
		&& (str[*start] < 9 || str[*start] > 13))
	{
		(*start)++;
		length++;
	}
	return (length);
}

static char	*part_by_part(char *str, int *start)
{
	int		i;
	int		length;
	char	*result;

	length = measure_part(str, start);
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (length)
	{
		result[i] = *(str + (*start) - length);
		i++;
		length--;
	}
	result[i] = '\0';
	return (result);
}

char	**split(char *str, int *argc)
{
	int		i;
	int		start;
	int		parts;
	char	**result;

	parts = (count_parts(str) + 1);
	*argc = parts;
	result = malloc(sizeof (char *) * parts);
	if (result == NULL)
		return (NULL);
	i = 1;
	start = 0;
	while (i < parts)
	{
		result[i] = part_by_part(str, &start);
		if (result[i] == NULL)
		{
			free_all(result, i);
			return (NULL);
		}
		i++;
	}
	return (result);
}
