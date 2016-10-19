#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgeslin  <jgeslin@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 12:36:55 by jgeslin           #+#    #+#              #
#    Updated: 2016/10/19 15:24:14 by gvilmont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = ./srcs/ft_do.c ./srcs/ft_init.c ./srcs/ft_put_pixel.c\
	  ./srcs/main.c ./srcs/ft_putintab.c ./srcs/ft_move.c\
	  ./srcs/ft_tools.c\

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIBS = libft/libft.a

GNL = libft/sources/get_next_line.c

FLAGMLX = -lmlx -framework Opengl -framework AppKit

all: $(NAME)

$(NAME):$(OBJ)
			make -C ./libft/
			gcc $(FLAG) -o $(NAME) $(FLAGMLX) $(GNL) $(SRC) $(LIBS) -I.

clean:
			make clean -C ./libft/
			/bin/rm -f $(OBJ)

fclean: clean
		make fclean -C ./libft/
		/bin/rm -f $(NAME)

re:fclean all

.PHONY: clean fclean re all
