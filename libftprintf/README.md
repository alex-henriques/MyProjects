# ft_printf

ft_printf is a C library that reimplements a subset of the standard `printf` function, compiled as a static archive (`libftprintf.a`).

## Build

```bash
make
```
This produces `libftprintf.a`.

## Usage

Link the library into your project and include the header:
```c
#include "ft_printf.h"

ft_printf("Hello, %s! You are %d years old.\n", "world", 42);
ft_printf("Pointer: %p | Hex: %x | Unsigned: %u\n", ptr, 255, 255);
```
`ft_printf` returns the number of characters written, just like the standard `print_f`.

## Supported Conversions
 
| Specifier | Description |
|-----------|-------------|
| `%c` | Single character |
| `%s` | String (`(null)` if NULL) |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` / `%X` | Unsigned hexadecimal (lower / upper case) |
| `%p` | Pointer address (`(nil)` if NULL) |
| `%%` | Literal `%` |

## Project Structure

```
ft_printf/
├── ft_printf.c         # Core dispatcher, format string parser
├── ft_printf.h         # Header and prototypes
├── ft_putchar_fd.c     # Write a single character to a fd
├── ft_print_str.c      # %s
├── ft_print_digit.c    # %d / %i
├── ft_print_u.c        # %u
├── ft_print_hex.c      # %x / %X
├── ft_print_ptr.c      # %p
└── Makefile
```
