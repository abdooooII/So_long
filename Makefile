NAME = so_long

CC = CC

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = get_next_line.c \
		get_next_line_utils.c \
		parsing_utils.c \
		parsing.c \
		reading.c \
		so_long.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o : %.c so_long.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
