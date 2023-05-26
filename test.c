/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:39:28 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/26 01:35:09 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void move_d(t_list *data)
{
    if (data->map_2d[data->x_player][data->y_player+1] == 'E' && data->count_C != 0)
        return ;
    if(data->map_2d[data->x_player][data->y_player+1] == 'C')
    {
        // puts("here");
        data->count_C -= 1;
        data->map_2d[data->x_player][data->y_player] = '0';
        data->map_2d[data->x_player][data->y_player +1] = 'P';

        
    }
    else if (data->map_2d[data->x_player][data->y_player+1] == 'E' && data->count_C == 0)
    {
        ft_putstr_fd("you are a winner\n", 1);
        mlx_destroy_window(data->mlx, data->win);
        exit(1);
    }
    else
    {
        data->map_2d[data->x_player][data->y_player] = '0';
        data->map_2d[data->x_player][data->y_player +1] = 'P';
        
    }
    data->count_move += 1;
    ft_putstr_fd("\nMouvements -->> ", 1);
    ft_putnbr_fd(data->count_move, 1);
    // data->y_player += 1; 
}
void move_right(t_list *data)
{
    if(data->map_2d[data->x_player][data->y_player+1] != '1')
        move_d(data);
}
void move_upp(t_list *data)
{
    if (data->map_2d[data->x_player -1][data->y_player] == 'E' && data->count_C != 0)
        return ;
    if(data->map_2d[data->x_player -1][data->y_player] == 'C')
    {
        data->count_C -= 1;
        data->map_2d[data->x_player][data->y_player] = '0';
        data->map_2d[data->x_player -1][data->y_player] = 'P';
        
    }
    if (data->map_2d[data->x_player -1][data->y_player] == 'E' && data->count_C == 0)
    {
        ft_putstr_fd("you are a winner\n", 1);
        mlx_destroy_window(data->mlx, data->win);
        exit(1);
    }
    else
    {
        data->map_2d[data->x_player][data->y_player] = '0';
        data->map_2d[data->x_player -1][data->y_player] = 'P';
    }
    data->count_move += 1;
    ft_putstr_fd("\nMouvements -->> ", 1);
    ft_putnbr_fd(data->count_move, 1);
    // mlx_clear_window(data->mlx, data->win);
    // data->x_player -= 1; 
}

void move_up(t_list *data)
{
    if(data->map_2d[data->x_player-1][data->y_player] != '1')
        move_upp(data);
}