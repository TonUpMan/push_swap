/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:36:23 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/10 13:36:32 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	join_stack(t_stack **b, t_stack **a, int big)
{
	int	value;
	while ((*b))
	{
		if ((*b)->value > big)
		{
			big = (*b)->value;
			push_a(b, a);
			rotate_a(a);
		}
		else
		{
			value = (chr_value(a, (*b)->value));
			if (chr_cost(a, value) > ft_stacksize(*a) / 2)
			{
				while ((*a)->value != value)
					reverse_rotate_a(a);
			}	
			else
			{
				while ((*a)->value != value)
					rotate_a(a);
			}
			push_a(b, a);
		}
	}
}

void	end_sort(t_stack **a, int small)
{
	while(!ft_isorted(a))
	{
		if (chr_cost(a, small) > ft_stacksize(*a) / 2)
			{
				while ((*a)->value != small)
					reverse_rotate_a(a);
			}	
			else
			{
				while ((*a)->value != small)
					rotate_a(a);
			}
	}
}

void	sort_three(t_stack **a, int big)
{
	t_stack *head;

	while (!ft_isorted(a))
	{
		head = *a;
		if (head->value == big)
		{
			rotate_a(a);
			continue ;
		}
		if (head->next->value == big)
		{			
			reverse_rotate_a(a);
			continue ;
		}
		if (!ft_isorted(a))
				swap_a(*a);			
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	big;
	int		small;

	push_b(a, b);
	big = find_big(a);
	sort_three(a, big);
	join_stack(b, a, big);
	small = find_small(a);
	end_sort(a, small);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int		big;
	int		small;

	push_b(a, b);
	push_b(a, b);
	big = find_big(a);
	if (!ft_isrevsorted(b))
		swap_b(*b);
	sort_three(a, big);
	join_stack(b, a, big);
	small = find_small(a);
	end_sort(a, small);
}
