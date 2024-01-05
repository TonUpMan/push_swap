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

static void print_stack(t_stack *a, t_stack *b)
{
	while (a)
	{
		ft_printf("a=[%d]   ", a->value);
		if (b)
		{
			ft_printf("b=[%d]\n\n", b->value);
			b = b->next;
		}
		else
			ft_printf("\n");
		a = a->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	char	**arg;

	if (argc >= 2)
	{
		arg = ft_treat(argc, argv);
		if (!check_if(arg))
			return (0);
		init_stack_a(&a, arg);
		if (a == NULL)
			return (0);
		go_sort(&a, &b);
		print_stack(a, b);
	}
	return (0);
}
