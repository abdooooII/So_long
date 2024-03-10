/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:10:58 by abouafso          #+#    #+#             */
/*   Updated: 2024/03/10 23:05:34 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_copie(t_list *vars)
{
	int	i;
	char	**map_copie;

	i = countlines(vars);
	map_copie = (char **) malloc (sizeof(char *) * i + 1);
	if (!map_copie)
		return (NULL);
	i = 0;
	while (vars->my_map[i])
	{
		map_copie[i] = ft_strdup(vars->my_map[i]);
		if (!map_copie)
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
	if(i < 0 || i >= countlines(vars) || j < 0 || j >= ft_strlen(vars->my_map[0]) 
	|| vars->my_map[i][j] == '1' || vars->my_map[i][j] == 'S'
	|| vars->my_map[i][j] == 'E')
		return ;
	vars->my_map[i][j] = 'S';
	ft_flood_fill(vars, i + 1, j);
	ft_flood_fill(vars, i - 1, j);
	ft_flood_fill(vars, i , j + 1);
	ft_flood_fill(vars, i, j - 1);
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

void ft_print()
{
	printf("HHHHHHH");
	exit(EXIT_FAILURE);

	
}
void validpath_checker(t_list *vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	vars->updated_map = map_copie(vars);
	ft_print();
	player_position(vars, &i, &j);
	ft_flood_fill(vars, i, j);
	check_path(vars);
}