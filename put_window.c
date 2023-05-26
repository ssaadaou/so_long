/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:56:40 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/26 02:24:54 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void *display_game_elements(t_list *data, char **map)
{
    int i =0;
    int j= 0;

    // data->mlx = mlx_init();
    while(data->map_2d[i])
    {
       
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'P')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->space,j*50 , i*50);
                mlx_put_image_to_window(data->mlx, data->win, data->player, j*50, i*50);
            }
            if(map[i][j] == 'C')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->space,j*50 , i*50);   
                mlx_put_image_to_window(data->mlx, data->win, data->coin, j*50, i*50);
            }
            if(map[i][j] == 'E')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->space,j*50 , i*50);
                mlx_put_image_to_window(data->mlx, data->win, data->gate,j*50 , i*50);
            }
            if(map[i][j] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->space,j*50 , i*50);
            if(map[i][j] == '1')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->wall,j*50 , i*50);   

                
            }
            j++;
        }
        i++;
    }
    return NULL;
}
void moves(t_list *data , int x, int y)
{
     if (data->map_2d[data->x_player+x][data->y_player + y] == '1')
        return ;
    if (data->map_2d[data->x_player+x][data->y_player + y] == 'E' && data->count_C != 0)
        return ;
    if(data->map_2d[data->x_player+x][data->y_player + y] == 'C')
    {
        data->count_C -= 1;
        data->map_2d[data->x_player][data->y_player] = '0';
        data->map_2d[data->x_player+x][data->y_player + y] = 'P';
    }
    else if (data->map_2d[data->x_player+x][data->y_player + y] == 'E' && data->count_C == 0)
    {
        ft_putstr_fd("\n\nyou are a winner\n", 1);
        mlx_destroy_window(data->mlx, data->win);
        exit(1);
    }
    else
    {
        data->map_2d[data->x_player][data->y_player] = '0';
        data->map_2d[data->x_player+x][data->y_player + y] = 'P';
        
    }
    data->count_move += 1;
    ft_putstr_fd("\nMouvements -->> ", 1);
    ft_putnbr_fd(data->count_move, 1);
    data->y_player += y; 
    data->x_player += x;  
    display_game_elements(data, data->map_2d);

        

}


int key_hundle(int key,t_list *data)
{
    
    // int key;
    if(key == 13 || key == 126)    // move_up(data);
        moves(data, -1 , 0);
    else if(key == 1 || key == 125) //move_down(data);
        moves(data, +1 , 0);
    else if(key == 0 || key == 123)  //move_left(data);
        moves(data, 0 , -1);
    else if (key == 2 || key == 124) // move_right(data);
        moves(data, 0 , +1);
    else if (key == 53)
        mlx_destroy_window(data->mlx, data->win); 
   return 0; 
}
