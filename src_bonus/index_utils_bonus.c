/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:37:29 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/18 14:28:22 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	chr_cost_index(t_stack **x, int index)
{
	t_stack		*chr;
	int			cost;

	chr = *x;
	cost = 0;
	while (chr->index != index)
	{
		cost++;
		chr = chr->next;
	}
	return (cost);
}

int	chr_next_index(t_stack **x, int index)
{
	t_stack		*head;
	int			cost;
	int			save;
	int			result;

	head = *x;
	cost = 0;
	save = ft_stacksize(*x);
	result = 0;
	while (head)
	{
		if (index < head->index)
		{
			cost = chr_cost_index(x, head->index);
			if (save > cost || head->index < result)
			{
				save = cost;
				result = head->index;
			}
		}
		head = head->next;
	}
	return (result);
}

void	index_sort(t_stack **a, int size)
{
	t_stack		*head;
	int			next;
	int			i;

	i = 0;
	next = find_small(a);
	while (i < size)
	{
		head = *a;
		next = chr_next_value(a, next);
		while (head->value != next)
			head = head->next;
		head->index = i;
		next++;
		i++;
	}
}
