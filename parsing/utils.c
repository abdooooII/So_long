/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:52:20 by abouafso          #+#    #+#             */
/*   Updated: 2024/05/02 02:52:10 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr_fd_positive(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr_fd_positive(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	player_position(t_libx *mlx, int *i, int *j)
{
	while (mlx->map[*i])
	{
		*j = 0;
		while (mlx->map[*i][*j])
		{
			if (mlx->map[*i][*j])
				return ;
			(*j)++;
		}
		(*i)++;
	}
}

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
