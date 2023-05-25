/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:56:07 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/25 18:06:35 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_upp(t_list *data)
{
    if (data->map_2d[data->x_player -1][data->y_player] == 'E' && data->count_C != 0)
        return ;
    if(data->map_2d[data->x_player -1][data->y_player] == 'C')
        data->count_C -= 1;
    data->map_2d[data->x_player][data->y_player] = '0';
    if (data->map_2d[data->x_player -1][data->y_player] == 'E' && data->count_C == 0)
    {
        ft_putstr_fd("you are a winner\n", 1);
        mlx_destroy_window(data->mlx, data->win);
        exit(1);
    }
    data->map_2d[data->x_player -1][data->y_player] = 'P';
    data->count_move += 1;
    ft_putstr_fd("Mouvements -->> ", 1);
    ft_putnbr_fd(data->count_move, 1);
    mlx_clear_window(data->mlx, data->win);
    data->x_player -= 1; 
}

void move_up(t_list *data)
{
    if(data->map_2d[data->x_player-1][data->y_player] != '1')
        move_upp(data);
}

void move_dwn(t_list *data)
{
    if (data->map_2d[data->x_player -1][data->y_player] == 'E' && data->count_C != 0)
        return ;
    if(data->map_2d[data->x_player -1][data->y_player] == 'C')
        data->count_C -= 1;
    data->map_2d[data->x_player][data->y_player] = '0';
    if (data->map_2d[data->x_player -1][data->y_player] == 'E' && data->count_C == 0)
    {
        ft_putstr_fd("you are a winner\n", 1);
        mlx_destroy_window(data->mlx, data->win);
        exit(1);
    }
    data->map_2d[data->x_player -1][data->y_player] = 'P';
    data->count_move += 1;
    ft_putstr_fd("Mouvements -->> ", 1);
    ft_putnbr_fd(data->count_move, 1);
    mlx_clear_window(data->mlx, data->win);
    data->x_player -= 1; 
}

void move_down(t_list *data)
{
    if(data->map_2d[data->x_player-1][data->y_player] != '1')
        move_dwn(data);
}
//////
void move_a(t_list *data)
{
    if (data->map_2d[data->x_player][data->y_player-1] == 'E' && data->count_C != 0)
        return ;
    if(data->map_2d[data->x_player][data->y_player-1] == 'C')
        data->count_C -= 1;
    data->map_2d[data->x_player][data->y_player-1] = '0';
    if (data->map_2d[data->x_player][data->y_player-1] == 'E' && data->count_C == 0)
    {
        ft_putstr_fd("you are a winner\n", 1);
        mlx_destroy_window(data->mlx, data->win);
        exit(1);
    }
    data->map_2d[data->x_player][data->y_player -1] = 'P';
    data->count_move += 1;
    ft_putstr_fd("Mouvements -->> ", 1);
    ft_putnbr_fd(data->count_move, 1);
    mlx_clear_window(data->mlx, data->win);
    data->x_player -= 1; 
}

void move_left(t_list *data)
{
    if(data->map_2d[data->x_player][data->y_player-1] != '1')
        move_a(data);
}

void move_d(t_list *data)
{
    if (data->map_2d[data->x_player][data->y_player+1] == 'E' && data->count_C != 0)
        return ;
    if(data->map_2d[data->x_player][data->y_player+1] == 'C')
        data->count_C -= 1;
    data->map_2d[data->x_player][data->y_player+1] = '0';
    if (data->map_2d[data->x_player][data->y_player+1] == 'E' && data->count_C == 0)
    {
        ft_putstr_fd("you are a winner\n", 1);
        mlx_destroy_window(data->mlx, data->win);
        exit(1);
    }
    data->map_2d[data->x_player][data->y_player +1] = 'P';
    data->count_move += 1;
    ft_putstr_fd("Mouvements -->> ", 1);
    ft_putnbr_fd(data->count_move, 1);
    mlx_clear_window(data->mlx, data->win);
    data->x_player -= 1; 
}

void move_right(t_list *data)
{
    if(data->map_2d[data->x_player][data->y_player+1] != '1')
        move_d(data);
}