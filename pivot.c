/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:23:12 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/06 14:23:15 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_median(t_stack **a)
{
	t_stack *tmp;
	int		median;
	int		d;

	tmp = *a;
	median = 0;
	d = 0;
	while (tmp)
	{
		median += tmp->value;
		tmp = tmp->next;
		d++;
	}
	median = median / d;
	return (median);
}

static int	ft_count_cost(int value, int median)
{
	int		i;
	int		cost;

	i = median;
	if(value < median)
	{
		while (i > value)
			i--;
		cost = median - i;
	}	
	else
	{
		while (i < value)
			i++;
		cost = i - median;
	}
	return (cost);
}

static int	ft_cost(t_stack **a, int median)
{
	t_stack	*tmp;
	int		cost;
	int		save;
	int		pivot;

	tmp = *a;
	while (tmp)
	{
		cost = ft_count_cost(tmp->value, median);
		if (cost == 0)
		{
			pivot = tmp->value;
			return (pivot);
		}
		if (tmp->prev == NULL)
			save = cost;
		if (save > cost)
			pivot = tmp->value;
		tmp = tmp->next;
	}
	return (pivot);
}

int	ft_pivot(t_stack **a)
{
	int		median;
	int		pivot;

	median = ft_median(a);
	pivot = ft_cost(a, median);
	return (pivot);
}
