CLR := test_colours
VERBOSE := 1

C_FLAGS := -g -Wall -Wextra -Werror -fsanitize=address
#MINILIBX_DIR := MLX42
#MINILIBX := $(MINILIBX_DIR)/libmlx42.a
LIBFT_DIR := ../libft
LIBFT := $(LIBFT_DIR)/libft.a

CLR_C_FILES := test_colours.c ../src/parser/colours.c

CLR_O_FILES = $(notdir $(CLR_C_FILES:%.c=%.o) )

#OBJ_DIR := objs
#OBJS = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o) ))

#ifeq ($(USER), nlouro)
#	LIBS :=  $(MINILIBX) $(LIBFT) -I include -lglfw -lm -L "/usr/local/Cellar/glfw/3.3.8/lib"
#else
#	LIBS :=  $(MINILIBX) $(LIBFT) -I include -lglfw -lm -L "/Users/$(USER)/.brew/opt/glfw/lib/"
#endif

.PHONY: all libs cleanlibft clean fclean re

all: $(CLR)

tc: $(CLR)
	./$(CLR)

$(CLR): $(CLR_O_FILES) $(LIBFT)
	gcc $(C_FLAGS) $(CLR_O_FILES) $(LIBFT) -o $@

$(CLR_O_FILES): $(CLR_C_FILES)
	gcc -c -D VERBOSE=$(VERBOSE) $(C_FLAGS) $(CLR_C_FILES) -I $(LIBFT_DIR)

cleanlibft:
	make -C ../libft fclean

#$(MINILIBX):
#	make -C ./MLX42

$(LIBFT):
	make -C ../libft

libft: $(LIBFT)

clean:
	rm -f *.o

fclean: clean
	rm -rf $(CLR)

re: fclean all
