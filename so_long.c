/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:38:12 by abouafso          #+#    #+#             */
/*   Updated: 2024/04/22 08:38:13 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_list	vars;
	// t_libx	*libx;

	// libx = NULL;
	if (ac != 2)
		ft_error("Error: Invalid number of arguments\n");
	vars.c = 0;
	vars.e = 0;
	vars.p = 0;
	parsing(av, &vars);

	// my_mlx(libx);
}
