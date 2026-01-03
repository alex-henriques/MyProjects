NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -Iincludes
DEBUG = -g3

SRCDIR = src
OBJDIR = obj
INCDIR = includes
INCLUDES = -I$(INCDIR) -I

SRC =   actions.c \
		cleanup.c \
		init.c \
		main.c \
		monitor.c \
		parse.c \
		routine.c \
		time_utils.c \
		utils.c

FULL_SRC = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
CYAN = \033[0;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)Compiling $(NAME)...$(RESET)"
	@echo "$(BLUE)Linking objects...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilation complete!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(CYAN)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@echo "$(CYAN)Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Full clean...$(RESET)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re