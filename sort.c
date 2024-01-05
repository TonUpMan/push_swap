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

static void ft_presort(int value, int index, t_stack **sort)
{
	t_stack *new;

	new = ft_newstack(value, index);
	ft_add_backstack(sort, new);
}

static void	ft_isorted(t_stack **a, t_stack **sort)
{
	t_stack *check;
	t_stack *head;

	head = *a;
	*sort = malloc(sizeof(t_stack));
	*sort = NULL;
	while (head != NULL)
	{
		check = head->next;
		while (check != NULL)
		{
			if (head->value > check->value)
				ft_presort(head->value, head->index, sort);
			check = check->next;
		}
		head = head->next;
	}

}

void	go_sort(t_stack **a, t_stack **b)
{
	t_stack	*sort;
	t_stack *check;

	ft_isorted(a, &sort);
	if (sort == NULL)
		return ;
	while ((*a)->next != NULL)
	{
		check = sort;
		while (check)
		{
			if ((*a)->value == check->value)
				push_b(a, b);
			check = check->next;
		}
		rotate_a(a);
	}
}
