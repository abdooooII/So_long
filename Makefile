# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 20:58:51 by abouafso          #+#    #+#              #
#    Updated: 2024/05/02 05:38:47 by abouafso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = CC

CFLAGS = -Wall -Wextra -Werror

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
	 parsing/utils.c \
	 start_window.c \
	 directions.c \
	 parsing/count_utils.c

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
