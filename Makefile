# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 14:16:04 by jjesberg          #+#    #+#              #
#    Updated: 2023/01/06 22:18:47 by nlouro           ###   ########.fr        #
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
		tools/render.c \
		src/start_cub.c \
		src/keys.c \

OBJ = $(SRC:.c=.o)

CC = gcc -g -Wall -Wextra -Werror

ifeq ($(USER), nlouro)
	LIBS :=  MLX42/libmlx42.a ./libft/libft.a -I include -lglfw -lm -L "/usr/local/Cellar/glfw/3.3.8/lib"
else
	LIBS :=  MLX42/libmlx42.a ./libft/libft.a -I include -lglfw -lm -L "/Users/$(USER)/.brew/opt/glfw/lib/"
endif

all: $(NAME)

$(NAME):
	$(CC) $(SRC) $(LIBS) -o $(NAME)

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
