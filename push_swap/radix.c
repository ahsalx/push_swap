/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sal <aben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:12:16 by aben-sal          #+#    #+#             */
/*   Updated: 2026/01/18 14:23:51 by aben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_array(t_node *a, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = a->value;
		a = a->next;
		i++;
	}
}

static void	simple_sort(int *arr, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 0;
		}
		else
		i++;
	}
}

static int	find_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (0);
}

void	index_stack(t_node *a)
{
	int	size;
	int	*arr;

	size = stack_size(a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		error_exit(&a, NULL);
	fill_array(a, arr, size);
	simple_sort(arr, size);
	while (a)
	{
		a->index = find_index(arr, size, a->value);
		a = a->next;
	}
	free(arr);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
