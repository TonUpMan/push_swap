/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:20:38 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/18 14:30:57 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	a = malloc(sizeof(t_stack *));
	*a = NULL;
	*b = NULL;
	if (argc >= 2)
	{
		arg = ft_treat(argc, argv);
		if (!check_if(arg, a, b))
			return (0);
		if (!init_stack_a(a, arg))
		{
			ft_free_stack(a);
			ft_free_stack(b);
			return (0);
		}
		go_sort(a, b);
	}
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
