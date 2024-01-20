/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:12:14 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/20 15:13:35 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	do_swap(t_stack **a, t_stack **b, char *command)
{
	int	i;

	i = 1;
	if (command[i] == 'a')
		swap_a(*a);
	if (command[i] == 'b')
		swap_b(*b);
	if (command[i] == 's')
		swap_all(*a, *b);
	return ;
}

void	do_push(t_stack **a, t_stack **b, char *command)
{
	int	i;

	i = 1;
	if (command[i] == 'a')
		push_a(b, a);
	if (command[i] == 'b')
		push_b(a, b);
	return ;
}

void	do_rotate(t_stack **a, t_stack **b, char *command)
{
	int	i;

	i = 1;
	if (command[i] == 'a')
		rotate_a(a);
	if (command[i] == 'b')
		rotate_b(b);
	if (command[i] == 'r')
		rotate_all(a, b);
	return ;
}

void	do_reverse_rotate(t_stack **a, t_stack **b, char *command)
{
	int	i;

	i = 2;
	if (command[i] == 'a')
		reverse_rotate_a(a);
	if (command[i] == 'b')
		reverse_rotate_b(b);
	if (command[i] == 'r')
		reverse_rotate_all(a, b);
	return ;
}
