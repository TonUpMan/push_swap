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

static int stackchr(t_stack *a, t_stack **sort)
{
	t_stack *check;

	check = *sort;
	while (check)
	{
		if (check->value == a->value)
			return (0);
		check = check->next;
	}
	return (1);	
}

void	ft_divide(int pivot, t_stack **a, t_stack **b, t_stack **sort)
{
	t_stack *head;
	int		size;

	head = *a;
	size = ft_stacksize((*a));
	while (size)
	{
		if (!stackchr((*a), sort))
		{
			rotate_a(a);
		}
		if	((*a)->value > pivot)
		{
			push_b(a, b);
			size--;
		}
		else
			size--;
	}
}

static void ft_presort(int value, int index, t_stack **sort)
{
	t_stack *new;

	new = ft_newstack(value, index);
	ft_add_backstack(sort, new);
}

static int	ft_isorted(t_stack **a, t_stack **sort)
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
			{
				ft_presort(head->value, head->index, sort);
				i = 0;
			}
			check = check->next;
		}
		head = head->next;
	}
	return (i);
}

void	go_sort(t_stack **a, t_stack **b)
{
	t_stack	**sort;
	int		pivot;

	sort = malloc(sizeof(t_stack*));
	if (ft_isorted(a, sort))
	{
		free(sort);
		return ;
	}
	pivot = ft_pivot(a);
	ft_divide(pivot, a, b, sort);
}
