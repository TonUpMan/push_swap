/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:20:38 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/22 11:31:12 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char    *ft_join(int argc, char **argv, char *arg)
{
    int i;

    i = 1;
    while (i < (argc - 1))
    {
        arg = ft_strjoin(arg, argv[i]);
        i++;
    }
    return (arg);
}

int main(int argc, char **argv)
{
    char    *arg = NULL;
//    t_stack a;

    if (argc > 2)
    {
///////////////////////////////////////////////////////////////        
        arg = ft_join(argc, argv, arg); //join args in one
///////////////////////////////////////////////////////////////
        if (!check_if(arg))
            return (0);
        ft_printf("%s", arg);
///////////////////////////////////////////////////////////////        
//       filling_stack(t_stack a, arg);
                                    //init stack
///////////////////////////////////////////////////////////////
    }
    return (0);
}
