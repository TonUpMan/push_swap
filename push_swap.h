/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:14:40 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/19 09:14:43 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	void			*value;
    struct s_list   *prev;
	struct s_list	*next;
} t_stack;

t_stack	*ft_lstnew(void *value);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);

#endif