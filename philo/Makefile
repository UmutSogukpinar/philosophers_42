NAME = philo

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -Iincludes

# * Directories
OBJ_DIR	= obj
SRC_DIR	= srcs

# * Subdirectories
INIT_DIR = $(SRC_DIR)/init
DIN_DIR = $(SRC_DIR)/dining
LOCK_DIR = $(SRC_DIR)/locks
UTIL_DIR = $(SRC_DIR)/utils

SRCS =	$(SRC_DIR)/main.c			\
		$(SRC_DIR)/free.c			\
		$(DIN_DIR)/dining.c			\
		$(DIN_DIR)/eating.c			\
		$(DIN_DIR)/routine.c		\
		$(DIN_DIR)/monitor.c		\
		$(LOCK_DIR)/lock.c			\
		$(LOCK_DIR)/get_locks.c		\
		$(LOCK_DIR)/set_locks.c		\
		$(INIT_DIR)/init_table.c	\
		$(INIT_DIR)/init_philos.c	\
		$(UTIL_DIR)/checker.c		\
		$(UTIL_DIR)/display.c		\
		$(UTIL_DIR)/libft_utils.c	\
		$(UTIL_DIR)/utils.c			\
		$(UTIL_DIR)/time.c
		

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