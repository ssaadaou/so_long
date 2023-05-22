/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:57:29 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/14 18:51:04 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count_split(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && c != s[i])
			i++;
		while (c && c == s[i])
			i++;
		count++;
	}
	return (count);
}

static int	ft_count_word(char *s, char c)
{
	int	count;

	count = 0;
	while (*s && c != *s)
	{
		count++;
		s++;
	}
	return (count);
}

static char	*ft_word(char *s, char c, char **word)
{
	int	count;
	int	i;

	count = ft_count_word(s, c);
	*word = malloc((count + 1) * sizeof(char));
	if (!word)
		return (NULL);
	(*word)[count] = '\0';
	i = 0;
	while (i < count)
		(*word)[i++] = *s++;
	while (c == *s)
		s++;
	return (s);
}

int	_free(char **res)
{
	int i = 0;
	
	while (res[i])
	{
		free(res[i]);
		res[i] = NULL;
		i++;
	}
	free(res);
	res = NULL;
	return (0);
}

char **splitt(char *s, char c)
{
    int		i;
	int		count;
	char	**res;

	if (!s)
		return (NULL);
	i = 0;
	while (*s && c == (char)*s)
		s++;
	count = ft_count_split((char *)s, c);
	res = malloc((count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[count] = NULL;
	i = 0;
	while (i < count)
	{
		s = ft_word((char *)s, c, res + i);
		if (!s)
			return (_free(res), NULL);
		i++;
	}
	return (res);
}