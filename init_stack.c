/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:30:21 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/24 14:50:26 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*filling_stack(char *arg)
{
	int	i;
	int	tmp;
	t_stack	*new;
	char **splited;

	i = 0;
	tmp = 0;
	splited = ft_split(arg, ' ');
	while (splited[i])
	{

		tmp = ft_atoi(splited[i]);
		free(splited[i]);
		ft_lstadd_backstack(&new, ft_lstnewstack(&tmp, &i));
		i++;
	}
	return (new);
}
