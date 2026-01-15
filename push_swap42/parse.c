/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sal <aben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 14:38:06 by aben-sal          #+#    #+#             */
/*   Updated: 2026/01/14 19:31:03 by aben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

static int	only_spaces(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!is_space(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	*make_word(const char *s, int start, int end)
{
	int		len;
	char	*str;
	int		i;

	len = end - start;
	str = malloc(len + 1);
	i = 0;
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

static int	parse_one_arg(t_node **a, const char *s)
{
	int		i;
	int		start;
	char	*word;

	i = 0;
	while (s[i])
	{
		while (s[i] && is_space(s[i]))
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && !is_space(s[i]))
			i++;
		word = make_word(s, start, i);
		if (!word || !add_number(a, word))
		{
			free(word);
			return (0);
		}
		free(word);
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_node **a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!argv[i][0] || only_spaces(argv[i]) || !parse_one_arg(a, argv[i]))
			return (0);
		i++;
	}
	return (1);
}
