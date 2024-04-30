/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:38:04 by abouafso          #+#    #+#             */
/*   Updated: 2024/05/01 00:23:29 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(char *s1)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *) malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_putchar(char c)
{
	write(2, &c, 1);
}

char	*ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	check_file(char *str)
{
	int	i;

	i = strlen(str) - 4;
	if (str[i] == '.' && str[++i] == 'b' && str[++i] == 'e' && str[++i] == 'r')
		return ;
	else
		ft_error("ERROR: extension\n");
}

int	check_spaces(t_libx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == ' ' || mlx->map[i][j] == '\t')
				ft_error("ERROR :found white spaces on the map!");
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_characters(t_libx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->map[++i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'C')
				mlx->cc++;
			else if (mlx->map[i][j] == 'E')
				mlx->ee++;
			else if (mlx->map[i][j] == 'P')
				mlx->pp++;
			else if (mlx->map[i][j] == 'X')
				mlx->xx++;
			j++;
		}
	}
	if (mlx->pp != 1 || mlx->ee != 1 || mlx->cc == 0)
		ft_error("ERROR: problem in map characters");
	return (0);
}

int	check_invalid_characters(t_libx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] != 'X' && mlx->map[i][j] != '1' && mlx->map[i][j] != '0'
				&& mlx->map[i][j] != 'C' && mlx->map[i][j] != 'P'
				&& mlx->map[i][j] != 'E' && mlx->map[i][j] != '\n')
				ft_error("ERROR: invalid characters\n");
			j++;
		}
		i++;
	}
	return (0);
}

int	check_walls(t_libx *mlx)
{
	int	i;
	int	j;

	i = countlines(mlx) - 1;
	j = 0;
	while (mlx->map[0][j])
	{
		if (mlx->map[0][j] != '1' && mlx->map[0][j] != '\n')
			ft_error("ERROR; walls");
		j++;
	}
	j = 0;
	while (mlx->map[i][j])
	{
		if (mlx->map[i][j] != '1')
			ft_error("ERROR; walls");
		j++;
	}
	return (0);
}

int	countlines(t_libx *mlx)
{
	int	count;

	count = 0;
	while (mlx->map[count])
		count++;
	return (count);
}
int	countliness(char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

int	check_sides(t_libx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(mlx->map[i]) - 2;
	while (mlx->map[i])
	{
		if (mlx->map[i][0] != '1' || mlx->map[i][j] != '1')
			ft_error("ERROR: invalid map sides!");
		i++;
	}
	return (0);
}

int	check_map_width(t_libx *mlx)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(mlx->map[0]);
	while (mlx->map[i + 1])
	{
		if (ft_strlen(mlx->map[i]) != len)
			ft_error("ERROR: check map width");
		i++;
	}
	if (ft_strlen(mlx->map[i]) != len - 1)
		ft_error("ERROR: check map width");
	return (0);
}

int	C_count(char **map)
{
	int i;
	int j;
	int C;

	C = 0;
	i = 0;
	// j = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'C')
				C++;
			j++;
		}
		i++;
	}
	return(C);
}