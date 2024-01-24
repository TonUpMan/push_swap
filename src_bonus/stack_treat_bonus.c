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

long int	ft_atol(const char *nptr)
{
	long int	tmp;
	int			i;
	int			n;

	i = 0;
	tmp = 0;
	n = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	while (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			n = -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		tmp = tmp * 10 + (nptr[i] - '0');
		i++;
	}
	if (n == -1)
		tmp *= n;
	return (tmp);
}

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
	t_stack		*new;
	int			i;
	long int	nbr;

	i = 0;
	while (arg[i])
	{
		nbr = ft_atol(arg[i]);
		ft_check_over(nbr, arg, a, b);
		new = ft_newstack((int)nbr, i);
		ft_add_backstack(a, new);
		ft_check_double(a, b, arg);
		i++;
	}
	free_tab(arg);
}
