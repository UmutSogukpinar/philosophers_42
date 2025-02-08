NAME = philo

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -Iincludes

INIT_DIR   = init
DINNER_DIR = dinner
UTILS_DIR  = utils
TIME_DIR   = time
OBJ_DIR    = obj

SRCS =	main.c \
		$(INIT_DIR)/init.c \
		$(DINNER_DIR)/routine.c \
		$(DINNER_DIR)/beginning.c \
		$(TIME_DIR)/time.c \
		$(UTILS_DIR)/table.c \
		$(UTILS_DIR)/lock.c \
		$(UTILS_DIR)/print.c \
		$(UTILS_DIR)/check.c \
		$(UTILS_DIR)/libft.c \

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



