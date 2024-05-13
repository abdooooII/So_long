/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:10:58 by abouafso          #+#    #+#             */
/*   Updated: 2024/05/13 18:52:33 by abouafso         ###   ########.fr       */
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

void	ft_flood_fill(t_libx *mlx, int i, int j)
{
	if (i < 0 || i >= countlines(mlx) || j < 0
		|| j >= ft_strlen(mlx->updated_map[0])
		|| mlx->updated_map[i + 1][j + 1] == '1'
		|| mlx->updated_map[i + 1][j + 1] == 'S'
		|| mlx->updated_map[i + 1][j + 1] == 'E')
		return ;
	mlx->updated_map[i + 1][j + 1] = 'S';
	ft_flood_fill(mlx, i - 1, j);
	ft_flood_fill(mlx, i + 1, j);
	ft_flood_fill(mlx, i, j - 1);
	ft_flood_fill(mlx, i, j + 1);
}

static void	player_condition(t_libx	*mlx, int i, int j)
{
	if (mlx->updated_map[i][j] == 'P'
			&& mlx->updated_map[i + 1][j] == '1'
			&& mlx->updated_map[i - 1][j] == '1'
			&& mlx->updated_map[i][j + 1] == '1'
			&& mlx->updated_map[i][j - 1] == '1')
	{
		ft_error("ERROR : the path is not valid!");
		ft_free(mlx->updated_map);
	}
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
			player_condition(mlx, i, j);
			j++;
		}
	}
	ft_free(mlx->updated_map);
}

void	validpath_checker(t_libx *mlx)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	mlx->updated_map = map_copie(mlx);
	player_position(mlx, &i, &j);
	ft_flood_fill(mlx, i, j);
	check_path(mlx);
}
