# get_next_line

get_next_line is a C function that reads a single line at a time from a file descriptor, retaining leftover content between calls via a static buffer.

## Usage 

Add the files to your project and compile with a `BUFFER_SIZE` definition:

```bash
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o my_program
```

```c
#include "get_next_line.h"

int fd = open("file.txt", O_RDONLY);
char    *line;

while((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

Each call returns the next line including the training `\n`, or `NULL` on EOF(end of file)  or error. The returned string must be freed by the caller.

`BUFFER_SIZE` can be overriden at compile time to tune read performance:

```bash
cc -D BUFFER_SIZE=4096 ...
```

## Bonus

The bonus version supports reading from multiple file descriptors simultaneously (up to `MAX_FD 1024`) by using a static array of leftover buffers indexed by `fd`.

```bash
cc -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o my_program
```

## Project Structure

```
get_next_line/
├── get_next_line.h
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line_bonus.h
├── get_next_line_bonus.c
└── get_next_line_utils_bonus.c
```
