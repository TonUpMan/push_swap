GREEN =\033[32m
RESET =\033[0m

SRCS = push_swap.c \
	lst_utils.c \
	parsing.c \
	init_stack.c \

OBJS = $(SRCS:.c=.o)

NAME = Push_Swap

CC = clang

CFLAGS = -Wall -Wextra -Werror -Iincludes

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "LIBFT COMPILATION :\c"
	@${MAKE} -C ./libft >/dev/null
	@echo "$(GREEN)COMPILED$(RESET)"
	@echo "Push_Swap : \c"
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}
	@echo "$(GREEN)COMPILED$(RESET)"

%.o : %.c
	@$(CC) $(CFLAGS) -c $(SRCS) ./libft/libft.h

clean : 
	@echo "All files.o :\c" 
	@${MAKE} -C ./libft clean >/dev/null
	@rm -rf $(OBJS)
	@echo "$(GREEN)REMOVED$(RESET)"

fclean : clean
	@echo "Push_Swap & libft.a :\c"
	@${MAKE} -C ./libft fclean >/dev/null
	@rm -rf $(NAME)
	@echo "$(GREEN)REMOVED$(RESET)"

re : fclean all

PHONY. : re fclean clean all
