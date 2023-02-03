# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 14:16:04 by jjesberg          #+#    #+#              #
#    Updated: 2023/02/03 15:27:52 by nlouro           ###   ########.fr        #
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
		src/parser/init_data.c \
		src/parser/textures.c \
		src/parser/colours.c \
		src/parser/bools.c \
		src/parser/player_check.c \
		src/parser/wall_check.c \
		src/parser/player_pos.c \
		src/window/event_handlers.c \
		src/window/init_cub.c \
		src/window/raycast.c \
		src/window/draw.c \

OBJ_DIR := objs
OBJS = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o) ))

#FIXME: remove this statement before submitting
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
	@echo "\033[32mLinking object files...\033[0m"
	gcc $(FLAGS) $(OBJS) $(LIBS) -o $@

o: $(OBJS)
$(OBJS): $(SRC) $(OBJ_DIR)
	@echo "\033[34mCompiling source code...\033[0m"
	gcc -c -D VERBOSE=$(VERBOSE) $(FLAGS) $(SRC) -I $(LIBFT_DIR) -I $(MINILIBX_DIR) 
	mv *.o $(OBJ_DIR)

$(OBJ_DIR):
	@echo "\033[34mCreate objects placeholder directory objs/\033[0m"
	mkdir -p $(OBJ_DIR)

libs: $(MINILIBX) $(LIBFT)

cleanlibs:
	make -C ./$(LIBFT_DIR) fclean
	make -C ./$(MINILIBX_DIR) fclean

$(MINILIBX):
	make -C ./$(MINILIBX_DIR)
	#NOTE: for debugging use:
	#make DEBUG=1 -C ./$(MINILIBX_DIR)

$(LIBFT):
	make -C ./$(LIBFT_DIR)

clean:
	@echo "\033[33mRemoving object files & directory...\033[0m"
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\033[33mRemoving executable...\033[0m"
	rm -rf $(NAME) $(NAME).dSYM

re: fclean all

norm:
	clear
	norminette src include $(LIBFT_DIR) 
