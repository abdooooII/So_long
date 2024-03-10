/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 01:21:27 by abouafso          #+#    #+#             */
/*   Updated: 2024/03/10 02:42:45 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// void	my_mlx(t_libx *libx, char filename, void **p)
// {
// 	libx->w = 0;
// 	libx->h = 0;
// 	mlx_init();
// 	mlx_new_window(libx->mlx, count_lines(libx->carte) * 60, ft_strlen(libx->carte[0]) * 60, "SO_LONG");
// 	mlx_xpm_file_to_image(libx->mlx, filename, &(libx->w), &(libx->h));
// 	mlx_put_image_to_window(libx->mlx, libx->wind, libx->img, (libx->x) * 60, (libx->y) * 60);
// }
// void	mlx2(t_libx *libx)
// {
// 	libx->w= countlines(libx->carte) * 60;
// 	libx->h = ft_strlen(libx->carte[0]) * 60;
// 	my_mlx(libx->mlx, "chihaja.xpm", &(libx->player));
// 	my_mlx(libx->mlx, "chihaja.xpm", &(libx->collectibles));	
// 	my_mlx(libx->mlx, "chihaja.xpm", &(libx->wall));	
// 	my_mlx(libx->mlx, "chihaja.xpm", &(libx->exit));	
// }
