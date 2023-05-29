/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:57:04 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/29 16:07:49 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position_player(t_list *data)
{
	int		i;
	int		j;
	char	**m_2d;

	m_2d = data->map_2d;
	i = 0;
	while (m_2d[i])
	{
		j = 0;
		while (m_2d[i][j])
		{
			if (m_2d[i][j] == 'P')
			{
				data->x_player = i;
				data->y_player = j;
			}
			else if (m_2d[i][j] == 'C')
				data->count_c += 1;
			j++;
		}
		i++;
	}
}

void	var_init(t_list *data)
{
	data->count_c = 0;
	data->count_move = 0;
	data->x_player = 0;
	data->y_player = 0;
	data->width = 0;
	data->height = 0;
	data->w_coin = 0;
	data->w_player = 0;
	data->w_wall = 0;
	data->w_space = 0;
	data->w_gate = 0;
	data->h_coin = 0;
	data->h_player = 0;
	data->h_wall = 0;
	data->h_space = 0;
	data->h_gate = 0;
	var_init_s(data);
}

void	var_init_s(t_list *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->player = NULL;
	data->wall = NULL;
	data->coin = NULL;
	data->gate = NULL;
	data->space = NULL;
	data->map = NULL;
	data->map_1d = NULL;
	data->map_2d = NULL;
}
