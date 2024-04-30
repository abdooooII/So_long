/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:38:08 by abouafso          #+#    #+#             */
/*   Updated: 2024/05/01 00:24:22 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_free(char **str)
{
	int i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	parsing(char **av,t_libx *mlx)
{
	int		fd;

	check_file(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error("file descriptor fail\n");
	mlx->map = read_map(fd, av[1]);
	if (!mlx->map)
		ft_error("error while reading the map\n");
	check_spaces(mlx);
	check_map_characters(mlx);
	check_invalid_characters(mlx);
	check_walls(mlx);
	check_sides(mlx);
	check_map_width(mlx);
	validpath_checker(mlx);
	map_dimension(mlx);
}
