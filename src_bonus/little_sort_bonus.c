/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:36:23 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/18 14:29:01 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	join_little_stack(t_stack **b, t_stack **a)
{
	int	next;

	while ((*b))
	{
		next = chr_next_index(a, (*b)->index);
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

void	end_sort(t_stack **a)
{
	while (!ft_isorted(a))
	{
		if (chr_cost_index(a, 0) > ft_stacksize(*a) / 2)
		{
			while ((*a)->index != 0)
				reverse_rotate_a(a);
		}
		else
		{
			while ((*a)->index != 0)
				rotate_a(a);
		}
	}
}

void	sort_three(t_stack **a, int big)
{
	t_stack		*head;

	while (!ft_isorted(a))
	{
		head = *a;
		if (head->index == big)
		{
			rotate_a(a);
			continue ;
		}
		if (head->next->index == big)
		{
			reverse_rotate_a(a);
			continue ;
		}
		if (!ft_isorted(a))
			swap_a(*a);
	}
}

void	sort_four(t_stack **a, t_stack **b, int big)
{
	while (ft_stacksize(*a) != 3)
	{
		if ((*a)->index == big)
			rotate_a(a);
		else
			push_b(a, b);
	}
	sort_three(a, big);
	join_little_stack(b, a);
	end_sort(a);
}

void	sort_five(t_stack **a, t_stack **b, int big)
{
	while (ft_stacksize(*a) != 3)
	{
		if ((*a)->index == big)
			rotate_a(a);
		else
			push_b(a, b);
	}
	if (!ft_isrevsorted(b))
		swap_b(*b);
	sort_three(a, big);
	join_little_stack(b, a);
	end_sort(a);
}
