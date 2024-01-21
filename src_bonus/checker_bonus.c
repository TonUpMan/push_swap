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

static char	*ft_trim_command(char *cmd)
{
	char	*trimed;

	trimed = ft_strtrim(cmd, " \n");
	free(cmd);
	cmd = ft_substr(trimed, 0, ft_strlen(trimed));
	free(trimed);
	return (cmd);
}

void	check_command(char *cmd, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (cmd[i] == 'r' && ft_strchr("abr", cmd[i + 1]) && ft_strlen(cmd) == 2)
		return ;
	if (cmd[i] == 's' && ft_strchr("abs", cmd[i + 1]))
		return ;
	if (cmd[i] == 'p' && ft_strchr("ab", cmd[i + 1]))
		return ;
	if (cmd[i] == 'r' && cmd[i + 1] == 'r' && ft_strchr("abr", cmd[i + 2]))
		return ;
	else
	{
		ft_free_stacks(a, b);
		free(cmd);
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
}

void	do_command(t_stack **a, t_stack **b, char *cmd)
{
	int	i;

	i = 0;
	if (cmd[i] == 'r' && ft_strlen(cmd) == 2)
	{
		do_rotate(a, b, cmd);
		return ;
	}
	if (cmd[i] == 's')
	{
		do_swap(a, b, cmd);
		return ;
	}
	if (cmd[i] == 'p')
	{
		do_push(a, b, cmd);
		return ;
	}
	if (cmd[i] == 'r' && cmd[i + 1] == 'r' && ft_strlen(cmd) == 3)
	{
		do_reverse_rotate(a, b, cmd);
		return ;
	}
}

void	go_check(t_stack **a, t_stack **b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (cmd)
		{
			cmd = ft_trim_command(cmd);
			check_command(cmd, a, b);
			do_command(a, b, cmd);
			free(cmd);
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
