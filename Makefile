#SRCS = push_swap.c \
	lst_utils.c \
	parsing.c \
	init_stack.c \

SRCS = main.c

OBJS = $(SRCS:.c=.o)

NAME = Push_Swap

CC = clang

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@(cd libft && $(MAKE))
	$(CC) -o $(NAME) ./libft/libft.a $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $(SRCS) -I /libft

clean : 
	@(cd libft && $(MAKE) $@)
	rm -rf $(OBJS)

fclean : clean
	@(cd libft && $(MAKE) $@)
	rm -rf $(NAME)

re : fclean all

PHONY. : re fclean clean all
