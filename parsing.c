/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:52:44 by qdeviann          #+#    #+#             */
/*   Updated: 2024/01/03 14:24:00 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_over(int nbr, char *str)
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

static int	isvalid(int c)
{
	if (ft_isdigit(c))
		return (1);
	if (c == 45)
		return (1);
	if (c == 43)
		return (1);
	else
		return (0);
}

static int	check_if_digit(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == 43 || arg[i] == 45)
			count++;
		if (isvalid(arg[i]))
			i++;
		else
			return (2);
	}
	if (count > 1)
		return (2);
	return (1);
}

int	check_if(char **arg)
{
	int	check;
	int	i;

	i = 0;
	while (arg[i])
	{
		check = check_if_digit(arg[i]);
		if (check == 2)
		{
			ft_putstr_fd("error", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_double(int *nbr, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < (argc - 1))
	{
		j = 0;
		while (j < (argc - 2))
		{
			if (j == i)
				j++;
			if (nbr[j] == nbr[i])
			{
				ft_putstr_fd("error", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
