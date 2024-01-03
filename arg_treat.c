/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:39:04 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/02 17:37:03 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(char **arg, int *result)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
	free(result);
	ft_putstr_fd("error", 2);
}

static void	ft_trim_plus(char **arg, int i)
{
	char	*trimed;

	trimed = ft_strtrim(arg[i], "+");
	free(arg[i]);
	arg[i] = ft_substr(trimed, 0, ft_strlen(trimed));
	free(trimed);
}

int	*ft_convert(char **arg)
{
	int	*result;
	int	i;

	i = 0;
	while (arg[i])
		i++;
	result = ft_calloc(sizeof(int), i);
	i = 0;
	while (arg[i])
	{
		if (arg[i][0] == 43)
			ft_trim_plus(arg, i);
		result[i] = ft_atoi(arg[i]);
		if (!ft_check_over(result[i], arg[i]))
		{
			free_all(arg, result);
			return (0);
		}
		free(arg[i]);
		i++;
	}
	free(arg);
	return (result);
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

char	**ft_treat(int argc, char **argv)
{
	char	**result;
	char	*args;
	int		i;

	i = 1;
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
