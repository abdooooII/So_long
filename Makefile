NAME = so_long

CC = CC

FLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = get_next_line.c \
		get_next_line_utils.c \
		parsing_utils.c \
		parsing.c \
		reading.c \
		so_long.c 


OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
