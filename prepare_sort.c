/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:01:59 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/10 07:42:38 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	join_stack(t_stack **b, t_stack **a)
{
	int	next;

	if (!(*a))
		push_first(a, b);
	while((*b))
	{
		next = chr_index(a, (*b)->index);
		if ((*a)->index == next || next == 0)
			push_a(b, a);
		else
		{
			if (chr_cost_index(a, next) > ft_stacksize(*a) / 2)
				{
					while ((*a)->index != next)
						reverse_rotate_a(a);
				}	
				else
				{
					while ((*a)->index != next)
						rotate_a(a);
				}
		}
	}
}

void	push_first(t_stack **a, t_stack **b)
{
	int big;
	int size;

	size = ft_stacksize(*b);
	big = find_big(b, size);
	while ((*b)->index != big)
		rotate_b(b);
	push_a(b, a);
}

static void	short_sort(t_stack **a, t_stack **b, int size)
{
	int	big;

	big = find_big(a, size);
	if (size == 2)
		rotate_a(a);
	else if (size == 3)
		sort_three(a, big);
	else if (size == 4)
		sort_four(a, b, big);
	else if (size == 5)
		sort_five(a, b, big);
}

void	go_sort(t_stack **a, t_stack **b)
{
	int		size;

	size = ft_stacksize(*a);
	index_sort(a, size);
	if (ft_isorted(a))
		return ;
	else
	{
		if (size <= 5)
		{
			short_sort(a, b, size);
			return ;
		}	
		else
		{
			butter_sort(a, b, size);
			return ;
		}
	}
}
