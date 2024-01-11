/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:01:59 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/10 07:42:38 by qdeviann         ###   ########.fr       */
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
	int		size;

	size = ft_stacksize(*a);
	if (ft_isorted(a))
		return ;
	if (size == 2)
		rotate_a(a);	
	if (size <= 50)
	{	
			sort_ten_max(a, b, size);
	}
		//if (size <= 100)
		//{
		//	sort_hundred(a, b);
		//	continue ;
		//}
		//else
		//	sort_max(a, b);
	}
