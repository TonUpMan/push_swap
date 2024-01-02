/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:32:40 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/02 17:40:03 by qdeviann         ###   ########.fr       */
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
	ft_printf("s%c\n", c);
}

void	p(t_stack **x, t_stack **y, int c)
{
	t_stack	*tmp;

	tmp = *x;
	tmp = tmp->next;
	if (*y == NULL)
		ft_lstadd_backstack(y, *x);
	else
		ft_lstadd_frontstack(y, *x);
	*x = tmp;
	ft_printf("p%c", c);
}

void	r(t_stack **x, int c)
{
	t_stack	*tmp;
	t_stack	*head;

	head = *x;
	tmp = ft_lstlaststack(head);
	*x = head->next;
	head->next = NULL;
	tmp->next = head;
	ft_printf("r%c\n", c);
}

void	rr(t_stack **x, int c)
{
	t_stack	*tmp;
	t_stack	*head;

	head = *x;
	tmp = ft_lstlaststack(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tmp->next = *x;
	*x = tmp;
	ft_printf("rr%c\n", c);
}
