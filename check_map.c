/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:57:15 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/16 19:21:53 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	check_rectangular(t_list *game_data)
{
	int len;
	int i = 0;
	char **m_2d= game_data->map_2d;
	len = ft_strlen(game_data->map_2d[0]);
	while(m_2d[i])
	{
		// printf("%d\n", i);
		// printf("%d\n", len);
		if(len != ft_strlen(m_2d[i]))
		{
			ft_putstr_fd("Error: Map is not rectangular",2);
				exit(1);
		}
		i++;
	}
	
}
// void check_top_wall(t_list *game_data)
// {
// 	int i = 0;
// 	while(game_data->map_2d[0][i])
// 	{
// 		if(game_data->map_2d[0][i] != '1')
// 		{
// 		}
// 		i++;
// 	}
// }

// void	check_bottom_wall(t_list *game_data)
// {
	
// 	while()
// }
void	check_wall(t_list *game_data)
{
	int len_col;
	int len_lines;
	int i = 0;
	int j ;

	len_lines = ft_strlen_lines(game_data->map_2d);
	len_col = ft_strlen(game_data->map_2d[0]);
	while (i < len_lines)
	{
		j = 0;
		while(j < len_col)
		{
			if((i == 0 || i == len_lines - 1 || j == 0 || j == len_col - 1 ) && game_data->map_2d[i][j] != '1')
			{
				ft_putstr_fd("Error: wall is not valid", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
	
}

