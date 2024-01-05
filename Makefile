GREEN =\033[32m
RESET =\033[0m

SRCS = push_swap.c \
	parsing.c \
	arg_treat.c \
	stack_utils.c \
	command.c \
	command_stack.c \
	command_rotate.c \
	multi_command.c \
	stack_treat.c \
	sort.c \
	
OBJS = $(SRCS:.c=.o)

NAME = Push_Swap

CC = clang

CFLAGS = -Wall -Wextra -Werror -Iincludes -g

all : $(NAME)

$(NAME) : $(OBJS)
	@echo | cat "./banners/push.txt"
	@echo "LIBFT COMPILATION :\c"
	@${MAKE} -C ./libft >/dev/null
	@echo "$(GREEN)COMPILED$(RESET)"
	@echo "Push_Swap : \c"
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}
	@echo "$(GREEN)COMPILED$(RESET)"
	@echo "Norm error detected : \c"
	@echo | norminette | grep "Error" | wc -l

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
