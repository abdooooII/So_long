/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:26:23 by abouafso          #+#    #+#             */
/*   Updated: 2024/02/29 11:48:08 by abouafso         ###   ########.fr       */
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
	int i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
	exit(EXIT_FAILURE);
}


void	check_file(char *str)
{
	int i;

	i = strlen(str) - 4;
	
	if (str[i] == '.' && str[++i] == 'b' && str[++i] == 'e' && str[++i] == 'r')
		return ;
	else
		ft_error("ERROR: extension\n");
}

int	check_spaces(char **lines)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while(lines[i])
	{
		while(lines[i][j])
		{
			if (lines[i][j] == ' ' || lines[i][j] == '\t')
				ft_error("ERROR :found white spaces on the map!");
			j++;
		}
		j = 0;
		if (lines[1][j] == '\0')
			ft_error("ERROR : the map is empty");
		i++;
	}
	return 0;
}

int	check_map_characters(char **lines)
{
	int i = 0;
	int j = 0;
	int E = 0;
	int P = 0;
	int C = 0;

	while(lines[i])
	{
		while(lines[i][j])
		{
			if (lines[i][j] == 'C')
				C++;
			else if (lines[i][j] == 'E')
				E++;
			else if (lines[i][j] == 'P')
				P++;
			j++;
		}
		j = 0;
		i++;
	}
	if(P != 1 || E != 1 || C == 0)
		ft_error("ERROR: problem in map characters");
	return (0);
	
}

int	check_invalid_characters(char **lines)
{
	int i = 0;
	int j = 0;
	
	while(lines[i])
	{
		while(lines[i][j])
		{
			if (lines[i][j] != '1' && lines[i][j] != '0' && lines[i][j] != 'C' && lines[i][j] != 'P' && lines[i][j] != 'E' && lines[i][j] != '\n')
			{
				ft_error("ERROR: invalid characters\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_walls(char **lines)
{
	int i;
	int j;

	i = countlines(lines) - 1;
	j = 0;
	while(lines[0][j])
	{
		if  (lines[0][j] != '1' && lines[0][j] != '\n')
			ft_error("ERROR; walls");
		j++;
	}
	j = 0;
	while(lines[i][j])
	{
		if  (lines[i][j] != '1')
			ft_error("ERROR; walls");
		j++;
	}
	return (0);
}

int countlines(char **lines)
{
	int count = 0;
	
	while(lines[count])
		count++;
	return(count);
}

int check_sides(char **lines)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(lines[i]) - 2;
	while(lines[i])
	{
		if (lines[i][0] != '1' || lines[i][j] != '1')
			ft_error("ERROR: invalid map sides!");
		i++;
	}
	return (0);
}
int check_map_width(char **lines)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(lines[0]);
	while(lines[i + 1])
	{
		if(ft_strlen(lines[i]) != len )
			ft_error("ERROR: check map width");
		i++;
	}
	if (ft_strlen(lines[i]) != len - 1)
		ft_error("ERROR: check map width");
	return (0); 
}

// int main(int ac, char **av)
// {

//     check_file(av[1]);
//     return (0);
// }