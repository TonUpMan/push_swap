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

static void	init_stack_a(t_stack **a, char *arg)
{
	char	**splited;
	int		tmp;
	int		i;

	splited = ft_split(arg, ' ');
	free(arg);
	i = 0;
	while (splited[i])
	{
		tmp = ft_atoi(splited[i]);
		free(splited[i]);
		ft_lstadd_backstack(a, ft_lstnewstack(tmp, i));
		i++;
	}
	free(splited);
}

int	main(int argc, char **argv)
{
	char	*arg;
	int		i;
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (argc > 2)
	{
		arg = ft_makeone(argc, argv);
		if (!check_if(arg))
			return (0);
		init_stack_a(&a, arg);	
///////////////////////////////////////////////////////////////////////////////		
		i = (argc - 1);
		while (i >= 1)
		{
			a = a->next;
			ft_printf("a->value = %d\na->index = %d\n", a->value, a->index);
			ft_printf("\n");
			i--;
		}
//////////////////////////////////////////////////////////////////////////////		
	}
	return (0);
}
