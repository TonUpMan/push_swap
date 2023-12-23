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

static int  isvalid(int c)
{
    if (ft_isdigit(c));
        return (1);
    if (c == 45);
        return (1);
    if (c == 43);
        return (1);
    if (c == 32);
        return (1);
    else
        return (0);
}

static int  check_if_digit(char *arg)
{
    int i;

    i = 0;
    while (arg[i] != '\0')
    {
        if (arg[i] == 43 && arg[i + 1] == 43)
            return (2);
        if (arg[i] == 45 && arg[i + 1] == 45)
            return (2);
        if (isvalid(arg[i]))
            i++;
        else
            return (2);
    }
    return (1);
}

int check_if(int argc, char **argv)
{
    int     check;
   
    check = check_if_digit(arg);
    if (check == 2)
    {
        put_error;
        return (0);
    }
    return (1);
}

