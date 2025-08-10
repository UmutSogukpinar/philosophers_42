NAME = philo

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -Iincludes

# * Directories
OBJ_DIR	= obj
SRC_DIR	= srcs

# * Subdirectories
INIT_DIR = $(SRC_DIR)/init
UTIL_DIR = $(SRC_DIR)/utils

SRCS =	$(SRC_DIR)/main_bonus.c				\
		$(SRC_DIR)/free_bonus.c				\
		$(INIT_DIR)/init_structs.c			\
		$(INIT_DIR)/sems.c					\
		$(UTIL_DIR)/checker_bonus.c			\
		$(UTIL_DIR)/display_bonus.c			\
		$(UTIL_DIR)/libft_utils_bonus.c		\
		$(UTIL_DIR)/time_bonus.c			\
		$(UTIL_DIR)/utils_bonus.c
		

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