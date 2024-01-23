/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_treat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:39:04 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/18 14:23:04 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	full_space(char *argv, t_stack **a, t_stack **b)
{
	int	len;
	int check;
	int	i;

	len = ft_strlen(argv);
	i = 0;
	check = 0;
	while (argv[i])
	{
		if (argv[i] == 32)
			check++;
		i++;
	}
	if (len == check)
	{
		ft_putstr_fd("Error\n", 2);
		ft_free_stacks(a, b);
		exit(0);
	}
}

static void	check_empty(int argc, char **argv, t_stack **a, t_stack **b)
{
	int		empty;
	int		i;

	i = 1;
	empty = 0;
	while (i <= (argc - 1))
	{
		full_space(argv[i], a, b);
		if (!argv[i][0])
			empty++;
		i++;
	}
	if (empty == argc - 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_free_stacks(a, b);
		exit(0);
	}
}

void	ft_trim(char **result)
{
	char	*trimed;
	int		i;

	i = 0;
	while (result[i])
	{
		trimed = ft_strtrim(result[i], "+");
		free(result[i]);
		result[i] = ft_substr(trimed, 0, ft_strlen(trimed));
		free(trimed);
		i++;
	}
}

static char	*ft_join(char *args, char *argv)
{
	char	*tmp;
	char	*joined;

	tmp = ft_strjoin(argv, " ");
	joined = ft_strjoin(args, tmp);
	free (args);
	free (tmp);
	return (joined);
}

char	**ft_treat(int argc, char **argv, t_stack **a, t_stack **b)
{
	char	**result;
	char	*args;
	int		i;

	i = 1;
	check_empty(argc, argv, a, b);
	args = ft_calloc(1, sizeof (char *));
	while (i <= (argc - 1))
	{
		args = ft_join(args, argv[i]);
		i++;
	}
	result = ft_split(args, ' ');
	free(args);
	return (result);
}