/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:01:14 by abouafso          #+#    #+#             */
/*   Updated: 2024/05/01 00:57:49 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**read_map(int fd, char *av)
{
	int		i;
	char	**all_lines;

	i = count_lines(fd);
	close(fd);
	fd = open(av, O_RDONLY);
	all_lines = (char **)malloc(sizeof(char *) * i + 1);
	if (!all_lines)
		return (NULL);
	i = 0;
	while (1)
	{
		all_lines[i] = get_next_line(fd);;
		if (!all_lines[i])
			break ;
		i++;
	}
	return (all_lines);
}

int	  count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		count++;
	}
	return (count);
}
