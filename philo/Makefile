NAME = philo

CC = cc
RM = rm -rf
CFLAGS2 = -Wall -Wextra -Werror -Iincludes
CFLAGS  = -g

FREE_DIR = ./free
INIT_DIR = ./init
THREAD_DIR = ./thread
UTILS_DIR = ./utils
TIME_DIR = ./time

SRCS =	main.c \
		$(THREAD_DIR)/routine.c \
		$(THREAD_DIR)/routine_two.c \
		$(THREAD_DIR)/thread.c \
		$(THREAD_DIR)/lock.c \
		$(INIT_DIR)/init.c \
		$(INIT_DIR)/init_two.c \
		$(INIT_DIR)/init_three.c \
		$(FREE_DIR)/free.c \
		$(FREE_DIR)/free_two.c \
		$(UTILS_DIR)/calloc.c \
		$(UTILS_DIR)/utils.c \
		$(UTILS_DIR)/check.c \
		$(TIME_DIR)/time.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
