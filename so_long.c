/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:38:12 by abouafso          #+#    #+#             */
/*   Updated: 2024/04/30 07:12:46 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void close_window(void *mlx_ptr, void *win_ptr)
{
	(void) mlx_ptr;
	(void) win_ptr;
    printf("Fenêtre fermée\n");
    exit(0);
}
int key_pressed(int keycode, void *param)
{
	
    printf("Key pressed: %d\n", keycode);
    if (keycode == 53) //esc key code number
        close_window(param, NULL);
	// if (key == )
    return (0);
}
#include <string.h>
static int	count_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	j;
	char	*str;
	int		i;

	j = n;
	if (j == 0)
		return ((ft_strdup("0")));
	i = count_len(j);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (j < 0)
	{
		str[0] = '-';
		j = -j;
	}
	str[i--] = '\0';
	while (j)
	{
		str[i] = (j % 10) + '0';
		j /= 10;
		i--;
	}
	return (str);
}
int	main(int ac, char **av)
{
	t_list	vars;
	t_libx	mlx;
	char **map;
	// t_libx	*libx;
	mlx.moves = 0;
	// libx = NULL;
	if (ac != 2)
		ft_error("Error: Invalid number of arguments\n");
	vars.c = 0;
	vars.e = 0;
	vars.p = 0;
	map = parsing(av, &vars, &mlx);
	mlx.x = 0;
	mlx.y = 0;
	start_map(map, mlx);
		
    mlx_hook(mlx.win, 2, 0, start_the_game, &mlx);
	//mlx_hook(mlx.win, 2, 0, key_pressed, &mlx);
    mlx_hook(mlx.win, 17, 0, destroy_helper, &mlx);

	mlx_loop(mlx.mlx);
}
