/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:55:14 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/28 19:32:00 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void ff(t_list *data)
{
    check_rectangular(data);
    check_wall(data);
    position_player(data);
    valid_path(data);
    data->mlx = mlx_init();
    display_image(data);
    mlx_hook(data->win,2,0, key_hundle, data);
    mlx_hook(info->mlx_win, 17, 0, destroy_win, data);
    mlx_loop(data->mlx);
}
int main (int ac, char **av)
{
    int fd;
    char *line;
    char *map = NULL;
    char **split_map = NULL;
    t_list *data;
    fd = _error(ac , av);
    line = get_next_line(fd);
    while (line)
    {
        map = ft_strjoin(map , line);
        free(line);
        line = get_next_line(fd);
    }
    data = malloc(sizeof(t_list));
    var_init(data);
    data->map_1d = map;
    check_map(data);
    check_elements(data);
    split_map = splitt(map, '\n');
    data->map_2d = split_map;
    ff(data);
    _free(split_map);
    _free(data->map_2d);
    free(data->map_1d);
}
