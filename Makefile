# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 14:16:04 by jjesberg          #+#    #+#              #
#    Updated: 2023/01/04 23:05:58 by jjesberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC =	main.c \
		debugtools/print_all.c \
		init/save_map.c	\
		init/save_map_data.c	\
		init/init.c \
		init/bools_map.c	\
		init/valid_map.c	\
		init/valid_map_helper.c	\
		tools/utils.c	\
		tools/error.c \
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
