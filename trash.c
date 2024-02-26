/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:40:11 by abouafso          #+#    #+#             */
/*   Updated: 2024/02/26 16:40:12 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_map(int fd, char *line)
{
	int i = 0;
	char *line;
	char **all_lines;

	fd = open("map.ber", O_RDONLY);
	
}