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

int	main(int argc, char **argv)
{
	t_stack	*a;
	char	**arg;

	if (argc >= 2)
	{
		arg = ft_treat(argc, argv);
		if (!check_if(arg))
			return (0);
		init_stack_a(&a, arg);
		if (a == NULL)
			return (0);
		while (a != NULL)
		{
			ft_printf("[%d]value = %d\n", a->index, a->value);
			a = a->next;
		}
	}
	return (0);
}
