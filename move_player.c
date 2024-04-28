/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:55:06 by abouafso          #+#    #+#             */
/*   Updated: 2024/04/28 20:38:53 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_to_right(t_libx *mlx)
{
    player_position(mlx->map, &mlx->i, mlx->y);

    if(mlx->map[mlx->i][mlx->j + 1] == '0')
    {
        mlx->map[mlx->i][mlx->j + 1] == 'P';
        mlx->map[mlx->i][mlx->j] == '0';
    }
    else if(mlx->map[mlx->i][mlx->j + 1] == 'C')
    {
        mlx->map[mlx->i][mlx->j + 1] == 'P';
        mlx->map[mlx->i][mlx->j] == '0';
    }
    else if(mlx->map[mlx->i][mlx->j + 1] == 'E')
    {
        if(C_count(mlx->map) == 0)
        {
            printf("you won!!!!")
            exit(EXIT_SUCCESS);
        }
    }
}

void    move_to_left(t_libx *mlx)
{
    player_position(mlx->map, &mlx->i, mlx->y);

    if(mlx->map[mlx->i][mlx->j - 1] == '0')
    {
        mlx->map[mlx->i][mlx->j - 1] == 'P';
        mlx->map[mlx->i][mlx->j] == '0';
    }
    else if(mlx->map[mlx->i][mlx->j - 1] == 'C')
    {
        mlx->map[mlx->i][mlx->j - 1] == 'P';
        mlx->map[mlx->i][mlx->j] == '0';
    }
    else if(mlx->map[mlx->i][mlx->j - 1] == 'E')
    {
        if(C_count(mlx->map) == 0)
        {
            printf("you won!!!!")
            exit(EXIT_SUCCESS);
        }
    }
}

void    move_to_up(t_libx *mlx)
{
    player_position(mlx->map, &mlx->i, mlx->y);

    if(mlx->map[mlx->i - 1][mlx->j] == '0')
    {
        mlx->map[mlx->i - 1][mlx->j] == 'P';
        mlx->map[mlx->i][mlx->j] == '0';
    }
    else if(mlx->map[mlx->i - 1][mlx->j] == 'C')
    {
        mlx->map[mlx->i - 1][mlx->j] == 'P';
        mlx->map[mlx->i][mlx->j] == '0';
    }
    else if(mlx->map[mlx->i - 1][mlx->j] == 'E')
    {
        if(C_count(mlx->map) == 0)
        {
            printf("you won!!!!")
            exit(EXIT_SUCCESS);
        }
    }
}

void    move_to_down(t_libx *mlx)
{
    player_position(mlx->map, &mlx->i, mlx->y);

    if(mlx->map[mlx->i + 1][mlx->j] == '0')
    {
        mlx->map[mlx->i + 1][mlx->j] == 'P';
        mlx->map[mlx->i][mlx->j] == '0';
    }
    else if(mlx->map[mlx->i + 1][mlx->j] == 'C')
    {
        mlx->map[mlx->i + 1][mlx->j] == 'P';
        mlx->map[mlx->i][mlx->j] == '0';
    }
    else if(mlx->map[mlx->i + 1][mlx->j] == 'E')
    {
        if(C_count(mlx->map) == 0)
        {
            printf("you won!!!!")
            exit(EXIT_SUCCESS);
        }
    }
}

void    move_player(t_libx *mlx, int keycode)
{
    if (keycode == A)
        move_to_left(mlx);
    else if (keycode == D)
        move_to_right(mlx);
    else if (keycode == W)
        move_to_up(mlx);
    else if (keycode == S)
        move_to_down(mlx);
}

int start_the_game(t_libx *mlx, int keycode)
{
    if(keycode == 53)
        exit(EXIT_SUCCESS);
    if(keycode == A || keycode == D || keycode == S || keycode == W)
    {
        move_player(mlx, keycode);
        start_map(mlx->map, *mlx);
        mlx->x = 0;
        mlx->y = 0;
    }

}



