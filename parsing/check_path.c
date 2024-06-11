/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:10:58 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/10 01:53:42 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map_copie(t_libx *mlx)
{
	int		i;
	int		ii;
	char	**map_copie;

	ii = countlines(mlx);
	map_copie = (char **) malloc (sizeof(char *) * ii + 1);
	if (!map_copie)
		return (NULL);
	i = 0;
	while (i < ii)
	{
		map_copie[i] = ft_strdup(mlx->map[i]);
		if (!map_copie[i])
			ft_error("Error\nfor strdup to copie map\n");
		i++;
	}
	map_copie[i] = NULL;
	return (map_copie);
}

void	player_positionn(char **map, int *i, int *j)
{
	while (map[*i])
	{
		*j = 0;
		while (map[*i][*j])
		{
			if (map[*i][*j] == 'P')
				return ;
			(*j)++;
		}
		(*i)++;
	}
}

void	ft_flood_fill(t_libx *mlx, int i, int j)
{
	if (i < 0 || i >= countlines(mlx) || j < 0
		|| j >= ft_strlen(mlx->updated_map[0])
		|| mlx->updated_map[i][j] == '1'
		|| mlx->updated_map[i][j] == 'S'
		|| mlx->updated_map[i][j] == 'E')
		return ;
	mlx->updated_map[i][j] = 'S';
	ft_flood_fill(mlx, i - 1, j);
	ft_flood_fill(mlx, i + 1, j);
	ft_flood_fill(mlx, i, j - 1);
	ft_flood_fill(mlx, i, j + 1);
}

void	check_path(t_libx *mlx)
{
	int	i;
	int	j;
	int	count;

	count = countlines(mlx);
	i = -1;
	while (++i < count)
	{
		j = 0;
		while (j < ft_strlen(mlx->updated_map[i]))
		{
			if (mlx->updated_map[i][j] == 'C'
					|| (mlx->updated_map[i][j] == 'E'
						&& mlx->updated_map[i + 1][j] != 'S'
						&& mlx->updated_map[i - 1][j] != 'S'
						&& mlx->updated_map[i][j + 1] != 'S'
						&& mlx->updated_map[i][j - 1] != 'S'))
			{
				ft_error("ERROR : the path is not valid!");
				ft_free(mlx->updated_map);
			}
			j++;
		}
	}
	ft_free(mlx->updated_map);
}

int	validpath_checker(t_libx *mlx)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx->updated_map = map_copie(mlx);
	if (!mlx->updated_map)
		return (-1);
	player_position(mlx, &i, &j);
	ft_flood_fill(mlx, i, j);
	check_path(mlx);
	return (0);
}
