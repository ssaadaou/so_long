/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:56:07 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/18 23:42:09 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


mlx_hook(data->win, 2, 1L<<0, keypress, data)

int	key_code(int key_code, t_list *info)
{
	if (key_code == 124 || key_code == 2)
		move_right(info);
	if (key_code == 123 || key_code == 0)
		move_left(info);
	if (key_code == 125 || key_code == 1)
		move_down(info);
	if (key_code == 126 || key_code == 13)
		move_up(info);
	if (key_code == 53)
		quit(info);
	return (0);
}

void	creat_window(char **map, t_list *info)
{
	info->y = calcul_height(info->y, map);
	info->x = calcul_width(info->x, map);
	info->mlx = mlx_init();
	pointer_image(info);
	info->mlx_win = mlx_new_window(info->mlx, info->x * 50, \
	info->y * 50, "so_long");
	mlx_loop_hook(info->mlx, &add_to_window, info);
	mlx_hook(info->mlx_win, 2, 0, &key_code, info);
	mlx_hook(info->mlx_win, 17, 0, &quit, info);
	mlx_loop(info->mlx);
}