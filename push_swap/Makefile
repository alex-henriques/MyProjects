# Compiler settings
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g3
# DEBUG   = -g3
INCLUDES = -Iincludes -Ilibft -I.  # All possible include paths

# Project structure
NAME    = push_swap
SRC_DIR = .
OBJ_DIR = obj
LIBFT   = libft/libft.a

# Source files
SRCS = \
		error.c \
		main.c \
		parsing.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		radix_sort.c \
		small_sort.c \
		utils.c

OBJS = $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.c=.o)))

# Build rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Build successful!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJ_DIR)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
