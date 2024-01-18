GREEN =\033[32m
RESET =\033[0m

SRC_DIR = src
SRC_BONUS_DIR = src_bonus
OBJ_DIR = obj
OBJ_BONUS_DIR = obj_bonus

SRCS := push_swap.c \
	parsing.c \
	arg_treat.c \
	stack_treat.c \
	stack_utils.c \
	command.c \
	command_stack.c \
	command_rotate.c \
	multi_command.c \
	prepare_sort.c \
	little_sort.c \
	butter_sort.c \
	index_utils.c \
	sort_utils.c \

SRCS_BONUS := push_swap_bonus.c \
	parsing_bonus.c \
	arg_treat_bonus.c \
	stack_treat_bonus.c \
	stack_utils_bonus.c \
	command_bonus.c \
	command_stack_bonus.c \
	command_rotate_bonus.c \
	multi_command_bonus.c \
	prepare_sort_bonus.c \
	little_sort_bonus.c \
	butter_sort_bonus.c \
	index_utils_bonus.c \
	sort_utils_bonus.c \
	
SRCS := $(SRCS:%.c=$(SRC_DIR)/%.c)	
SRCS_BONUS := $(SRCS_BONUS:%.c=$(SRC_BONUS_DIR)/%.c)

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS := $(SRCS_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)


NAME = push_swap
NAME_BONUS = checker

CC = clang

CFLAGS = -Wall -Wextra -Werror -I include -g

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	@echo "LIBFT COMPILATION :\c"
	@${MAKE} -C ./libft >/dev/null
	@echo "$(GREEN)COMPILED$(RESET)"
	@echo "Push_Swap : \c"
	@${CC} ${OBJS} ./libft/libft.a -o ${NAME}
	@echo "$(GREEN)COMPILED$(RESET)"
	@echo "Norm error detected : \c"
	@echo | norminette | grep "Error" | wc -l

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "LIBFT COMPILATION :\c"
	@${MAKE} -C ./libft >/dev/null
	@echo "$(GREEN)COMPILED$(RESET)"
	@echo "checker : \c"
	@${CC} ${OBJS} ./libft/libft.a -o ${NAME_BONUS}
	@echo "$(GREEN)COMPILED$(RESET)"
	@echo "Norm error detected : \c"
	@echo | norminette | grep "Error" | wc -l

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean: 
	@echo "All files.o :\c" 
	@${MAKE} -C ./libft clean >/dev/null
	@rm -rf $(OBJS) $(OBJ_DIR) $(OBJ_BONUS) $(OBJ_BONUS_DIR)
	@echo "$(GREEN)REMOVED$(RESET)"

fclean: clean
	@echo "exec :\c"
	@${MAKE} -C ./libft fclean >/dev/null
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)REMOVED$(RESET)"

re: fclean all

PHONY.: re fclean clean all
