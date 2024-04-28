/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:38:04 by abouafso          #+#    #+#             */
/*   Updated: 2024/04/28 18:15:19 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

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

int	check_spaces(t_list *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->my_map[i])
	{
		j = 0;
		while (vars->my_map[i][j])
		{
			if (vars->my_map[i][j] == ' ' || vars->my_map[i][j] == '\t')
				ft_error("ERROR :found white spaces on the map!");
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_characters(t_list *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->my_map[++i])
	{
		j = 0;
		while (vars->my_map[i][j])
		{
			if (vars->my_map[i][j] == 'C')
				vars->c++;
			else if (vars->my_map[i][j] == 'E')
				vars->e++;
			else if (vars->my_map[i][j] == 'P')
				vars->p++;
			j++;
		}
	}
	if (vars->p != 1 || vars->e != 1 || vars->c == 0)
		ft_error("ERROR: problem in map characters");
	return (0);
}

int	check_invalid_characters(t_list *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->my_map[i])
	{
		j = 0;
		while (vars->my_map[i][j])
		{
			if (vars->my_map[i][j] != '1' && vars->my_map[i][j] != '0'
				&& vars->my_map[i][j] != 'C' && vars->my_map[i][j] != 'P'
				&& vars->my_map[i][j] != 'E' && vars->my_map[i][j] != '\n')
				ft_error("ERROR: invalid characters\n");
			j++;
		}
		i++;
	}
	return (0);
}

int	check_walls(t_list *vars)
{
	int	i;
	int	j;

	i = countlines(vars) - 1;
	j = 0;
	while (vars->my_map[0][j])
	{
		if (vars->my_map[0][j] != '1' && vars->my_map[0][j] != '\n')
			ft_error("ERROR; walls");
		j++;
	}
	j = 0;
	while (vars->my_map[i][j])
	{
		if (vars->my_map[i][j] != '1')
			ft_error("ERROR; walls");
		j++;
	}
	return (0);
}

int	countlines(t_list *vars)
{
	int	count;

	count = 0;
	while (vars->my_map[count])
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

int	check_sides(t_list *vars)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(vars->my_map[i]) - 2;
	while (vars->my_map[i])
	{
		if (vars->my_map[i][0] != '1' || vars->my_map[i][j] != '1')
			ft_error("ERROR: invalid map sides!");
		i++;
	}
	return (0);
}

int	check_map_width(t_list *vars)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(vars->my_map[0]);
	while (vars->my_map[i + 1])
	{
		if (ft_strlen(vars->my_map[i]) != len)
			ft_error("ERROR: check map width");
		i++;
	}
	if (ft_strlen(vars->my_map[i]) != len - 1)
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
		while(mao[i][j])
		{
			if(map[i][j] == 'C')
				C++;
			j++;
		}
		i++;
	}
	return(C);
}