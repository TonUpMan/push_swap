/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grouping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:39:04 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/24 14:48:13 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_convert(char **arg)
{
	int	*result;
	int i;

	i = 0;
	while (arg[i])
		i++;
	result = ft_calloc(sizeof(int), i);
	i = 0;
	while (arg[i])
	{
		result[i] = ft_atoi(arg[i]);
		free(arg[i]);
		i++;
	}
	free(arg);
	return (result);
}

static char	*ft_addspace(char *argv)
{
	char	*spaced;

	spaced = ft_strjoin(argv, " ");
	return (spaced);
}

static char	*ft_join(char *args, char *tmp)
{
	char	*joined;

	joined = ft_strjoin(args, tmp);
	free (args);
	free (tmp);
	return (joined);
}

char	**ft_treat(int argc, char **argv)
{
	char	**result;
	char	*args;
	char	*tmp;
	int		i;

	i = 1;
	args = ft_calloc(1, sizeof (char *));
	while (i <= (argc - 1))
	{
		tmp = ft_addspace(argv[i]);
		args = ft_join(args, tmp);
		i++;
	}
	result = ft_split(args, ' ');
	free(args);
	return (result);
}
