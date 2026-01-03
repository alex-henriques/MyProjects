CLIENT_SRC = client.c
SERVER_SRC  = server.c
CLIENT = client
SERVER = server
OBJ_DIR = obj
C_OBJ = $(addprefix $(OBJ_DIR)/, $(CLIENT_SRC:.c=.o))
S_OBJ = $(addprefix $(OBJ_DIR)/, $(SERVER_SRC:.c=.o))
RM            = rm -rf
CC            = cc
AR            = ar -crs
FLAGS         = -Wall -Wextra -Werror
LIBFT_PATH    = ./libft
LIBFT         = $(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -I$(LIBFT_PATH) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ_DIR) $(C_OBJ) $(S_OBJ)

all: $(LIBFT) client server

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

client: $(LIBFT) $(OBJ_DIR) $(C_OBJ)
	$(CC) $(FLAGS) -o $(CLIENT) $(C_OBJ) -I$(LIBFT_PATH) -L$(LIBFT_PATH) -lft

server: $(LIBFT) $(OBJ_DIR) $(S_OBJ)
	$(CC) $(FLAGS) -o $(SERVER) $(S_OBJ) -I$(LIBFT_PATH) -L$(LIBFT_PATH) -lft

re: fclean all


clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	make -C $(LIBFT_PATH) fclean

.PHONY: all clean fclean re
