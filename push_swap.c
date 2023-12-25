/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:20:38 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/24 14:49:43 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		tmp;
	char	*arg;
	char	**splited = NULL;
	t_stack *element;

	element = malloc(sizeof(t_stack));
	if (argc > 2)
	{
		arg = ft_makeone(argc, argv);
		if (!check_if(arg))
			return (0);
		splited = ft_prepare(arg, splited);
		i = 0;
		while(splited[i])
		{
			tmp = ft_atoi(splited[i]);
			free(splited[i]);
			ft_lstadd_backstack(&element, ft_lstnewstack(tmp, i));
			i++;
		}
		free(splited);
///////////////////////////////////////////////////////////////////////////////		
		while(i >= 1)
		{
			element = element->next;
			ft_printf("element->value = %d\nelement->index = %d\n", element->value, element->index);
			ft_printf("\n");
			i--;
		}

//////////////////////////////////////////////////////////////////////////////		
	}
	return (0);
}
