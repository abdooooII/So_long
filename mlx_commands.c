/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:59:28 by abouafso          #+#    #+#             */
/*   Updated: 2024/04/30 07:05:41 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    initialize_mlx(t_libx   *mlx)
{
    mlx->mlx = mlx_init();
    if(!mlx->mlx)
    	ft_error("Error while ");
}

void    new_window(t_libx *mlx)
{
    mlx->win = mlx_new_window(mlx->mlx , (ft_strlen(mlx->map[0]) - 1) * 64, countliness(mlx->map) * 64 , "So long");
    if(!mlx->win)
        ft_error("Error while creating the window ! ");
}

void    load_image(t_libx *mlx, char *filename, void **item)
{
    *item = mlx_xpm_file_to_image(mlx->mlx, filename, &mlx->width, &mlx->height);
    if(!*item)
        ft_error("Error while converting the xpm file to image ! ");
}
void put_image(t_libx *mlx, int x, int y, void *image)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, image, y * 64, x * 64);
}

void	start_window(t_libx	*mlx)
{
	mlx->width = 0;
	mlx->height = 0;

	initialize_mlx(mlx);
	new_window(mlx);
	load_image(mlx, "background.xpm", &(mlx->background));
	load_image(mlx, "wall.xpm", &(mlx->wall));
	load_image(mlx, "player.xpm", &(mlx->player));
	load_image(mlx, "collectibles.xpm", &(mlx->collectibles));
	load_image(mlx, "exit.xpm", &(mlx->exit));
	load_image(mlx, "enemy2.xpm", &(mlx->enemy));
}

void	start_map(char **map, t_libx mlx)
{
	int i = 0;
	int	j = 0;

	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == '1')
				put_image(&mlx, i, j, mlx.wall);
			else if (map[i][j] == '0')
				put_image(&mlx, i, j, mlx.background);
			else if (map[i][j] == 'P')
				put_image(&mlx, i, j, mlx.player);
			else if (map[i][j] == 'C')
				put_image(&mlx, i, j, mlx.collectibles);
			else if (map[i][j] == 'E')
				put_image(&mlx, i, j, mlx.exit);
			else if (map[i][j] == 'X')
				put_image(&mlx, i, j, mlx.enemy);
			j++;
		}
		i++;
	}
}

void	map_dimension(t_libx *mlx)
{
	mlx->width = countliness(mlx->map) * 64;
	mlx->height = ft_strlen(mlx->map[0]) * 64;

	start_window(mlx);
}
//hooks

int destroy_helper(void *param)
{
	(void)param;
	// t_libx *mlx = (t_libx *)param;
	printf("close window");
	exit(EXIT_SUCCESS);
}