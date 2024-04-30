#include "so_long.h"

void    move_to_right(t_libx *mlx)
{

    player_positionn(mlx->map, &mlx->y, &mlx->x);
    if (mlx->map[mlx->y][mlx->x + 1] == '0'  || mlx->map[mlx->y][mlx->x + 1] == 'C')
    {
        mlx->map[mlx->y][mlx->x + 1] = 'P';
        mlx->map[mlx->y][mlx->x] = '0';
		mlx->moves++;
		ft_putnbr_fd_positive(mlx->moves);
		ft_putstr("\n");
    }
    else if (mlx->map[mlx->y][mlx->x + 1] == 'E')
    {
        if (C_count(mlx->map) == 0)
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

void    move_to_left(t_libx *mlx)
{
    player_positionn(mlx->map, &mlx->y, &mlx->x);
    if (mlx->map[mlx->y][mlx->x - 1] == '0' || mlx->map[mlx->y][mlx->x - 1] == 'C')
    {
        mlx->map[mlx->y][mlx->x - 1] = 'P';
        mlx->map[mlx->y][mlx->x] = '0';
		mlx->moves++;
		ft_putnbr_fd_positive(mlx->moves);
		ft_putstr("\n");
    }
    else if (mlx->map[mlx->y][mlx->x - 1] == 'E')
    {
          if (C_count(mlx->map) == 0)
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

void    move_to_up(t_libx *mlx)
{
    player_positionn(mlx->map, &mlx->y, &mlx->x);

    if (mlx->map[mlx->y - 1][mlx->x] == '0'  || mlx->map[mlx->y - 1][mlx->x] == 'C')
    {
        mlx->map[mlx->y - 1][mlx->x] = 'P';
        mlx->map[mlx->y][mlx->x] = '0';
		mlx->moves++;
		ft_putnbr_fd_positive(mlx->moves);
		ft_putstr("\n");
    }
    else if (mlx->map[mlx->y - 1][mlx->x] == 'E')
    {
        if (C_count(mlx->map) == 0)
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

void    move_to_down(t_libx *mlx)
{
    player_positionn(mlx->map, &mlx->y, &mlx->x);

    if (mlx->map[mlx->y + 1][mlx->x] == '0' || mlx->map[mlx->y + 1][mlx->x] == 'C')
    {
        mlx->map[mlx->y + 1][mlx->x] = 'P';
        mlx->map[mlx->y][mlx->x] = '0';
		mlx->moves++;
		ft_putnbr_fd_positive(mlx->moves);
		ft_putstr("\n");
    }
    else if (mlx->map[mlx->y + 1][mlx->x] == 'E')
    {
          if (C_count(mlx->map) == 0)
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

void	change_player_direction(int keycode, t_libx *mlx)
{
	if(keycode == D)
		load_image(mlx, "assets/player.xpm", &(mlx->player));
	else if(keycode == A)
		load_image(mlx, "assets/playerD.xpm", &(mlx->player));

}

void	enemy_animation(int keycode, t_libx *mlx)
{
	(void) keycode;
	static int current_frame = 0;
	int num_frames = 3; // Change this to the number of frames in your animation
	char *image_files[] = {"assets/enemy1.xpm", "assets/enemy2.xpm", "assets/enemy3.xpm"};

	load_image(mlx, image_files[current_frame], &(mlx->enemy));
	current_frame = (current_frame + 1) % num_frames;
}

void    move_player(t_libx *mlx, int keycode)
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
        move_to_up(mlx);
    else if (keycode == S)
        move_to_down(mlx);
}

int start_the_game(int keycode, t_libx *mlx)
{
    if (keycode == A || keycode == D || keycode == S || keycode == W)
    {
        move_player(mlx, keycode);
        start_map(*mlx);
		mlx_string_put(mlx->mlx, mlx->win, 32, 32, 0xFFFFFF, ft_itoa(mlx->moves));
		mlx_string_put(mlx->mlx, mlx->win, 32, 15, 0xFFFFFF, "moves :");
        mlx->y = 0;
        mlx->x = 0;
    }
    if (keycode == 53)
        exit(EXIT_SUCCESS);
    return (0);
}
