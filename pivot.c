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
		median += tmp->index;
		tmp = tmp->next;
		d++;
	}
	median = median / d;
	return (median);
}

static int	ft_count_cost(int index, int median)
{
	int		cost;

	if(index < median)
		cost = median - index;
	else
		cost = index - median;
	return (cost);
}

static int	ft_cost(t_stack **x, int median)
{
	t_stack	*tmp;
	int		cost;
	int		save;
	int		pivot;

	tmp = *x;
	pivot = tmp->index;
	while (tmp)
	{
		cost = ft_count_cost(tmp->index, median);
		if (cost == 0)
		{
			pivot = tmp->index;
			return (pivot);
		}
		if (tmp->prev == NULL)
			save = cost;
		if (save > cost)
		{
			pivot = tmp->index;
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
