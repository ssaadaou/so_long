/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:55:14 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/16 20:55:05 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int main (int ac, char **av)
{
    int fd;
    char *line;
    char *map = NULL;
    char **split_map = NULL;
    t_list *game_data;
    fd = _error(ac , av);
    line = get_next_line(fd);
    while (line)
    {
        map = ft_strjoin(map , line);
        free(line);
        line = get_next_line(fd);
    }
    game_data = malloc(sizeof(t_list));
    game_data->map_1d = map;
    check_map(game_data);
    check_elements(game_data);
    split_map = splitt(map, '\n');
    game_data->map_2d = split_map;
    check_rectangular(game_data);
    check_wall(game_data);
    position_player(game_data);
    // printf("%c\n", game_data->map_2d[game_data->x_player][game_data->y_player]);
    // printf("%d\n", game_data->x_player);
    // printf("%d\n", game_data->y_player);
}
