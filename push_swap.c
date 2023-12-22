/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:20:38 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/16 09:20:43 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int check;

    check = 0;
    if (argc > 3)
    {
        check = check_if(argc, argv);
        if (check == 0)
            return (0);
    }
    return (0);
}