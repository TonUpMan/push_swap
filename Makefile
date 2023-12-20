NAME = Push_Swap

SRCS =  push_swap.c \
		lst_utils.c \

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

NAME : $(OBJS)
	ar -rcs $(OBJS) -I Includes

%.o : %.c
	$(CC) $(CFLAGS) -c $(SRCS) -I Includes

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

PHONY. : re fclean clean all
