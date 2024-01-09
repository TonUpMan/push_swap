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

int	find_big(t_stack **x)
{
	t_stack *head;
	int		big;

	head = *x;
	big = head->value;
	while (head->next)
	{
		head = head->next;
		if (head->value > big)
			big = head->value;
	}
	return (big);
}

void	go_sort(t_stack **a, t_stack **b)
{
	int		middle;
	int		bigger;
	int		smaller;
	int		size;

	if (ft_isorted(a))
		return ;
	middle = ft_pivot(a);
	bigger = find_big(a);
	smaller = find_small(a);
	size = ft_stacksize(*a);
	ft_printf("small = %d\n middle = %d\n bigger = %d\n size = %d\n\n", smaller, middle, bigger, size);
	push_b(a, b);
}
