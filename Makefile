#Makefile#

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = check_arg.c \
	main.c \
	movement_1.c \
	movement_2.c \
	movement_3.c \
	operations_1.c \
	operations_2.c \
	sorting_1.c \
	sorting_2.c \
	sorting_3.c \
	split.c

OBJS = $(SRCS:.c=.o)

COLOR_GREEN=\033[0;32m
COLOR_END=\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) created.✅$(COLOR_END)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	@echo "$(COLOR_GREEN)$(NAME) cleaned.✅$(COLOR_END)"

re: fclean all

.PHONY: all clean fclean re bonus