# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 14:16:04 by jjesberg          #+#    #+#              #
#    Updated: 2022/11/27 17:09:33 by ezpiro-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
