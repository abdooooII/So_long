/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:58:27 by abouafso          #+#    #+#             */
/*   Updated: 2024/02/27 22:40:04 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **parsing(int ac, char **av)
{
    int fd;
    char **my_map;

    if (ac != 2)
        ft_error("too much arguments\n");
    check_file(av[1]);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        ft_error("file descriptor fail\n");    
   my_map = read_map(fd, av[1]);
    if(!my_map)
        ft_error("error while reading the map\n");
    
    check_spaces(my_map);
    check_map_characters(my_map);

    return (0);
    
}

// int main (int ac, char **av)
// {
// 	char **my_map;
	
// 	my_map = parsing(ac , av);
	
// }