/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:24:48 by abouafso          #+#    #+#             */
/*   Updated: 2024/03/11 22:30:13 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrchr(char *str, int c)
{
	int	index;

	index = ft_strlen(str) + 1;
	while (index > 0)
	{
		index--;
		if (str[index] == c)
			return (str + index);
	}
	return (NULL);
}

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(num_elements * element_size);
	if (!str)
		return (NULL);
	while (i < num_elements * element_size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		lenght;
	char	*new;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	lenght = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(lenght);
	if (!new)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}
