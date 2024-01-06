/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_treat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:06:38 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/04 12:07:10 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newstack(int value, int index)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->index = index;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

static int	ft_check_over(int nbr, char *str)
{
	int		len;
	char	*tmp;

	len = ft_strlen(str);
	tmp = ft_itoa(nbr);
	if (!ft_strncmp(tmp, str, len))
	{
		free(tmp);
		return (1);
	}
	else
	{
		free(tmp);
		return (0);
	}
}
static int	ft_check_double(t_stack **a)
{
	t_stack *check;
	t_stack *head;

	if (!*a)
		return (1);
	head = *a;
	while (head != NULL)
	{
		check = head->next;
		while (check != NULL)
		{
			if (head->value == check->value)
				return (0);
			check = check->next;
		}
		head = head->next;
	}
	return (1);
}

void	init_stack_a(t_stack **a, char **arg)
{
	t_stack	*new;
	int		i;
	int		check;

	i = 0;
	check = 0;
	while (arg[i])
	{
		new = ft_newstack(ft_atoi(arg[i]), i);
		if(!ft_check_over(new->value, arg[i]))
			check = 1;
		ft_add_backstack(a, new);
		if (!ft_check_double(a))
			check = 1;
		free(arg[i]);
		i++;
	}
	free(arg);
	if (check == 1)
	{
		ft_stackclear(a);
		ft_putstr_fd("error", 2);
	}
}
