NAME = so_long

CC = CC

CFLAGS = #-Wall -Wextra -Werror

RM = rm -f

SRC = get/get_next_line.c \
		get/get_next_line_utils.c \
		parsing/parsing_utils.c \
		parsing/parsing.c \
		parsing/reading.c \
		so_long.c \
		parsing/check_path.c \
		mlx_commands.c \
		move_player.c \
		parsing/utils.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c so_long.h
		$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
