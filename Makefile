# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 14:16:04 by jjesberg          #+#    #+#              #
#    Updated: 2022/11/29 00:22:57 by jjesberg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = cub3D
# SRC = *.c
# OBJ = $(SRC:.c=.o)
# CC = gcc -Wall -Wextra -Werror
# LIBS =  MLX42/libmlx42.a -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"

# $(NAME):
#     make -C ./libft
#     make -C ./MLX42
#     $(CC) $(SRC) ./libft/libft.a $(LIBS) -o $(NAME)

# clean:
#     make -C ./libft clean
#     make -C ./MLX42 clean
#     rm -f $(OBJ)

# fclean:
#     make -C ./libft fclean
#     make -C ./MLX42 fclean
#     rm -f $(NAME)

# all: $(NAME)

# re: fclean all

CC = gcc -g

CFLAGS = -Wall -Werror #-Wextra

MLX_FLAGS = MLX42/libmlx42.a -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"

NAME = cub3D
MLX_DIR = MLX42
LIBFT_DIR = libft

SRCS = 	main.c \
		src/error.c \
		src/init.c \
		src/map_reader.c \
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -sC $(MLX_DIR)
	@$(MAKE) -sC $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(MLX_DIR) -L$(LIBFT_DIR) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@$(MAKE) -sC $(MLX_DIR) clean
	@$(MAKE) -sC $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all
