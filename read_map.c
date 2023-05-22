/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:01:25 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/14 18:18:33 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_strchr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
int	check_line(char *buffer)
{
	int i = 0;
	int count= 0;
	while(*buffer)
	{
		if(ft_strchr(buffer))
			count += 1;
		else if (*buffer != '\0')

	}

}
int read_map(const char *file, int *line, int *column)
{
	int fd;
	char *buffer;
	int c;

	int fd = open(file, O_RDONLY);
	if (fd == -1)
		return 0;
	while(1)
	{
		c = read(fd, buffer, BUFFER_SIZE);
		if (c < 0)
			return 0;
		
	}
}