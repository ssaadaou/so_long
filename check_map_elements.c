/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:56:07 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/29 15:56:14 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	new_line_error(char *map, int new_line_count)
{
	if (new_line_count > 1)
	{
		free(map);
		ft_putstr_fd("Error: Too Many New Lines", 2);
		exit (1);
	}
}

void	invalid_map(char *map)
{
	free(map);
	ft_putstr_fd("Error: Invalid map", 2);
	exit (1);
}

void	check_map(t_list *data)
{
	int		i;
	char	*map;
	int		new_line_count;

	map = data->map_1d;
	new_line_count = 0;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '1' || map[i] == '0' || map[i] == 'C' || \
			map[i] == 'P' || map[i] == 'E' || map[i] == '\n')
		{
			if (map[i] == '\n' && ++new_line_count > 1)
				new_line_error(map, new_line_count);
			else
				new_line_count = 0;
			i++;
		}
		else
		{
			invalid_map(map);
		}
	}
}

void	check_elements(t_list *data)
{
	int		i;
	int		count;
	int		count1;
	int		count2;
	char	*map;

	i = 0;
	count = 0;
	count1 = 0;
	count2 = 0;
	map = data->map_1d;
	while (map[i])
	{
		if (map[i] == 'P')
			count++;
		if (map[i] == 'E')
			count1++;
		if (map[i] == 'C')
			count2++;
		i++;
	}
	if (count != 1 || count1 != 1 || count2 < 1)
		invalid_map(map);
}
