/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sal <aben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:00:00 by aben-sal          #+#    #+#             */
/*   Updated: 2026/01/13 16:00:19 by aben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static long	atol_part2(const char *str, int i, long sign, int *ok)
{
	long	res;

	res = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			*ok = 0;
			return (0);
		}
		res = res * 10 + (str[i] - '0');
		if (res * sign > INT_MAX || res * sign < INT_MIN)
		{
			*ok = 0;
			return (0);
		}
		i++;
	}
	return (res * sign);
}

static long	atol_part1(const char *str, int *ok)
{
	long	sign;
	int		i;

	*ok = 1;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
	{
		*ok = 0;
		return (0);
	}
	return (atol_part2(str, i, sign, ok));
}

static int	has_duplicate(t_node *a, int value)
{
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
	return (0);
}

int	add_number(t_node **a, const char *str)
{
	long	val;
	int		ok;
	t_node	*n;

	val = atol_part1(str, &ok);
	if (!ok || has_duplicate(*a, (int)val))
		return (0);
	n = new_node((int)val);
	if (!n)
		return (0);
	append_node(a, n);
	return (1);
}
