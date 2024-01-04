/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_treat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:06:38 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/04 12:07:10 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(char **arg, t_stack **a)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
	ft_stackclear(a);
	ft_putstr_fd("error", 2);
}

static int	ft_check_over(int nbr, char *str)
{
	int		len;
	char	*tmp;

	len = ft_strlen(str);
	tmp = ft_itoa(nbr);
	if (!ft_strncmp(tmp, str, len))
	{
		free(tmp);
		return (1);
	}
	else
	{
		free(tmp);
		return (0);
	}
}

void	init_stack_a(t_stack **a, char **arg)
{
	t_stack	*new;
	int	i;

	i = 0;
	*a = malloc(sizeof(t_stack));
	*a = NULL;
	while (arg[i])
	{
		new = ft_lstnewstack(ft_atoi(arg[i]), i);
		if(!ft_check_over(new->value, arg[i]))
		{
			free_all(arg, a);
			return ;
		}
		ft_lstadd_backstack(a, new);
		free(arg[i]);
		i++;
	}
	free(arg);
}
