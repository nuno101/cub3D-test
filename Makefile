# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjesberg <j.jesberger@heilbronn.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 14:16:04 by jjesberg          #+#    #+#              #
#    Updated: 2023/01/04 16:55:06 by jjesberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC =	main.c \
		debugtools/print_all.c \
		tools/utils.c	\
		tools/bools.c	\
		tools/bools_map.c	\
		tools/save.c	\
		src/error.c \
		src/init.c \
		src/valid.c	\
		src/map_reader.c \
		src/start_cub.c \

OBJ = $(SRC:.c=.o)

CC = gcc -g -Wall -Wextra #-Werror

LIBS =  MLX42/libmlx42.a -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"

all: $(NAME)

$(NAME):
	$(CC) $(SRC) ./libft/libft.a $(LIBS) -o $(NAME)

libs:
	make -C ./MLX42
	make -C ./libft

cleanlibs:
	make -C ./libft fclean
	make -C ./MLX42 fclean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
