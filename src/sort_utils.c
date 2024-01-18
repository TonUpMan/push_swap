/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 07:47:35 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/18 14:32:39 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_small(t_stack **x)
{
	t_stack		*head;
	int			small;

	head = *x;
	small = head->value;
	while (head->next)
	{
		head = head->next;
		if (head->value < small)
			small = head->value;
	}
	return (small);
}

int	find_big(t_stack **x)
{
	t_stack		*head;
	int			big;

	head = *x;
	big = head->index;
	while (head->next)
	{
		head = head->next;
		if (head->index > big)
			big = head->index;
	}
	return (big);
}

int	chr_cost_value(t_stack **x, int nbr)
{
	t_stack		*chr;
	int			cost;

	chr = *x;
	cost = 0;
	while (chr->value != nbr)
	{
		cost++;
		chr = chr->next;
	}
	return (cost);
}

int	chr_next_value(t_stack **x, int value)
{
	t_stack		*head;
	int			cost;
	int			save;
	int			result;

	head = *x;
	cost = 0;
	save = ft_stacksize(*x);
	while (head)
	{
		if (value <= head->value)
		{
			cost = chr_cost_value(x, head->value);
			if (save > cost || head->value < result)
			{
				save = cost;
				result = head->value;
			}
		}
		head = head->next;
	}
	return (result);
}
