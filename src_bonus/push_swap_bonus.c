/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:20:38 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/20 15:14:37 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free_stacks(t_stack **x, t_stack **y)
{
	ft_free_stack(x);
	ft_free_stack(y);
}

void	ft_free_stack(t_stack **x)
{
	ft_stackclear(x);
	free(x);
}

void	free_tab(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

int	main(int argc, char **argv)
{
	t_stack		**a;
	t_stack		**b;
	char		**arg;

	b = malloc(sizeof(t_stack *));
	if (!b)
		return (0);
	a = malloc(sizeof(t_stack *));
	if (!a)
	{
		free(b);
		return (0);
	}
	*a = NULL;
	*b = NULL;
	if (argc >= 2)
	{
		arg = ft_treat(argc, argv);
		check_if(arg, a, b);
		init_stack_a(a, b, arg);
		go_check(a, b);
	}
	ft_free_stacks(a, b);
	return (0);
}
