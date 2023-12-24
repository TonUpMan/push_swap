/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:30:21 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/24 12:39:48 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*filling_stack(char *arg)
{
	t_stack	*new;
	char	**args;
	int		tmp;
	int		i;

	i = 0;
	tmp = 0;
	args = ft_split(arg, ' ');
	free(arg);
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		free(args[i]);
		ft_lstadd_backstack(&new, ft_lstnewstack(tmp, i));
		i++;
	}
	return (new);
}
