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
