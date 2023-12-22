/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdeviann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:14:40 by qdeviann          #+#    #+#             */
/*   Updated: 2023/12/22 11:31:22 by qdeviann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	void			*value;
	void			*index;
    struct s_list   *prev;
	struct s_list	*next;
} t_stack;

t_stack	*ft_lstnew(void *value);
t_stack	*ft_lstlast(t_stack *lst);
t_stack *filling_stack(t_stack a, int argc, char **argv);
size_t	ft_strlen(const char *c);
char	*ft_calloc(size_t nmemb, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void    put_error(void);
int		check_if(int argc, char **argv);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_isprint(int c);

#endif
