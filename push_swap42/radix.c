/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sal <aben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 13:12:16 by aben-sal          #+#    #+#             */
/*   Updated: 2026/01/14 18:25:34 by aben-sal         ###   ########.fr       */
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
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
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
	int		size;
	int		*arr;
	t_node	*tmp;

	size = stack_size(a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		error_exit(&a, NULL);
	fill_array(a, arr, size);
	simple_sort(arr, size);
	tmp = a;
	while (tmp)
	{
		tmp->index = find_index(arr, size, tmp->value);
		tmp = tmp->next;
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
