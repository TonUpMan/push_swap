/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butter_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:42:32 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/17 14:24:01 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_range(int size)
{
	int	size_range;

	if (size <= 200)
		size_range = size / 4;
	else
		size_range = size / 9;
	return (size_range);
}

static void	push_value(t_stack **a, t_stack **b, int range, int median)
{
	int	i;

	i = 0;
	while (i < range)
	{
		if ((*a)->index <= range)
		{
			if ((*a)->index > median)
				push_b(a, b);
			else
			{
				push_b(a, b);
				rotate_b(b);
			}
			i++;
		}
		else
			rotate_a(a);
	}
}

static void	push_rest(t_stack **a, t_stack **b, int size)
{
	int	small;
	int	median;
	int	range;

	small = ft_stacksize(*b);
	range = small + size;
	median = range - (size / 2);
	push_value(a, b, range, median);
}

void	butter_sort(t_stack **a, t_stack **b, int size)
{
	int	range;
	int	median;
	int	size_range;

	range = ft_range(size);
	size_range = range;
	while (size >= size_range)
	{
		median = range - (size_range / 2);
		push_value(a, b, range, median);
		size -= size_range;
		range += size_range;
	}
	if (size != 0)
	{
		push_rest(a, b, size);
	}
}
