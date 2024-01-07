/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:01:59 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/05 10:02:26 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_divide(int pivot, t_stack **a, t_stack **b)
{
	t_stack *head;
	int		size;

	head = *a;
	size = ft_stacksize((*a));
	while (size)
	{	
		if	((*a)->value >= pivot)
		{
			push_b(a, b);
		}
		else
		{
			rotate_a(a);
		}
		size--;
	}
}

static int	ft_isorted(t_stack **a)
{
	t_stack *check;
	t_stack *head;
	int		i;

	head = *a;
	i = 1;
	while (head != NULL)
	{
		check = head->next;
		while (check != NULL)
		{
			if (head->value > check->value)
				i = 0;

			check = check->next;
		}
		head = head->next;
	}
	return (i);
}

void	go_sort(t_stack **a, t_stack **b)
{
	int		pivot;

	if (ft_isorted(a))
		return ;
	pivot = ft_pivot(a);
	ft_divide(pivot, a, b);
}
