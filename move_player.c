/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 05:04:43 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/10 01:41:54 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_player_direction(int keycode, t_libx *mlx)
{
	if (keycode == D)
		load_image(mlx, "./textures/player.xpm", &(mlx->player));
	else if (keycode == A)
		load_image(mlx, "./textures/playerD.xpm", &(mlx->player));
}

void	enemy_animation(int keycode, t_libx *mlx)
{
	static int	current_frame = 0;
	int			num_frames;
	char		*image_files[3];

	image_files[0] = "./textures/enemy1.xpm";
	image_files[1] = "./textures/enemy2.xpm";
	image_files[2] = "./textures/enemy3.xpm";
	num_frames = 3;
	(void) keycode;
	load_image(mlx, image_files[current_frame], &(mlx->enemy));
	current_frame = (current_frame + 1) % num_frames;
}

void	move_player(t_libx *mlx, int keycode)
{
	if (keycode == A)
	{
		move_to_left(mlx);
		change_player_direction(keycode, mlx);
		enemy_animation(keycode, mlx);
	}
	else if (keycode == D)
	{
		move_to_right(mlx);
		change_player_direction(keycode, mlx);
		enemy_animation(keycode, mlx);
	}
	else if (keycode == W)
	{
		move_to_up(mlx);
		enemy_animation(keycode, mlx);
	}
	else if (keycode == S)
	{
		move_to_down(mlx);
		enemy_animation(keycode, mlx);
	}
}

int	start_the_game(int keycode, t_libx *mlx)
{
	char	*moves;

	if (keycode == A || keycode == D || keycode == S || keycode == W)
	{
		move_player(mlx, keycode);
		start_map(*mlx);
		moves = ft_itoa(mlx->moves);
		mlx_string_put(mlx->mlx, mlx->win, 32, 32, 0xFFFFFF, moves);
		free(moves);
		mlx_string_put(mlx->mlx, mlx->win, 32, 15, 0xFFFFFF, "moves :");
		mlx->y = 0;
		mlx->x = 0;
	}
	if (keycode == 53)
		destroy_helper(mlx);
	return (0);
}
