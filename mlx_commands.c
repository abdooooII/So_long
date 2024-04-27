/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:59:28 by abouafso          #+#    #+#             */
/*   Updated: 2024/04/27 21:04:51 by abouafso         ###   ########.fr       */
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
    mlx->win = mlx_new_window(mlx->mlx , ft_strlen(mlx->map[0]), countlines(mlx->map), "So long");
    if(!mlx->win)
        ft_error("Error while creating the window ! ");
}

void    load_image(t_libx *mlx, char *filename, void **item)
{
    *item = mlx_xpm_file_to_image(mlx->mlx, filename, mlx->width, mlx->height);
    if(!*item)
        ft_error("Error while converting the xpm file to image ! ");
}
void put_image(t_libx *mlx, )