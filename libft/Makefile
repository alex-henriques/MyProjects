# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alehenri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 13:25:44 by alehenri          #+#    #+#              #
#    Updated: 2025/07/03 10:44:33 by alehenri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

# Directories
SRCDIR = srcs
INCDIR = includes
OBJDIR = objs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files (with path)
SRCS = $(SRCDIR)/ft_isalpha.c \
       $(SRCDIR)/ft_isdigit.c \
       $(SRCDIR)/ft_isalnum.c \
       $(SRCDIR)/ft_isascii.c \
       $(SRCDIR)/ft_isprint.c \
       $(SRCDIR)/ft_strlen.c \
       $(SRCDIR)/ft_memset.c \
       $(SRCDIR)/ft_bzero.c \
       $(SRCDIR)/ft_memcpy.c \
       $(SRCDIR)/ft_memmove.c \
       $(SRCDIR)/ft_strlcpy.c \
       $(SRCDIR)/ft_strlcat.c \
       $(SRCDIR)/ft_toupper.c \
       $(SRCDIR)/ft_tolower.c \
       $(SRCDIR)/ft_strchr.c \
       $(SRCDIR)/ft_strrchr.c \
       $(SRCDIR)/ft_strcmp.c \
       $(SRCDIR)/ft_strncmp.c \
       $(SRCDIR)/ft_memchr.c \
       $(SRCDIR)/ft_memcmp.c \
       $(SRCDIR)/ft_strnstr.c \
       $(SRCDIR)/ft_atoi.c \
       $(SRCDIR)/ft_calloc.c \
       $(SRCDIR)/ft_strdup.c \
       $(SRCDIR)/ft_substr.c \
       $(SRCDIR)/ft_strjoin.c \
       $(SRCDIR)/ft_strtrim.c \
       $(SRCDIR)/ft_split.c \
       $(SRCDIR)/ft_itoa.c \
       $(SRCDIR)/ft_strmapi.c \
       $(SRCDIR)/ft_striteri.c \
       $(SRCDIR)/ft_putchar_fd.c \
       $(SRCDIR)/ft_putstr_fd.c \
       $(SRCDIR)/ft_putendl_fd.c \
       $(SRCDIR)/ft_putnbr_fd.c \
       $(SRCDIR)/ft_putchar_pf.c \
       $(SRCDIR)/ft_printf.c \
       $(SRCDIR)/ft_print_str.c \
       $(SRCDIR)/ft_print_ptr.c \
       $(SRCDIR)/ft_print_hex.c \
       $(SRCDIR)/ft_print_digit.c \
       $(SRCDIR)/ft_print_u.c \
       $(SRCDIR)/ft_lstsize.c \
       $(SRCDIR)/ft_strtok.c

# Object files (in objs directory)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)
$(NAME): $(OBJDIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "Library $(NAME) created successfully!"
$(OBJDIR):
	mkdir -p $(OBJDIR)
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJDIR)
	@echo "Object files cleaned!"
fclean: clean
	rm -f $(NAME)
	@echo "Library $(NAME) removed!"
re: fclean all
.PHONY: all clean fclean re
