/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_treat_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:06:38 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/18 14:33:22 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	ft_isorted(t_stack **a)
{
	t_stack		*check;
	t_stack		*head;
	int			i;

	head = *a;
	i = 1;
	while (head != NULL)
	{
		check = head->next;
		while (check != NULL)
		{
			if (head->value > check->value)
				i = 0;
			check = check->next;
		}
		head = head->next;
	}
	return (i);
}

void	init_stack_a(t_stack **a, t_stack **b, char **arg)
{
	t_stack	*new;
	int		i;
	int		check;

	i = 0;
	check = 1;
	while (arg[i])
	{
		new = ft_newstack(ft_atoi(arg[i]), i);
		if (!ft_check_over(new->value, arg[i]))
			check = 0;
		ft_add_backstack(a, new);
		if (!ft_check_double(a))
			check = 0;
		free(arg[i]);
		i++;
	}
	free(arg);
	if (check == 0)
	{
		ft_free_stacks(a, b);
		ft_putstr_fd("Error\n", 2);
		exit (0);
	}
}
