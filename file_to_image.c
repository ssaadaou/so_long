/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:55:40 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/28 23:53:49 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_image(t_list *data)
{
	int	i;

	i = 0;
	while (data->map_2d[i])
	{
		i++;
	}
	data->win = mlx_new_window(data-> mlx, ft_strlen(data->map_2d[0]) \
	* 50, i * 50, "so_long");
	data->coin = mlx_xpm_file_to_image(data->mlx, "image_fruit.xpm", \
	&data->w_coin, &data->h_coin);
	data->player = mlx_xpm_file_to_image(data->mlx, "image_player.xpm", \
	&data->w_player, &data->h_player);
	data->wall = mlx_xpm_file_to_image(data->mlx, "image_texture.xpm", \
	&data->w_wall, &data->h_wall);
	data->space = mlx_xpm_file_to_image(data->mlx, "image_grass_space.xpm", \
	&data->w_space, &data->h_space);
	data->gate = mlx_xpm_file_to_image(data->mlx, "elf_door.xpm",&data->w_gate, \
	&data->h_gate);
	if (!data->wall || !data->space || !data->player || !data->coin \
		|| !data->gate)
	{
		ft_putstr_fd("Error XPM file", 2);
		exit (1);
	}
	display_game_elements(data, data->map_2d);
}

int	key_hundle(int key, t_list *data)
{
	if (key == 13 || key == 126)
		moves (data, -1, 0);
	else if (key == 1 || key == 125)
		moves(data, 1, 0);
	else if (key == 0 || key == 123)
		moves(data, 0, -1);
	else if (key == 2 || key == 124)
		moves(data, 0, 1);
	else if (key == 53)
		exit (0);
	return (0);
}

int	destroy_win(int key, t_list *data)
{
	(void)key;
	(void)data;
	exit (0);
	return (0);
}
