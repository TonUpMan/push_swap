/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:50:54 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/18 14:24:20 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate_a(t_stack **a)
{
	if (ft_stacksize(*a) <= 1)
		return ;
	rotate(a);
}

void	rotate_b(t_stack **b)
{
	if (ft_stacksize(*b) <= 1)
		return ;
	rotate(b);
}

void	reverse_rotate_a(t_stack **a)
{
	if (ft_stacksize(*a) <= 1)
		return ;
	reverse_rotate(a);
}

void	reverse_rotate_b(t_stack **b)
{
	if (ft_stacksize(*b) <= 1)
		return ;
	reverse_rotate(b);
}
