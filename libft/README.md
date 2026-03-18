# libft

libft is a custom C library that re-implements a subset of the standard C library, along with additional utility functions used across 42 projects. It also includes a built-in `ft_printf`

## Build

```bash
make
```

This produces `libft.a`, a static library you can link against.

## Usage

Copy the `libft/` folder into your project and link it at compile time:
```bash
cc main.c -Ilibft/includes -Llibft -lft -o my_program
```

## Functions

**Character checks** — `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
 
**Character conversion** — `ft_toupper`, `ft_tolower`
 
**String** — `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strcmp`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_strlcpy`, `ft_strlcat`, `ft_strncpy`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`, `ft_strtok`
 
**Memory** — `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
 
**Conversion** — `ft_atoi`, `ft_atol`, `ft_itoa`
 
**Output (fd)** — `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
 
**ft_printf** — `ft_printf` with support for `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`
 
**Linked list** — `ft_lstsize`

## Project Structure

```
libft/
├── includes/
│   └── libft.h
├── srcs/
│   └── ft_*.c
└── Makefile
```
