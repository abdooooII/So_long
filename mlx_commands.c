/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:59:28 by abouafso          #+#    #+#             */
/*   Updated: 2024/05/02 05:28:31 by abouafso         ###   ########.fr       */
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
	load_image(mlx, "./assets/background.xpm", &(mlx->background));
	load_image(mlx, "./assets/wall.xpm", &(mlx->wall));
	load_image(mlx, "./assets/player.xpm", &(mlx->player));
	load_image(mlx, "./assets/collectibles.xpm", &(mlx->collectibles));
	load_image(mlx, "./assets/exit.xpm", &(mlx->exit));
	load_image(mlx, "./assets/enemy2.xpm", &(mlx->enemy));
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
//hooks

int	destroy_helper(void *param)
{
	(void)param;
	ft_putstr("close window");
	exit(EXIT_SUCCESS);
}
