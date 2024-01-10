/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:36:23 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/10 13:36:32 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, int big)
{
	t_stack *head;
	t_stack *end;

	while (!ft_isorted(a))
	{
		head = *a;
		end = ft_laststack(*a);
		if (head->value == big)
		{
			rotate_a(a);
			continue ;
		}
		if (head->next->value == big)
		{			
			reverse_rotate_a(a);
			continue ;
		}
		if (!ft_isorted(a))
				swap_a(*a);			
	}
}

static void	join_stack(t_stack **b, t_stack **a, int small)
{
	reverse_rotate_a(a);
	while ((*b))
		push_a(b, a);
	while((*a)->value != small)
		rotate_a(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int		big;
	int		middle;
	int		small;

	push_b(a, b);
	push_b(a, b);
	big = find_big(a);
	middle = ft_pivot(a);
	small = find_small(a);
	if (!ft_isrevsorted(b))
		swap_b(*b);
	sort_three(a, big);
	join_stack(b, a, small);

}
