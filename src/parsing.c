/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:52:44 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/17 14:31:12 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_over(long nbr, t_stack **a, t_stack **b)
{
	if (nbr > 2147483647 || nbr < -2147483648)
	{
		ft_free_stacks(a, b);
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
}

void	ft_check_double(t_stack **a, t_stack **b)
{
	t_stack		*check;
	t_stack		*head;

	if (!*a)
		return ;
	head = *a;
	while (head != NULL)
	{
		check = head->next;
		while (check != NULL)
		{
			if (head->value == check->value)
			{
				ft_free_stacks(a, b);
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
			check = check->next;
		}
		head = head->next;
	}
}

static int	isvalid(int c)
{
	if (ft_isdigit(c))
		return (1);
	if (c == 45)
		return (1);
	if (c == 43)
		return (1);
	else
		return (0);
}

static int	check_if_digit(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == 43 || arg[i] == 45)
			count++;
		if (isvalid(arg[i]))
			i++;
		else
			return (0);
	}
	if (count > 1)
		return (0);
	return (1);
}

void	check_if(char **arg, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!check_if_digit(arg[i]))
		{
			free_tab(arg);
			ft_free_stacks(a, b);
			ft_putstr_fd("Error\n", 2);
			exit (0);
		}
		i++;
	}
	ft_trim(arg);
}
