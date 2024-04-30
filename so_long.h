/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:38:18 by abouafso          #+#    #+#             */
/*   Updated: 2024/04/30 09:05:56 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
#include "mlx.h"


# define A 0
# define S 1
# define D 2
# define W 13

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif


typedef struct s_list
{
	char	**my_map;
	char	**updated_map;
	int		e;
	int		p;
	int		c;
	int		x;
}	t_list;

typedef struct s_libx
{
	int		height;
	int		width;
	int		x;
	int		y;
	int		moves;
	char	**map;
	void	*mlx;
	void	*win;
	void	*img;
	void	*background;
	void	*player;
	void	*collectibles;
	void	*exit;
	void	*wall;
	void	*enemy;

}			t_libx;

char	*ft_itoa(int n);
int		ft_strlen(char *str);
char	*ft_strrchr(char *str, int c);
void	*ft_calloc(size_t num_elements, size_t element_size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_join_and_free(char *buffer, char *buf);
char	*read_file(int fd, char *result);
char	*copy_line(char *buffer);
char	*remove_first_line(char *buffer);
char	*get_next_line(int fd);
int		count_lines(int fd);
char	*ft_strdup(char *s1);
char	*ft_error(char *str);
void	check_file(char *str);
char	**parsing(char **av, t_list *vars, t_libx *mlx);
char	**read_map(int fd, char *av);
int		check_spaces(t_list *vars);
int		check_map_characters(t_list *vars);
int		check_invalid_characters(t_list *vars);
int		check_walls(t_list *vars);
int		countlines(t_list *vars);
int		check_sides(t_list *vars);
int		check_map_width(t_list *vars);
char	**map_copie(t_list *vars);
void	player_position(t_list *vars, int *i, int *j);
void 	ft_flood_fill(t_list *vars, int i, int j);
void 	check_path(t_list *vars);
void 	validpath_checker(t_list *vars);
int		countliness(char **map);





//mlx-------

void    initialize_mlx(t_libx   *mlx);
void    new_window(t_libx *mlx);
void    load_image(t_libx *mlx, char *filename, void **item);
void 	put_image(t_libx *mlx, int x, int y, void *image);
void	start_window(t_libx	*mlx);
void	start_map(char **map, t_libx mlx);
void	map_dimension(t_libx *mlx);
void	map_dimension(t_libx *mlx);

//hooks

int		C_count(char **map);
int 	destroy_helper(void *param);
void    move_to_right(t_libx *mlx);
void    move_to_left(t_libx *mlx);
void    move_to_up(t_libx *mlx);
void    move_to_down(t_libx *mlx);
int		start_the_game(int keycode, t_libx *mlx);
void	player_positionn(char **map, int *i, int *j);
int key_pressed(int keycode, void *param);
void close_window(void *mlx_ptr, void *win_ptr);
void	enemy_animation(int keycode, t_libx *mlx);



#endif