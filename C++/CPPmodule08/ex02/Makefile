NAME =  MutatedAbomination

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"\

%.o: %.cpp
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(RED)Done...$(RESET)"

re: fclean all
	@echo "$(BLUE)Rebuild complete!$(RESET)"

.PHONY: all clean fclean re