/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:50:54 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/05 09:51:19 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **a)
{
	rotate(a);
	put_command("ra\n");
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	put_command("rb\n");
}

void	reverse_rotate_a(t_stack **a)
{
	reverse_rotate(a);
	put_command("rra\n");
}

void	reverse_rotate_b(t_stack **b)
{
	reverse_rotate(b);
	put_command("rrb\n");
}