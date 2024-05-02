/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:06:24 by abouafso          #+#    #+#             */
/*   Updated: 2024/05/02 00:09:10 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_right(t_libx *mlx)
{
	player_positionn(mlx->map, &mlx->y, &mlx->x);
	if (mlx->map[mlx->y][mlx->x + 1] == '0'
		|| mlx->map[mlx->y][mlx->x + 1] == 'C')
	{
		mlx->map[mlx->y][mlx->x + 1] = 'P';
		mlx->map[mlx->y][mlx->x] = '0';
		mlx->moves++;
		ft_putnbr_fd_positive(mlx->moves);
		ft_putstr("\n");
	}
	else if (mlx->map[mlx->y][mlx->x + 1] == 'E')
	{
		if (c_count(mlx->map) == 0)
		{
			ft_putstr("you won!!!!");
			exit(EXIT_SUCCESS);
		}
		else if (mlx->map[mlx->y][mlx->x + 1] == 'X')
		{
			ft_putstr("you lose !!!");
			exit(EXIT_SUCCESS);
		}
	}
}

void	move_to_left(t_libx *mlx)
{
	player_positionn(mlx->map, &mlx->y, &mlx->x);
	if (mlx->map[mlx->y][mlx->x - 1] == '0'
		|| mlx->map[mlx->y][mlx->x - 1] == 'C')
	{
		mlx->map[mlx->y][mlx->x - 1] = 'P';
		mlx->map[mlx->y][mlx->x] = '0';
		mlx->moves++;
		ft_putnbr_fd_positive(mlx->moves);
		ft_putstr("\n");
	}
	else if (mlx->map[mlx->y][mlx->x - 1] == 'E')
	{
		if (c_count(mlx->map) == 0)
		{
			ft_putstr("you won!!!!");
			exit(EXIT_SUCCESS);
		}
	}
	else if (mlx->map[mlx->y][mlx->x - 1] == 'X')
	{
		ft_putstr("you lose !!!");
		exit(EXIT_SUCCESS);
	}
}

void	move_to_up(t_libx *mlx)
{
	player_positionn(mlx->map, &mlx->y, &mlx->x);
	if (mlx->map[mlx->y - 1][mlx->x] == '0'
		|| mlx->map[mlx->y - 1][mlx->x] == 'C')
	{
		mlx->map[mlx->y - 1][mlx->x] = 'P';
		mlx->map[mlx->y][mlx->x] = '0';
		mlx->moves++;
		ft_putnbr_fd_positive(mlx->moves);
		ft_putstr("\n");
	}
	else if (mlx->map[mlx->y - 1][mlx->x] == 'E')
	{
		if (c_count(mlx->map) == 0)
		{
			ft_putstr("you won!!!!");
			exit(EXIT_SUCCESS);
		}
	}
	else if (mlx->map[mlx->y - 1][mlx->x] == 'X')
	{
		ft_putstr("you lose !!!");
		exit(EXIT_SUCCESS);
	}
}

void	move_to_down(t_libx *mlx)
{
	player_positionn(mlx->map, &mlx->y, &mlx->x);
	if (mlx->map[mlx->y + 1][mlx->x] == '0'
		|| mlx->map[mlx->y + 1][mlx->x] == 'C')
	{
		mlx->map[mlx->y + 1][mlx->x] = 'P';
		mlx->map[mlx->y][mlx->x] = '0';
		mlx->moves++;
		ft_putnbr_fd_positive(mlx->moves);
		ft_putstr("\n");
	}
	else if (mlx->map[mlx->y + 1][mlx->x] == 'E')
	{
		if (c_count(mlx->map) == 0)
		{
			ft_putstr("you won!!!!");
			exit(EXIT_SUCCESS);
		}
	}
	else if (mlx->map[mlx->y + 1][mlx->x] == 'X')
	{
		ft_putstr("you lose !!!");
		exit(EXIT_SUCCESS);
	}
}
