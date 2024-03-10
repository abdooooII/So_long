/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:10:58 by abouafso          #+#    #+#             */
/*   Updated: 2024/03/10 18:18:17 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_copie(char **lines)
{
	int	i;
	char	**map_copie;

	i = count_lines(lines);
	map_copie = (char **) malloc (sizeof(char *) * i + 1);
	if (!map_copie)
		return (NULL);
	i = 0;
	while (lines)
	{
		map_copie[i] = ft_strdup(lines[i]);
		if (!map_copie)
			ft_error("Error\nfor strdup to copie map\n");
		i++;
	}
	map_copie[i] = NULL;
	return (map_copie);
}

void	player_position(char **lines, int *i, int *j)
{
	while(lines[*i])
	{
		*j = 0;
		while(lines[*i][*j])
		{
			if(lines[*i][*j])
				return;
			(*j)++;
		}
		(*i)++;
	}
}

void ft_flood_fill(char **lines, int i, int j)
{
	if(i < 0 || j < 0 || j >= ft_strlen(lines[0]) || i >= countlines(lines) || lines[i][j] == 'E' || lines[i][j] == '1' || lines[i][j] == 'S')
		return ;
	lines[i][j] = 'S';
	ft_flood_fill(lines, i + 1, j);
	ft_flood_fill(lines, i - 1, j);
	ft_flood_fill(lines, i , j + 1);
	ft_flood_fill(lines, i, j - 1);
}
void check_path(char **lines)
{
	int	i;
	int	j;
	int count = countlines(lines);
	
	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < ft_strlen(lines[i]))
		{
			if (lines[i][j] == 'C' || (lines[i][j] == 'E' 
			&& lines[i + 1][j] != 'S' && lines[i - 1][j] != 'S' 
			&& lines[i][j + 1] != 'S' && lines[i][j - 1] != 'S'))
			{
				ft_error("ERROR : the path is not valid!");
			}
			j++;
		}
		i++;
	}
}
void validpath_checker(char **lines)
{
	char	**updated_map;
	int		i;
	int		j;

	updated_map = map_copie(lines);
}