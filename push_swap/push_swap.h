/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-sal <aben-sal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:23:28 by aben-sal          #+#    #+#             */
/*   Updated: 2026/01/14 19:40:33 by aben-sal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

/* parsing */
int					parse_args(int argc, char **argv, t_node **a);
int					add_number(t_node **a, const char *str);

/* stack build */
t_node				*new_node(int value);
void				append_node(t_node **a, t_node *new);

/* utils */
void				free_stack(t_node **a);
void				error_exit(t_node **a, t_node **b);
int					stack_size(t_node *a);
int					is_sorted(t_node *a);

/* operations (used) */
void				sa(t_node **a);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				ra(t_node **a);
void				rra(t_node **a);
void				swap(t_node **s);
void				rrotate(t_node **s);
void				rotate(t_node **s);
/* small sorts */
void				sort_small(t_node **a, t_node **b);

/* radix */
void				index_stack(t_node *a);
void				radix_sort(t_node **a, t_node **b);

#endif
