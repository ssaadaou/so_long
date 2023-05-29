/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:56:40 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/29 16:08:05 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_image(t_list *data, void *image, int i, int j)
{
	mlx_put_image_to_window (data->mlx, data->win, data->space, j * 50, i * 50);
	mlx_put_image_to_window (data->mlx, data->win, image, j * 50, i * 50);
}

void	display_game_elements(t_list *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_2d[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				handle_image(data, data->player, i, j);
			if (map[i][j] == 'C')
				handle_image(data, data->coin, i, j);
			if (map[i][j] == 'E')
				handle_image(data, data->gate, i, j);
			if (map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->space, \
				j * 50, i * 50);
			if (map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, \
					data->wall, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	handle_movement(t_list *data, int x, int y)
{
	data->map_2d[data->x_player][data->y_player] = '0';
	data ->map_2d[data->x_player + x][data->y_player + y] = 'P';
}

void	moves(t_list *data, int x, int y)
{
	if (data->map_2d[data->x_player + x][data->y_player + y] == '1' ||
		(data->map_2d[data->x_player + x][data->y_player + y] == 'E' \
		&& data->count_C != 0))
		return ;
	if (data->map_2d[data->x_player + x][data->y_player + y] == 'C')
	{
		data->count_C -= 1;
		handle_movement(data, x, y);
	}
	else if (data->map_2d[data->x_player + x][data->y_player + y] == 'E' \
	&& data->count_C == 0)
	{
		ft_putstr_fd("\n\nyou are a winner\n", 1);
		exit(1);
	}
	else
		handle_movement(data, x, y);
	count_moves(data);
	data->y_player += y;
	data->x_player += x;
	display_game_elements(data, data->map_2d);
}

void	count_moves(t_list *data)
{
	data->count_move += 1;
	ft_putstr_fd("\nMouvements -->> ", 1);
	ft_putnbr_fd(data->count_move, 1);
}
