/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:20:38 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/26 10:10:32 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack_a(t_stack **a, int *nbr, int argc)
{
	int		i;

	i = 0;
	while (i <= (argc - 1))
	{
		if (i == 0)
			*a = ft_lstnewstack(nbr[i], i);
		else
			ft_lstadd_backstack(a, ft_lstnewstack(nbr[i], i));
		i++;
	}
	free(nbr);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	char	**arg;
	int		*nbr;

	if (argc > 2)
	{
		arg = ft_treat(argc, argv);
		if (!check_if(arg))
			return (0);
		nbr = ft_convert(arg);
		if (!check_double(nbr, argc))
			return (0);
		init_stack_a(&a, nbr, argc);
///////////////////////////////////////////////////////////////////////////////		
		while (a->next != NULL)
		{
			ft_printf("a->value = %d\na->index = %d\n", a->value, a->index);
			ft_printf("\n");
			a = a->next;
		}		
//////////////////////////////////////////////////////////////////////////////		
	}
	return (0);
}
