/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:31:33 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/22 11:31:35 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	i;
	size_t	len_m;

	if (!s)
		return (0);
	len_m = ft_strlen(s) - start;
	if (len_m >= len)
		len_m = len;
	if (start > ft_strlen(s))
		len_m = 0;
	news = malloc((len_m + 1) * sizeof(char));
	if (news == NULL)
		return (NULL);
	i = 0;
	while (i < len_m)
	{
		news[i] = s[start];
		i++;
		start++;
	}
	news[i] = '\0';
	return (news);
}

static int	count_word(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s[0] != c && s[0] != '\0')
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && (s[i + 1] != c) && (s[i + 1] != '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

static char	**filling_tab(char const *s, char **tab, char c)
{
	int	i;
	int	y;

	y = 0;
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			while (s[i] != c && s[i] != '\0')
				i++;
			tab[y] = ft_substr(s, 0, i);
			if (!tab[y])
			{
				free_split(tab);
				break ;
			}
			s = (s + i);
			y++;
		}
		else
			s++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (0);
	tab = ft_calloc(((count_word(s, c)) + 1), sizeof(char *));
	if (tab == NULL)
		return (NULL);
	filling_tab(s, tab, c);
	return (tab);
}
