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

int	find_small(t_stack **x)
{
	t_stack *head;
	int		small;

	head = *x;
	small =	head->value;
	while (head->next)
	{
		head = head->next;
		if (head->value < small)
			small = head->value;
	}
	return (small);
}

int	find_big(t_stack **x, int size)
{
	t_stack *head;
	int		big;

	head = *x;
	while (head)
	{
		if (head->index == (size - 1))
			big = head->index;
		head = head->next;
	}
	return (big);
}

int		chr_cost_value(t_stack **x, int nbr)
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
		if(value <= head->value)
		{
			cost = chr_cost_value(x, head->value);
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

int	sorted_value(t_stack **x, int index)
{
	t_stack	*head;

	head = *x;
	while (head->index != index)
		head = head->next;
	if (ft_stacksize(head) == 1)
		return (1);
	while (head->next)
	{
		head = head->next;
		if (index < head->index)
			return (0);
	}	
	return(1);
}