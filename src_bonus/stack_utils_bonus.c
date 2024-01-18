/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:21:59 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/18 14:34:03 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_stacksize(t_stack *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*ft_laststack(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_add_backstack(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		last = ft_laststack(*lst);
		new->prev = last;
		last->next = new;
	}
}

void	ft_add_frontstack(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	(*lst)->prev = new;
	new->next = *lst;
	new->prev = NULL;
	*lst = new;
}

void	ft_stackclear(t_stack **lst)
{
	t_stack	*ptr;

	if (!lst)
		return ;
	while ((*lst))
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
}
