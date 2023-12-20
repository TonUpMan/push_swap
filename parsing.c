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
        if ()
    }
}

static int check_if_double(argv)
{
    
}
void    check_if(int argc, char **argv)
{
    int i;

    i = (argc - 1);
    while (i > 1)
    {
        check_if_digit(argv[i]);
        i--;
    }

}