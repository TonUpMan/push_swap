/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:01:59 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/18 12:37:13 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_isbig(t_stack **b, t_stack **a, int big)
{
	int	save_big;

	if ((*b))
	{
		save_big = find_big(b);
		if (big == save_big)
		{
			if (chr_cost_index(b, big) > ft_stacksize(*b) / 2)
			{
				while ((*b)->index != big)
					reverse_rotate_b(b);
			}
			else
			{
				while ((*b)->index != big)
					rotate_b(b);
			}
			push_a(b, a);
			swap_a(*a);
		}
	}
}

void	join_stack(t_stack **b, t_stack **a)
{
	int	big;

	while ((*b))
	{
		big = find_big(b);
		if (chr_cost_index(b, big) > ft_stacksize(*b) / 2)
		{
			while ((*b)->index != big && (*b)->index != (big - 1))
				reverse_rotate_b(b);
		}
		else
		{
			while ((*b)->index != big && (*b)->index != (big - 1))
				rotate_b(b);
		}
		push_a(b, a);
		check_isbig(b, a, big);
	}
}

static void	short_sort(t_stack **a, t_stack **b, int size)
{
	int	big;

	big = find_big(a);
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
			join_stack(b, a);
			end_sort(a);
			return ;
		}
	}
}
