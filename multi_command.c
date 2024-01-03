/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:29:06 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/03 10:30:43 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_all(t_stack *x, t_stack *y)
{
	swap(x);
	swap(y);
	put_command("ss");
}

void	rotate_all(t_stack **x, t_stack**y)
{
	rotate(x);
	rotate(y);
	put_command("rr");
}

void	reverse_rotate_all(t_stack **x, t_stack **y)
{
	reverse_rotate(x);
	reverse_rotate(y);
	put_command("rrr");
}
