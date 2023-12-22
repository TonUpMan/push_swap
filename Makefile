SRCS = push_swap.c \
	lst_utils.c \
	parsing.c \
	utils.c \

OBJS = $(SRCS:.c=.o)

NAME = ./Push_Swap

CC = clang

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)  @(cd $(libft) && $(MAKE))

%.o : %.c
	$(CC) $(CFLAGS) -c $(SRCS) -I Includes

clean : 
	rm -rf $(OBJS) @(cd $(libft) && $(MAKE) $@)

fclean : clean
	rm -rf $(NAME) @(cd $(libft) && $(MAKE) $@)

re : fclean all

PHONY. : re fclean clean all
