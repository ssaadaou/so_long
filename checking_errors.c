/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:57:38 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/29 00:05:04 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	_error(int ac, char **av)
{
	int	fd;
	int	i;

	if (ac != 2)
	{
		ft_putstr_fd("Error: Incorrect number of arguments\n", 2);
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Failed to open the .ber file\n", 2);
		exit(1);
	}
	i = ft_strlen(av[1]);
	if (i < 5 || (av[1][i - 1] != 'r' || av[1][i - 2] != 'e' \
	|| av[1][i - 3] != 'b' || av[1][i - 4] != '.'))
	{
		ft_putstr_fd("Error : Incorrect type of file", 2);
		exit(1);
	}
	return (fd);
}
