/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:20:38 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/02 17:38:53 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_stack(t_stack **x)
{
	ft_stackclear(x);
	free(x);
}

void print_stack(t_stack *x,  int c)
{
	while (x)
	{
		ft_printf("%c=[%d]\n", c, x->value);
		x = x->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack **b;
	char	**arg;

	b = malloc(sizeof(t_stack*));
	a = malloc(sizeof(t_stack*));
	*a = NULL;
	*b = NULL;
	if (argc >= 2)
	{
		arg = ft_treat(argc, argv);
		if (!check_if(arg))
			return (0);
		init_stack_a(a, arg);
		if (a == NULL)
			return (0);
		go_sort(a, b);
		print_stack(*a, 'a');
		print_stack(*b, 'b');
	}
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
