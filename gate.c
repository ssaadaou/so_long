/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gate.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:51:10 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/28 02:41:00 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exist(char **map, int base) 
{
    int	i = 0;
    int	j;

    while (map[i]) 
	{
        j = 0;
        while (map[i][j]) 
		{
            if (map[i][j] == base)
                return 1;
            j++;
        }
        i++;
    }

    return 0;
}

void floodfill(char **map, int x, int y, int base) 
{
    if ((map[y][x] != '0' && map[y][x] != 'P' && map[y][x] != base && map[y][x] != 'C'))
        return ;

    map[x][y] = 'X';

    floodfill(map, x, y + 1, base);
    floodfill(map, x, y - 1, base);
    floodfill(map, x + 1, y, base);
    floodfill(map, x - 1, y, base);
}

void check_path(struct t_list *data, int base) 
{
    char **map = data->map_2d;

    floodfill(map, data->x_player, data->y_player, base);

    if (base == 'C')
	{
        if (check_exist(map, 'C'))
            ft_putstr_fd("Error: no valid path to collect\n", 2);
			exit (1);
    }

    if (base == 'E') 
	{
        if (check_exist(map, 'E'))
            ft_putstr_fd("Error: no valid path to exit\n", 2);
			exit (1);
    }
    _free(map);
}
void valid_path(t_list *data)
{
	check_path(data, 'C');
	check_path(data, 'E');
}