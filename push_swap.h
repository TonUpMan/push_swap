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

t_stack	*ft_newstack(int value, int index);
t_stack	*ft_laststack(t_stack *lst);
t_stack	*filling_stack(t_stack *a, char *arg);
void	ft_free_stack(t_stack **x);
void	print_stack(t_stack *x,  int c);
void	put_command(char *s);
void	go_sort(t_stack **a, t_stack **b);
void	ft_add_backstack(t_stack **lst, t_stack *new);
void	ft_add_frontstack(t_stack **lst, t_stack *new);
void	ft_stackclear(t_stack **lst);
void	swap(t_stack *x);
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	push(t_stack **x, t_stack **y);
void	push_a(t_stack **b, t_stack **a);
void	push_b(t_stack **a, t_stack **b);
void	rotate(t_stack **x);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	reverse_rotate(t_stack **x);
void	reverse_rotate_a(t_stack **a);
void	reverse_rotate_b(t_stack **b);
void	swap_all(t_stack *x, t_stack *y);
void	rotate_all(t_stack **x, t_stack**y);
void	reverse_rotate_all(t_stack **x, t_stack **y);
void	init_stack_a(t_stack **a, char **arg);
char	**ft_treat(int argc, char **argv);
int		ft_check_over(int nbr, char *str);
int		ft_check_double(t_stack **a);
int		ft_pivot(t_stack **a);
int		ft_stacksize(t_stack *lst);
int		check_if(char **arg);
int		ft_isorted(t_stack **a);
int		ft_isrevsorted(t_stack **b);
int		find_big(t_stack **x);

#endif
