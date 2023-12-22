/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:52:44 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/19 09:53:11 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    put_error(void)
{
    write(2, "error\n", 6);
}

static int check_if_digit(argv)
{
    int i;

    i = 0;
    while (argv[i] != '\0')
    {
        if (argv[i] < 48 && argv[i] > 57)
            return (0);
        i++;
    }
    return (1);
}

static int check_if_double(int argc, char **argv)
{
    int i;
    int j;
    int k;

    i = (argc - 1);
    j = 1;
    k = 2;
    while (k < i)
    {
        if (argv[k] == argv[j])
            return (0);
        j++;
        k++;
    }

}
int    check_if(int argc, char **argv)
{
    int i;
    int check;

    i = (argc - 1);
    check = 1;
    while (i > 1)
    {
        check = check_if_digit(argv[i]);
        if (check == 0)
        {
            put_error;
            return (0);
        }
        i--;
    }
    check = check_if_double(argc, argv);
    if (check == 0)
    {
        put_error;
        return (0);
    }
    return (1);
}