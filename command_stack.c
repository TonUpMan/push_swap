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
	swap(a);
	put_command("sa\n");
}

void	swap_b(t_stack *b)
{
	swap(b);
	put_command("sb\n");
}

void	push_a(t_stack **b, t_stack **a)
{
	push(b, a);
	put_command("pa\n");
}

void	push_b(t_stack **a, t_stack **b)
{
	push(a, b);
	put_command("pb\n");
}

