# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 17:55:55 by ssaadaou          #+#    #+#              #
#    Updated: 2023/05/16 19:20:47 by ssaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBRARY = so_long.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = main.c utils.c get_next_line.c get_next_line_utils.c \
	checking_errors.c split.c check_map.c checking_elements.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o : %.c $(LIBRARY)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all