/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:32:40 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/26 10:32:43 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *x, int c)
{
	int	tmp;

	tmp = x->next->value;
	x->next->value = x->value;
	x->value = tmp;
	tmp = x->next->index;
	x->next->index = x->index;
	x->index = tmp;
	ft_printf("r%c\n", c);
}

void	push(t_stack **x, t_stack **y)
{
	t_stack *tmp;

	tmp = *x;
	tmp = tmp->next;
	if (*y == NULL)
		ft_lstadd_backstack(y, *x);
	else 
		ft_lstadd_frontstack(y, *x);
	*x = tmp;
}

//void	r(t_stack **x)
//{
//	1er element -> dernier element
//	2nd element -> 1er element
//}
//void	rr(t_stack **x)
//{
//	dernier element -> 1er element
//	1er element -> 2nd element
//}