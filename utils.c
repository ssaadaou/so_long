/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:55:47 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/28 01:00:43 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
int ft_strlen_lines(char **map_2d)
{
	int i = 0;
	while(map_2d[i])
		i++;
	return (i);
}
void	ft_putnbr_fd(int nbr, int fd)
{
	if(nbr < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd((nbr * -1), fd);	
	}
	if(nbr >= 0 && nbr < 10)
	{
		ft_putchar_fd((nbr + '0'), fd);
	}
	if(nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10,fd);
	}
}
void my_free(char **map) 
{
    int i = 0;
    while(map[i]) 
	{
        free(map[i]);
        i++;
    }
    free(map);
}
// int main()
// {
// 	int fd = open("test.txt", O_RDWR);
// 	if (fd =0)
// 	{
// 		puts("here");
// 		return 0;
// 	}
// 	ft_putnbr_fd(-23984998999999999999, fd);
//}