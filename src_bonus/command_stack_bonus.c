/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_stack_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:47:58 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/18 14:25:38 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_a(t_stack *a)
{
	if (ft_stacksize(a) <= 1)
		return ;
	swap(a);
}

void	swap_b(t_stack *b)
{
	if (ft_stacksize(b) <= 1)
		return ;
	swap(b);
}

void	push_a(t_stack **b, t_stack **a)
{
	if (ft_stacksize(*b) == 0)
		return ;
	push(b, a);
}

void	push_b(t_stack **a, t_stack **b)
{
	if (ft_stacksize(*a) == 0)
		return ;
	push(a, b);
}
