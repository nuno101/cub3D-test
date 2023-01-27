# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 14:16:04 by jjesberg          #+#    #+#              #
#    Updated: 2023/01/27 12:41:17 by nlouro           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D
VERBOSE := 1

#FIXME: use basic flags for final submission!
#FLAGS := -Wall -Wextra -Werror
FLAGS := -g -Wall -Wextra -Werror -fsanitize=address
MINILIBX_DIR := MLX42
MINILIBX := $(MINILIBX_DIR)/libmlx42.a
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

SRC :=	src/cub3d.c \
		src/errors.c \
		src/cleaner.c \
		src/parser/init_data.c \
		src/parser/textures.c \
		src/parser/colours.c \
		src/parser/bools.c \
		src/parser/player_check.c \
		src/parser/wall_check.c \
		src/parser/player_pos.c \
		src/window/hooks.c \
		src/window/keys.c \
		src/window/init_cub.c \
		src/window/raycast.c \
		src/window/draw.c \

OBJ_DIR := objs
OBJS = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o) ))

ifeq ($(USER), nlouro)
	# Macbook
	LIBS :=  $(MINILIBX) $(LIBFT) -I include -lglfw -lm -L "/usr/local/Cellar/glfw/3.3.8/lib"
	# School
	#LIBS :=  $(MINILIBX) $(LIBFT) -I include -lglfw -lm -L "/goinfre/$(USER)/.brew/Cellar/glfw/3.3.8/lib/"
else
	LIBS :=  $(MINILIBX) $(LIBFT) -I include -lglfw -lm -L "/Users/$(USER)/.brew/opt/glfw/lib/"
endif

.PHONY: all libs cleanlibs clean fclean re norm

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
	make -C ./$(LIBFT_DIR) fclean
	make -C ./$(MINILIBX_DIR) fclean

$(MINILIBX):
	make -C ./$(MINILIBX_DIR)

$(LIBFT):
	make -C ./$(LIBFT_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) $(NAME).dSYM

re: fclean all

norm:
	clear
	norminette parser src include debugtools $(LIBFT_DIR) 
