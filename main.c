/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:55:14 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/29 16:07:19 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	ff(t_list *data)
{
	check_rectangular(data);
	check_wall(data);
	position_player(data);
	valid_path(data);
	data->mlx = mlx_init();
	display_image(data);
	mlx_hook(data->win, 2, 0, key_hundle, data);
	mlx_hook(data->win, 17, 0, destroy_win, data);
	mlx_loop(data->mlx);
}

void	no_line(char *line)
{
	if (!line)
	{
		ft_putstr_fd("ERROR Empty file!\n", 2);
		exit (1);
	}
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	*map;
	char	**split_map;
	t_list	*data;

	map = NULL;
	split_map = NULL;
	fd = _error(ac, av);
	line = get_next_line(fd);
	no_line(line);
	while (line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	data = malloc(sizeof(t_list));
	var_init(data);
	data->map_1d = map;
	check_map(data);
	check_elements(data);
	split_map = splitt(map, '\n');
	data->map_2d = split_map;
	ff(data);
}
