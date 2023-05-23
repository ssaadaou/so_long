/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:55:47 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/23 14:51:19 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char	*ft_strdup( char *src)
// {
// 	int		i;
// 	int		lendsrc;
// 	char	*cpy;

// 	i = 0;
// 	lendsrc = strlen(src);
// 	cpy = malloc(sizeof(char) * (lendsrc + 1));
// 	if (!cpy)
// 		return (NULL);
// 	while (src[i])
// 	{
// 		cpy[i] = src[i];
// 		i++;
// 	}
// 	cpy[i] = '\0';
// 	return (cpy);
// }

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
int ft_strlen_lines(char **map_2d)
{
	int i = 0;
	while(map_2d[i])
		i++;
	return (i);
}
// // //
void	floodfill(char **map, int y, int x, int base)
{
	if (map[y][x] != '0' && map[y][x] != 'P' && map[y][x] != base
		&& map[y][x] != 'C')
		return ;
	map[y][x] = 'X';
	floodfill(map, y, x + 1, base);
	floodfill(map, y, x - 1, base);
	floodfill(map, y + 1, x, base);
	floodfill(map, y - 1, x, base);
}

int	check_exist(char **map, int base)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == base)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

