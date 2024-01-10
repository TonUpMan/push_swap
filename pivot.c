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

static int	ft_median(t_stack **x)
{
	t_stack *tmp;
	int		median;
	int		d;

	tmp = *x;
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
	int		cost;

	if(value < median)
		cost = median - value;
	else
		cost = value - median;
	return (cost);
}

static int	ft_cost(t_stack **x, int median)
{
	t_stack	*tmp;
	int		cost;
	int		save;
	int		pivot;

	tmp = *x;
	pivot = tmp->value;
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
		{
			pivot = tmp->value;
			save = cost;
		}
		tmp = tmp->next;
	}
	return (pivot);
}

int	ft_pivot(t_stack **x)
{
	int		median;
	int		pivot;

	median = ft_median(x);
	pivot = ft_cost(x, median);
	return (pivot);
}
