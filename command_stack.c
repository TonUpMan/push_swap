/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:47:58 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/05 09:48:30 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	if (ft_stacksize(a) <= 1)
		return ;
	swap(a);
	put_command("sa\n");
}

void	swap_b(t_stack *b)
{
	if (ft_stacksize(b) <= 1)
		return ;
	swap(b);
	put_command("sb\n");
}

void	push_a(t_stack **b, t_stack **a)
{
	if (ft_stacksize(*b) == 0)
		return ;
	push(b, a);
	put_command("pa\n");
}

void	push_b(t_stack **a, t_stack **b)
{
	if (ft_stacksize(*a) == 0)
		return ;
	push(a, b);
	put_command("pb\n");
}

