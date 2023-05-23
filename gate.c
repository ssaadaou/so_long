/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gate.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:51:10 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/23 14:51:22 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_path(t_list *info, int base)
{
	char	**map;

	map = ft_split(info->map1d, '\n');
	floodfill(map, info->player1.y, info->player1.x, base);
	if (base == 'C')
	{
		if (check_exist(map, base))
		{
			my_free(map);
			ft_putstr_fd("ERROR!There is no valid path \
			to catch all collectibles.\n", 2);
			exit (1);
		}
	}
	if (base == 'E')
	{
		if (check_exist(map, base))
		{
			my_free(map);
			ft_putstr_fd("ERROR!There is no valid path to go the exit.\n", 2);
			exit (1);
		}
	}
	my_free(map);
}
