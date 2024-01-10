/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 07:47:35 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/10 07:47:37 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_ten(t_stack **a, t_stack **b, int big, int middle, int small)
{
	int		size;
	t_stack *head;

	size = ft_stacksize(*a);
	while (size != 3)
	{
		head = *a;
		if(head->value == small || head->value == middle || head->value == big)
		{
			rotate_a(a);
			continue ;
		}
		else
		{
			push_b(a, b);
			size--;
		}
	}
}

static void	revsort_b(t_stack **b)
{
	t_stack *head;
	t_stack	*end;
	int		small;
	int		big;

	small = find_small(b);
	big = find_big(b);
	while (!ft_isrevsorted(b))
	{
		head = *b;
		end = ft_laststack(*b);
		if (head->value > end->value && head->value != big)
		{
			reverse_rotate_b(b);
			swap_b(*b);
			continue ;
		}
		else
		{
			rotate_b(b);
			continue ;
		}
		if (head->value < head->next->value && head->value != big)
			swap_b(*b);
	}
}

void	end_sort(t_stack **b, t_stack **a, int small, int middle)
{
	reverse_rotate_a(a);
	while ((*b)->value > middle)
		push_a(b, a);
	reverse_rotate_a(a);
	while ((*b))
		push_a(b, a);
	while((*a)->value != small)
		rotate_a(a);
}

void	sort_ten_max(t_stack **a, t_stack **b, int size)
{
	int	big;
	int	middle;
	int	small;

	big = find_big(a);
	middle = ft_pivot(a);
	small = find_small(a);
	if (size == 3)
	{
		sort_three(a, big);
		return ;
	}
	if (size <= 5)
	{
		sort_five(a, b);
		return ;
	}
	else
	{
		divide_ten(a, b, big, middle, small);
		sort_three(a, big);
		revsort_b(b);
		end_sort(b, a, small, middle);
	}
}
