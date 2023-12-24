/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:20:38 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/24 12:37:42 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*arg;
	t_stack	*a;

	if (argc > 1)
	{
		arg = ft_makeone(argc, argv);
		if (!check_if(arg))
			return (0);
		a = filling_stack(arg);
		while (a != NULL)
		{
			ft_printf("value = %d, index = %d\n", a->value, a->index);
			a = a->next;
		}
	}
	return (0);
}
