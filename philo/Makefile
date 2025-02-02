NAME = philo

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -Iincludes

INIT_DIR = ./init
FREE_DIR = ./free
UTILS_DIR = ./utils

SRCS =	main.c \
		$(INIT_DIR)/init.c \
		$(INIT_DIR)/init_two.c \
		$(FREE_DIR)/free.c \
		$(FREE_DIR)/free_two.c \
		$(UTILS_DIR)/calloc.c \
		$(UTILS_DIR)/utils.c \
		$(UTILS_DIR)/check.c \

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
