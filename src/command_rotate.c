/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:50:54 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/13 16:17:11 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **a)
{
	if (ft_stacksize(*a) <= 1)
		return ;
	rotate(a);
	put_command("ra\n");
}

void	rotate_b(t_stack **b)
{
	if (ft_stacksize(*b) <= 1)
		return ;
	rotate(b);
	put_command("rb\n");
}

void	reverse_rotate_a(t_stack **a)
{
	if (ft_stacksize(*a) <= 1)
		return ;
	reverse_rotate(a);
	put_command("rra\n");
}

void	reverse_rotate_b(t_stack **b)
{
	if (ft_stacksize(*b) <= 1)
		return ;
	reverse_rotate(b);
	put_command("rrb\n");
}
