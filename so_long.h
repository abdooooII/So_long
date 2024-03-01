#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char	**my_map;
	int		e;
	int		p;
	int		c;
}	t_list;

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
char	**parsing(char **av, t_list *vars);
char	**read_map(int fd, char *av);
int		check_spaces(t_list *vars);
int		check_map_characters(t_list *vars);
int		check_invalid_characters(t_list *vars);
int		check_walls(t_list *vars);
int		countlines(t_list *vars);
int		check_sides(t_list *vars);
int		check_map_width(t_list *vars);

#endif