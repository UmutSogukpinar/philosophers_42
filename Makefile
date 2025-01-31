NAME = philo/philo

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -Iphilo/includes

PHIL_DIR = ./philo

SRCS =	$(PHIL_DIR)/main.c \
		$(PHIL_DIR)/free.c \
		$(PHIL_DIR)/init.c \
		$(PHIL_DIR)/init_two.c \
		$(PHIL_DIR)/process.c \
		$(PHIL_DIR)/mutex.c \
		$(PHIL_DIR)/utils.c \

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
