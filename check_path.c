/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:10:58 by abouafso          #+#    #+#             */
/*   Updated: 2024/03/11 23:16:23 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_copie(t_list *vars)
{
	int	i;
	int ii;
	char	**map_copie;

	ii = countlines(vars);
	map_copie = (char **) malloc (sizeof(char *) * ii + 1);
	if (!map_copie)
		return (NULL);
	i = 0;
	while (i < ii)
	{
		map_copie[i] = ft_strdup(vars->my_map[i]);
		if (!map_copie[i])
			ft_error("Error\nfor strdup to copie map\n");
		i++;
	}
	map_copie[i] = NULL;
	return (map_copie);
}

void	player_position(t_list *vars, int *i, int *j)
{
	while(vars->my_map[*i])
	{
		*j = 0;
		while(vars->my_map[*i][*j])
		{
			if(vars->my_map[*i][*j])
				return;
			(*j)++;
		}
		(*i)++;
	}
}

void ft_flood_fill(t_list *vars, int i, int j)
{
	// printf("i: %d\tj: %d\tcountlines: %d\tft_strlen: %d\n", i, j, countlines(vars), ft_strlen(vars->my_map[0]));
	if (i < 0 || i >= countlines(vars) || j < 0 
	|| j >= ft_strlen(vars->updated_map[0]) 
	|| vars->updated_map[i + 1][j + 1] == '1' || vars->updated_map[i + 1][j + 1] == 'S'
	|| vars->updated_map[i + 1][j + 1] == 'E')
		return ;
	vars->updated_map[i + 1][j + 1] = 'S';
	ft_flood_fill(vars, i - 1, j);
	ft_flood_fill(vars, i + 1, j);
	ft_flood_fill(vars, i , j - 1);
	ft_flood_fill(vars, i, j + 1);
}

void check_path(t_list *vars)
{
	int	i;
	int	j;
	int count = countlines(vars);
	
	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < ft_strlen(vars->updated_map[i]))
		{
			if (vars->updated_map[i][j] == 'C' || (vars->updated_map[i][j] == 'E' 
			&& vars->updated_map[i + 1][j] != 'S' && vars->updated_map[i - 1][j] != 'S' 
			&& vars->updated_map[i][j + 1] != 'S' && vars->updated_map[i][j - 1] != 'S'))
			{
				ft_error("ERROR : the path is not valid!");
			}
			j++;
		}
		i++;
	}
}

// void ft_print()
// {
// 	printf("HHHHHHH");
// 	exit(EXIT_FAILURE);

	
// }
void validpath_checker(t_list *vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	vars->updated_map = map_copie(vars);
	player_position(vars, &i, &j);
	ft_flood_fill(vars, i, j);
	// printf("%s",vars->updated_map[1]);
	// printf("%s",vars->my_map[1]);
	check_path(vars);
}