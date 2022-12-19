# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 14:16:04 by jjesberg          #+#    #+#              #
#    Updated: 2022/12/19 03:17:04 by jjesberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC =	main.c \
		tools/utils.c	\
		src/error.c \
		src/init.c \
		src/map_reader.c \

OBJ = $(SRC:.c=.o)

CC = gcc -g -Wall -Wextra #-Werror

LIBS =  MLX42/libmlx42.a -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"

$(NAME):
	$(CC) $(SRC) ./libft/libft.a $(LIBS) -o $(NAME)

libs:
	make -C ./MLX42
	make -C ./libft

cleanlibs:
	make -C ./libft clean
	#make -C ./MLX42 clean

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

all: $(NAME)

re: fclean all
