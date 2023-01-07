# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 14:16:04 by jjesberg          #+#    #+#              #
#    Updated: 2023/01/07 03:54:58 by jjesberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D

FLAGS := -g -Wall -Wextra -Werror -fsanitize=address
#FLAGS = -Wall -Wextra -Werror
MINILIBX_DIR = MLX42
MINILIBX = $(MINILIBX_DIR)/libmlx42.a
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =	main.c \
		debugtools/print_all.c \
		debugtools/error.c \
		parser/checks.c \
		parser/init_data.c \
		parser/init_data_helper.c \
		parser/bools.c \
		parser/colours_texture.c \

OBJ := $(SRC:.c=.o)

ifeq ($(USER), nlouro)
	LIBS :=  $(MINILIBX) $(LIBFT) -I include -lglfw -lm -L "/usr/local/Cellar/glfw/3.3.8/lib"
else
	LIBS :=  $(MINILIBX) $(LIBFT) -I include -lglfw -lm -L "/Users/$(USER)/.brew/opt/glfw/lib/"
endif

.PHONY: all libs cleanlibs clean fclean re

all: $(NAME)

$(NAME): $(MINILIBX) $(LIBFT)
	gcc $(FLAGS) $(SRC) $(LIBS) -o $@

libs: $(MINILIBX) $(LIBFT)

cleanlibs:
	make -C ./libft fclean
	make -C ./MLX42 fclean

$(MINILIBX):
	make -C ./MLX42

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME) $(NAME).dSYM

re: fclean all
