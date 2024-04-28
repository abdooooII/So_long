#include "so_long.h"

void    move_to_right(t_libx *mlx)
{
    player_positionn(mlx->map, &mlx->y, &mlx->x);

    if (mlx->map[mlx->y][mlx->x + 1] == '0')
    {
        mlx->map[mlx->y][mlx->x + 1] = 'P';
        mlx->map[mlx->y][mlx->x] = '0';
    }
    else if (mlx->map[mlx->y][mlx->x + 1] == 'C')
    {
        mlx->map[mlx->y][mlx->x + 1] = 'P';
        mlx->map[mlx->y][mlx->x] = '0';
    }
    else if (mlx->map[mlx->y][mlx->x + 1] == 'E')
    {
        if (C_count(mlx->map) == 0)
            printf("you won!!!!");
    }
}

void    move_to_left(t_libx *mlx)
{
    player_positionn(mlx->map, &mlx->y, &mlx->x);

    if (mlx->map[mlx->y][mlx->x - 1] == '0')
    {
        mlx->map[mlx->y][mlx->x - 1] = 'P';
        mlx->map[mlx->y][mlx->x] = '0';
    }
    else if (mlx->map[mlx->y][mlx->x - 1] == 'C')
    {
        mlx->map[mlx->y][mlx->x - 1] = 'P';
        mlx->map[mlx->y][mlx->x] = '0';
    }
    else if (mlx->map[mlx->y][mlx->x - 1] == 'E')
    {
        if (C_count(mlx->map) == 0)
            printf("you won!!!!");
    }
}

void    move_to_up(t_libx *mlx)
{
    player_positionn(mlx->map, &mlx->y, &mlx->x);

    if (mlx->map[mlx->y - 1][mlx->x] == '0')
    {
        mlx->map[mlx->y - 1][mlx->x] = 'P';
        mlx->map[mlx->y][mlx->x] = '0';
    }
    else if (mlx->map[mlx->y - 1][mlx->x] == 'C')
    {
        mlx->map[mlx->y - 1][mlx->x] = 'P';
        mlx->map[mlx->y][mlx->x] = '0';
    }
    else if (mlx->map[mlx->y - 1][mlx->x] == 'E')
    {
        if (C_count(mlx->map) == 0)
            printf("you won!!!!");
    }
}

void    move_to_down(t_libx *mlx)
{
    player_positionn(mlx->map, &mlx->y, &mlx->x);

    if (mlx->map[mlx->y + 1][mlx->x] == '0')
    {
        mlx->map[mlx->y + 1][mlx->x] = 'P';
        mlx->map[mlx->y][mlx->x] = '0';
    }
    else if (mlx->map[mlx->y + 1][mlx->x] == 'C')
    {
        mlx->map[mlx->y + 1][mlx->x] = 'P';
        mlx->map[mlx->y][mlx->x] = '0';
    }
    else if (mlx->map[mlx->y + 1][mlx->x] == 'E')
    {
        if (C_count(mlx->map) == 0)
            printf("you won!!!!");
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
    if (keycode == 53)
        exit(EXIT_SUCCESS);
    if (keycode == A || keycode == D || keycode == S || keycode == W)
    {
        move_player(mlx, keycode);
        start_map(mlx->map, *mlx);
        mlx->y = 0;
        mlx->x = 0;
    }
    return (0);
}
