/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:19:29 by abouafso          #+#    #+#             */
/*   Updated: 2024/02/29 11:25:17 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef so_long
# define so_long

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <unistd.h> //open, close, read, write
#include <stdlib.h> //malloc, free, exit
#include <stdio.h> //perror
#include <string.h> //strerror
#include <stddef.h> //size_t
#include <limits.h> //int_max int_min
#include <fcntl.h> //fd

int		ft_strlen(char *str);
char	*ft_strrchr(char *str, int c);
void	*ft_calloc(size_t num_elements, size_t element_size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_join_and_free(char *buffer, char *buf);
char	*read_file(int fd, char *result);
char	*copy_line(char *buffer);
char	*remove_first_line(char *buffer);
char	*get_next_line(int fd);
int 	count_lines(int fd);
char	*ft_strdup(char *s1);
char	*ft_error(char *str);
void	check_file(char *str);
char    **parsing(int ac, char **av);
char    **read_map(int fd, char *av);
int     check_spaces(char **lines);
int     check_map_characters(char **lines);
int		check_invalid_characters(char **lines);
int		check_walls(char **lines);
int     countlines(char **lines);
int     check_sides(char **lines);
int     check_map_width(char **lines);


#endif