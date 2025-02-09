NAME = philo

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -Iincludes

INIT_DIR   = init
THREAD_DIR = thread
UTILS_DIR  = utils
OBJ_DIR    = obj

SRCS =	main.c \
		$(INIT_DIR)/init.c \
		$(THREAD_DIR)/create.c $(THREAD_DIR)/routine.c $(THREAD_DIR)/routine_two.c \
		$(UTILS_DIR)/check.c $(UTILS_DIR)/error_free.c $(UTILS_DIR)/libft.c $(UTILS_DIR)/print.c $(UTILS_DIR)/time.c \

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)         
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re