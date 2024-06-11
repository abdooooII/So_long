/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:43:45 by abouafso          #+#    #+#             */
/*   Updated: 2024/05/02 03:49:54 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	countliness(char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

int	countlines(t_libx *mlx)
{
	int	count;

	count = 0;
	while (mlx->map[count])
		count++;
	return (count);
}

int	c_count(char **map)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}
