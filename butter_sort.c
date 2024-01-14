/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butter.sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:42:32 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/14 14:42:34 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	butter_sort(t_stack **a, t_stack **b, int size)
{
	int	range;
	int	size_range;
	int median;
	int	i;

	if (size <= 200)
		size_range = size / 4;
	else
		size_range = size / 9;
	range = size_range;
	i = 0;
	while(size || !ft_isorted(a))
	{
		median = range / 2;
		while(i < median && size)
		{
			if((*a)->index <= median)
			{
				push_b(a, b);
				i++;
				size--;
			}
			else
			rotate_a(a);
		}
		while(i > median && size)
		{
			if((*a)->index >= median)
			{
				push_b(a, b);
				i++;
				size--;
			}
			else
			rotate_a(a);
		}
		if (size > size_range)
			range += size_range;
		else
			range += size;
	}
	join_stack(b, a);
	end_sort(a);
}
