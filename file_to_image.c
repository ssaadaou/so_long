/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:55:40 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/26 16:23:37 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    display_image(t_list *data)
{
    int i = 0;
    while(data->map_2d[i])
    {
        i++;
    }
    data->win = mlx_new_window(data->mlx ,ft_strlen(data->map_2d[0]) * 50 ,  i * 50 , "window");
    data->coin = mlx_xpm_file_to_image(data->mlx, "image_fruit.xpm", &data->width, &data->height);
    data->player = mlx_xpm_file_to_image(data->mlx, "image_player.xpm",&data->width ,&data->height);
    data->wall = mlx_xpm_file_to_image(data->mlx, "image_texture.xpm", &data->width, &data->height);
    data->space = mlx_xpm_file_to_image(data->mlx, "image_grass_space.xpm", &data->width, &data->height);
    data->gate = mlx_xpm_file_to_image(data->mlx, "elf_door.xpm",&data->width, &data->height);   
    display_game_elements(data, data->map_2d);
}
 
 int key_hundle(int key,t_list *data)
{
    
    
    if(key == 13 || key == 126)    
          moves(data, -1 , 0);
    else if(key == 1 || key == 125)
            moves(data, 1 , 0);
    else if(key == 0 || key == 123) 
            moves(data, 0 , -1);
    else if (key == 2 || key == 124) 
        moves(data, 0 , 1);
    else if (key == 53)
    {
        mlx_destroy_window(data->mlx, data->win); 
        exit (0);
        return 0;
    }
   return 0; 
}
