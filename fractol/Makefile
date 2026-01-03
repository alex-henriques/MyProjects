# Minilibx Paths
MLX_DIR   = ./minilibx-linux
MLX_LIB   = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Compiler settings
CC       = gcc
CFLAGS   = -Wall -Wextra -Werror
DEBUG    = -g3
INCLUDES = -I. -Ilibft -Iincludes -I$(MLX_DIR)

# Project 
NAME     = fractol
OBJ_DIR  = obj
LIBFT    = libft/libft.a

# Source files
SRCS = \
	complex.c \
	events.c \
	events2.c \
	fractal_sets.c \
	fractol.c \
	initialisation.c \
	render.c \
	utils.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "Build successful!"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C libft

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C libft clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
