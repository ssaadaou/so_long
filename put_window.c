/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:56:40 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/22 23:37:48 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void *display_game_elements(t_list *data, char **map)
{
    int i =0;
    int j= 0;

    data->mlx = mlx_init();
    while(data->map_2d[i])
    {
        i++;
    }
        data->win = mlx_new_window(data->mlx ,ft_strlen(data->map_2d[0]) * 50 ,  i * 50 , "window");
        data->coin = mlx_xpm_file_to_image(data->mlx, "image_coin.xpm", &data->width, &data->height);
        data->player = mlx_xpm_file_to_image(data->mlx, "image_player.xpm",&data->width ,&data->height);
        data->wall = mlx_xpm_file_to_image(data->mlx, "brick-wall.xpm", &data->width, &data->height);
        data->space = mlx_xpm_file_to_image(data->mlx, "image_room.xpm", &data->width, &data->height);
        data->gate = mlx_xpm_file_to_image(data->mlx, "image_gate.xpm",&data->width, &data->height);
    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'P')
                mlx_put_image_to_window(data->mlx, data->win, data->player, j*50, i*50);
            if(map[i][j] == 'C')
                mlx_put_image_to_window(data->mlx, data->win, data->coin, j*50, i*50);
            if(map[i][j] == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->gate,j*50 , i*50);
            if(map[i][j] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->space,j*50 , i*50);
            if(map[i][j] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->wall,j*50 , i*50);   
            j++;
        }
        i++;
    }
    mlx_loop(data->mlx);
    mlx_hook(data->win, 2, 1L<<0, keypress, data);
    return NULL;
}