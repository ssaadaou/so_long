/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:55:47 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/16 02:36:19 by ssaadaou         ###   ########.fr       */
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