/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:52:44 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/22 11:31:02 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    put_error(void)
{
    write(2, "error\n", 6);
}

static int  check_if_empty(char *argv)
{
    int i;
    count;

    i = 0;
    count = 0;
    while (argv[i] != '\0')
    {
        if (ft_isprint(argv[i]))
            return (1);
        i++;
    }
    return (0);
}

static int  check_if_digit(char *argv)
{
    int i;

    i = 0;
    while (argv[i] != '\0')
    {
        if (!ft_isdigit(argv[i]))
            return (2);
        if (argv[i] == 45 && argv[i + 1] == 45)
            return (2);
        if (argv[i] == 43 && argv[i + 1] == 43)
            return (2);
        if (argv[i] == 32 && argv[i + 1] == 32)
            return (2);
        i++;
    }
    return (1);
}

int check_if(int argc, char **argv)
{
    int i;
    int check;

    i = (argc - 1);
    check = 0;
    while (i > 1)
    {
        if (!check_if_empty(argv[i]))
            return (0);
        check = check_if_digit(argv[i]);
        if (check == 2)
            return (2);
        i--;
    }
    return (1);
}

