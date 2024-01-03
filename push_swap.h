/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:14:40 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/26 10:08:49 by qdeviann         ###   ########.fr       */
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
}t_stack;

t_stack	*ft_lstnewstack(int value, int index);
t_stack	*ft_lstlaststack(t_stack *lst);
t_stack	*filling_stack(t_stack *a, char *arg);
void	ft_lstadd_backstack(t_stack **lst, t_stack *new);
void	ft_lstadd_frontstack(t_stack **lst, t_stack *new);
void	swap(t_stack *x);
void	push(t_stack **x, t_stack **y);
void	rotate(t_stack **x);
void	reverse_rotate(t_stack **x);
void	swap_all(t_stack *x, t_stack *y);
void	rotate_all(t_stack **x, t_stack**y);
void	reverse_rotate_all(t_stack **x, t_stack **y);
char	**ft_treat(int argc, char **argv);
int		check_double(int *nbr, int argc);
int		check_if(char **arg);
int		ft_check_over(int nbr, char *str);
int		*ft_convert(char **arg);

#endif
