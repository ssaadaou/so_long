/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:57:04 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/18 13:00:40 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_elements(t_list *game_data)
{
	int	i;
	int	count;
	int	count1;
	int	count2;
	char *map;

	i = 0;
	count = 0;
	count1 = 0;
	count2 = 0;
	map = game_data->map_1d;
	while (map[i])
	{
		if (map[i] == 'P')
			count++;
		if (map[i] == 'E')
			count1++;
		if (map[i] == 'C')
			count2++;
		i++;
	}
	if (count != 1 || count1 != 1 || count2 < 1)
	{
		free(map);
		ft_putstr_fd("Error: invalid map", 2);
		exit (1);
	}
}

void	check_map(t_list *game_data)
{
	int	i;
	char *map;
// printf("%s\n",game_data->map_1d);
//     exit (0);
	i = 0;
	map = game_data->map_1d;
	while (map[i])
	{
		if (map[i] == '1' || map[i] == '0' || map[i] == 'C'
			|| map[i] == 'P' || map[i] == 'E' || map[i] == '\n')
			i++;
		else
		{
			free(map);
			ft_putstr_fd("Error: Invalid map", 2);
			exit (1);
		}
	}
}

void position_player(t_list *game_data)
 {
    int i;
    int j ;
    char **m_2d;
    
    game_data->x_player = 0;
    game_data->y_player = 0;
    m_2d = game_data->map_2d;
    i =0;
    while(m_2d[i])
    {
        j=0;
        while (m_2d[i][j])
        {
            if(m_2d[i][j] == 'P')
            {
                game_data->x_player = i;
                game_data->y_player = j;
                return;
            }
            j++;
        }
        i++;
    }
 }

void check_path_P(t_list *game_data)
{
	char **map_2d;
	
	
}