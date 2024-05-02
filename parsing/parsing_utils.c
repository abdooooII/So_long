/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:38:04 by abouafso          #+#    #+#             */
/*   Updated: 2024/05/02 03:45:10 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_spaces(t_libx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == ' ' || mlx->map[i][j] == '\t')
				ft_error("ERROR :found white spaces on the map!");
			j++;
		}
		i++;
	}
	return (0);
}

int	check_invalid_characters(t_libx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] != 'X' && mlx->map[i][j] != '1'
					&& mlx->map[i][j] != '0'
					&& mlx->map[i][j] != 'C' && mlx->map[i][j] != 'P'
					&& mlx->map[i][j] != 'E' && mlx->map[i][j] != '\n')
				ft_error("ERROR: invalid characters\n");
			j++;
		}
		i++;
	}
	return (0);
}

int	check_walls(t_libx *mlx)
{
	int	i;
	int	j;

	i = countlines(mlx) - 1;
	j = 0;
	while (mlx->map[0][j])
	{
		if (mlx->map[0][j] != '1' && mlx->map[0][j] != '\n')
			ft_error("ERROR; walls");
		j++;
	}
	j = 0;
	while (mlx->map[i][j])
	{
		if (mlx->map[i][j] != '1')
			ft_error("ERROR; walls");
		j++;
	}
	return (0);
}

int	check_sides(t_libx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(mlx->map[i]) - 2;
	while (mlx->map[i])
	{
		if (mlx->map[i][0] != '1' || mlx->map[i][j] != '1')
			ft_error("ERROR: invalid map sides!");
		i++;
	}
	return (0);
}

int	check_map_width(t_libx *mlx)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(mlx->map[0]);
	while (mlx->map[i + 1])
	{
		if (ft_strlen(mlx->map[i]) != len)
			ft_error("ERROR: check map width");
		i++;
	}
	if (ft_strlen(mlx->map[i]) != len - 1)
		ft_error("ERROR: check map width");
	return (0);
}
