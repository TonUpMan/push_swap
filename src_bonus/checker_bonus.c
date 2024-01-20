/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:11:06 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/20 15:11:55 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*ft_trim_command(char *command)
{
	char	*trimed;

	trimed = ft_strtrim(command, " \n");
	free(command);
	command = ft_substr(trimed, 0, ft_strlen(trimed));
	free(trimed);
	return (command);
}

void	check_command(char	*command)
{
	int	i;

	i = 0;
	if (command[i] == 'r' && ft_strchr("abr", command[i + 1]))
		return ;
	if (command[i] == 's' && ft_strchr("abs", command[i + 1]))
		return ;
	if (command[i] == 'p' && ft_strchr("ab", command[i + 1]))
		return ;
	if (command[i] == 'r' && command[i + 1] == 'r')
	{
		if (ft_strchr("abr", command[i + 2]))
			return ;
	}
	else
		exit(0);
}

void	do_command(t_stack **a, t_stack **b, char *command)
{
	int	i;

	i = 0;
	if (command[i] == 'r' && ft_strlen(command) == 2)
	{
		do_rotate(a, b, command);
		return ;
	}
	if (command[i] == 's')
	{
		do_swap(a, b, command);
		return ;
	}
	if (command[i] == 'p')
	{
		do_push(a, b, command);
		return ;
	}
	if (command[i] == 'r' && command[i + 1] == 'r' && ft_strlen(command) == 3)
	{
		do_reverse_rotate(a, b, command);
		return ;
	}
}

void	go_check(t_stack **a, t_stack **b)
{
	char	*command;

	if (ft_isorted(a))
	{
		ft_putstr_fd("OK\n", 1);
		exit(0);
	}
	while (1)
	{
		command = get_next_line(0);
		if (command)
		{
			command = ft_trim_command(command);
			check_command(command);
			do_command(a, b, command);
			free(command);
		}
		else
			break ;
	}
	if (ft_isorted(a) && ft_stacksize(*b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return ;
}
