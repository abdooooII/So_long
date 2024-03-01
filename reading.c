/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:01:14 by abouafso          #+#    #+#             */
/*   Updated: 2024/03/01 07:35:40 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(int fd, char *av)
{
	int		i;
	char	*line;
	char	**all_lines;

	i = count_lines(fd);
	close(fd);
	fd = open(av, O_RDONLY);
	all_lines = (char **)malloc(sizeof(char *) * i);
	if (!all_lines)
		return (NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		all_lines[i] = ft_strdup(line);
		free(line);
		if (!all_lines[i])
			break ;
		i++;
	}
	all_lines[i] = NULL;
	return (all_lines);
}

int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
	}
	return (count);
}
