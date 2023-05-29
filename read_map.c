/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:01:25 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/29 16:08:30 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_line(char *buffer)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (*buffer)
	{
		if (ft_strchr(buffer))
			count += 1;
		else if (*buffer != '\0')
		//something missing here
	}
}

int	read_map(const char *file, int *line, int *column)
{
	int		fd;
	int		c;
	char	*buffer;

	c = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		c = read(fd, buffer, BUFFER_SIZE);
		if (c < 0)
			return (0);
	}
}
// int len_height(t_list *data)
// {
// 	int i = 0;
// 	char **map = data->map_2d;
// 	 while(map[i])
//     {
//         i++;
//     }
// 	return (i);
// }
// int len_width(t_list *data)
// {
// 	int j = 0;
// 	while(data->map_2d[0][j])
// 	{
// 		j++;
// 	}
// 	return (j);
// }