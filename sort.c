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

int		chr_cost(t_stack **x, int nbr)
{
	t_stack *chr;
	int		cost;

	chr = *x;
	cost = 0;
	while(chr->value != nbr)
	{
		cost++;
		chr = chr->next;
	}
	return (cost);
}

int	chr_value(t_stack **x, int value)
{
	t_stack *head;
	int		cost;
	int		save;
	int		result;

	head = *x;
	cost = 0;
	save = ft_stacksize(*x);
	while (head)
	{
		if(value < head->value)
		{
			cost = chr_cost(x, head->value);
			if(save > cost || head->value < result)
			{
				save = cost;
				result = head->value;
			}
		}
		head = head->next;
	}
	return (result);
}

void	divide_stack(t_stack **a, t_stack **b, int big, int small)
{
	int		size;
	t_stack *head;

	size = ft_stacksize(*a);
	while (size != 3)
	{
		head = *a;
		if(head->value == small || head->value == big)
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

void	sort_ten_max(t_stack **a, t_stack **b, int size)
{
	int	big;
	int	small;

	big = find_big(a);
	small = find_small(a);
	if (size == 3)
	{
		sort_three(a, big);
		return ;
	}
	if (size == 4)
	{
		sort_four(a, b);
		return ;
	}
	if (size == 5)
	{
		sort_five(a, b);
		return ;
	}
	else
	{
		divide_stack(a, b, big, small);
		sort_three(a, big);
		revsort_b(b);
		join_stack(b, a, big);
		end_sort(a, small);
	}
}
