/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:38:08 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/09 19:39:01 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	check_map_characters(t_libx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->map[++i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'C')
				mlx->cc++;
			else if (mlx->map[i][j] == 'E')
				mlx->ee++;
			else if (mlx->map[i][j] == 'P')
				mlx->pp++;
			else if (mlx->map[i][j] == 'X')
				mlx->xx++;
			j++;
		}
	}
	if (mlx->pp != 1 || mlx->ee != 1 || mlx->cc == 0)
		ft_error("ERROR: problem in map characters");
	return (0);
}

void	check_file(char *str)
{
	int	i;

	i = strlen(str) - 4;
	if (str[i] == '.' && str[++i] == 'b' && str[++i] == 'e' && str[++i] == 'r')
		return ;
	else
		ft_error("ERROR: extension\n");
}

int	parsing(char **av, t_libx *mlx)
{
	int	fd;

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
	if (validpath_checker(mlx) == -1)
		return (-1);
	return (0);
}
