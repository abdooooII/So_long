/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:59:28 by abouafso          #+#    #+#             */
/*   Updated: 2024/06/10 01:37:23 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_libx *mlx, int x, int y, void *image)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, image, y * 64, x * 64);
}

void	start_window(t_libx	*mlx)
{
	mlx->width = 0;
	mlx->height = 0;
	initialize_mlx(mlx);
	new_window(mlx);
	load_image(mlx, "./textures/background.xpm", &(mlx->background));
	load_image(mlx, "./textures/wall.xpm", &(mlx->wall));
	load_image(mlx, "./textures/player.xpm", &(mlx->player));
	load_image(mlx, "./textures/collectibles.xpm", &(mlx->collectibles));
	load_image(mlx, "./textures/exit.xpm", &(mlx->exit));
	load_image(mlx, "./textures/enemy2.xpm", &(mlx->enemy));
}

void	start_map(t_libx mlx)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (mlx.map[++i])
	{
		j = 0;
		while (mlx.map[i][j])
		{
			if (mlx.map[i][j] == '1')
				put_image(&mlx, i, j, mlx.wall);
			else if (mlx.map[i][j] == '0')
				put_image(&mlx, i, j, mlx.background);
			else if (mlx.map[i][j] == 'P')
				put_image(&mlx, i, j, mlx.player);
			else if (mlx.map[i][j] == 'C')
				put_image(&mlx, i, j, mlx.collectibles);
			else if (mlx.map[i][j] == 'E')
				put_image(&mlx, i, j, mlx.exit);
			else if (mlx.map[i][j] == 'X')
				put_image(&mlx, i, j, mlx.enemy);
			j++;
		}
	}
}

void	map_dimension(t_libx *mlx)
{
	mlx->width = countliness(mlx->map) * 64;
	mlx->height = ft_strlen(mlx->map[0]) * 64;
	start_window(mlx);
}

int	destroy_helper(void *param)
{
	t_libx	*mlx;

	mlx = (t_libx *)param;
	ft_putstr("window closed\n");
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(EXIT_SUCCESS);
}
