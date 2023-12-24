/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:14:40 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/24 12:43:22 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

t_stack	*filling_stack(char *arg);
t_stack	*ft_lstnewstack(int value, int index);
t_stack	*ft_lstlaststack(t_stack *lst);
void	ft_lstadd_backstack(t_stack **lst, t_stack *new);
void	ft_lstadd_frontstack(t_stack **lst, t_stack *new);
char	*ft_makeone(int argc, char **argv);
int		check_if(char *arg);

#endif
