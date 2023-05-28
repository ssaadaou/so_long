/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:57:56 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/05/28 02:03:19 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_list
{
    char *map;
    char *map_1d;
    char **map_2d;
    int x_player;
    int y_player;
    void *mlx;
    void *win;
    void *player;
    void *wall;
    void *coin;
    void *gate;
    void *space;
    int width;
    int height;
    int count_C;
    int count_move;
} t_list;

// char	*ft_strdup(const char *src);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int nbr, int fd);
int     ft_strlen(char *s);
int     _error(int ac, char **av);
char    **splitt(char *s, char c);
void	check_elements(t_list *game_data);
void	check_map(t_list *game_data);
int	    _free(char **res);
void	check_rectangular(t_list *game_data);
int     ft_strlen_lines(char **map_2d);
void	check_wall(t_list *game_data);
void    position_player(t_list *game_data);
void    *display_game_elements(t_list *game_data, char **map);
int    key_hundle(int key ,t_list *data);
void    display_image(t_list *data);
// void    ff(t_list *data);
void var_init(t_list *data);
void moves(t_list *data , int x, int y);
void destroy_win(t_list *data);
void check_path(struct t_list *data, int base) ;

#endif