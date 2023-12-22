/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:31:45 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/22 11:31:48 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_isdigit(int c)
{
	if ((c < 58 && c > 47) || c == 45 || c == 43)
		return (1);
	else
		return (0);
}
int	ft_isprint(int c)
{
	if (c > 32 && c < 127)
		return (1);
	else
		return (0);
}

int ft_atoi(char *argv)
{
    int	i;
	int	tmp;
	int	n;

	i = 0;
	tmp = 0;
	n = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	while (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i + 1] == 43 || nptr[i + 1] == 45)
			return (0);
		if (nptr[i] == 45)
			n = -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		tmp = tmp * 10 + (nptr[i] - '0');
		i++;
	}
	if (n == -1)
		tmp *= n;
	return (tmp);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char				*ptr;
	unsigned long long	totall;
	unsigned int		i;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	totall = nmemb * size;
	if (totall / size != nmemb)
		return (NULL);
	ptr = malloc(totall);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < totall)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
