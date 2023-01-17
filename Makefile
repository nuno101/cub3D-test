# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 14:16:04 by jjesberg          #+#    #+#              #
#    Updated: 2023/01/17 17:45:31 by nlouro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D
VERBOSE := 1

#FIXME: use basic flags for final submission!
#FLAGS := -Wall -Wextra -Werror
FLAGS := -g -Wall -Wextra -Werror #-fsanitize=address
MINILIBX_DIR := MLX42
MINILIBX := $(MINILIBX_DIR)/libmlx42.a
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

SRC :=	cub3d.c \
		debugtools/print_all.c \
		debugtools/error.c \
		parser/init_data.c \
		parser/textures.c \
		parser/colours.c \
		parser/bools.c \
		parser/player_check.c \
		parser/wall_check.c \
		parser/player_pos.c \
		src/start_cub.c \
		src/hooks.c \
		src/keys.c \
		src/cleaner.c

OBJ_DIR := objs
OBJS = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o) ))

ifeq ($(USER), nlouro)
	LIBS :=  $(MINILIBX) $(LIBFT) -I include -lglfw -lm -L "/usr/local/Cellar/glfw/3.3.8/lib"
else
	LIBS :=  $(MINILIBX) $(LIBFT) -I include -lglfw -lm -L "/Users/$(USER)/.brew/opt/glfw/lib/"
endif

.PHONY: all libs cleanlibs clean fclean re

all: $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJS)
	gcc $(FLAGS) $(OBJS) $(LIBS) -o $@

$(OBJS): $(SRC) $(OBJ_DIR)
	gcc -c -D VERBOSE=$(VERBOSE) $(FLAGS) $(SRC) -I $(LIBFT_DIR) -I $(MINILIBX_DIR) 
	mv *.o $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libs: $(MINILIBX) $(LIBFT)

cleanlibs:
	make -C ./libft fclean
	make -C ./MLX42 fclean

$(MINILIBX):
	make -C ./MLX42

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OBJ_DIR)/*.o
	rmdir $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) $(NAME).dSYM

re: fclean all
