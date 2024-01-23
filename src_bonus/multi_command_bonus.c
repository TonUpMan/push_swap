/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_command_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:29:06 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/18 14:29:41 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_all(t_stack *x, t_stack *y)
{
	if (ft_stacksize(x) <= 1 || ft_stacksize(y) <= 1)
		return ;
	swap(x);
	swap(y);
	put_command("ss\n");
}

void	rotate_all(t_stack **x, t_stack**y)
{
	if (ft_stacksize((*x)) <= 1 || ft_stacksize((*y)) <= 1)
		return ;
	rotate(x);
	rotate(y);
	put_command("rr\n");
}

void	reverse_rotate_all(t_stack **x, t_stack **y)
{
	if (ft_stacksize((*x)) <= 1 || ft_stacksize((*y)) <= 1)
		return ;
	reverse_rotate(x);
	reverse_rotate(y);
	put_command("rrr\n");
}
