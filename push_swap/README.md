# push_swap

Push_swap is a C program sorting algorithm project from 42, that sorts a stack of integers using a limited set of operations, with the fewest moves possible.

## How it works

The program receives a list of integers as arguments and outputs to stdout the sequence of operations needed to sort them in ascending order on stack A, using a temporary stack B.
Available operations:
    Operations/Description:
        -> sa/sb: Swap the top two elements of stack A/B
        -> pa/pb: Push top of B onto A/ top of A onto B
        -> ra/rb: Rotate A/B upward (top->bottom)
        -> rra/rrb: Reverse rotate A/B(bottom->top)
        -> ss/rr/rrr: Apply the same operation on both stacks simultaneously

Sorting strategy:
    -> 2 elements — single sa
    -> 3 elements — hardcoded case logic (up to 2 ops)
    -> 5 elements — push the 2 smallest to B, sort the remaining 3, push back
    -> Large stacks — radix sort on normalized indices (bit-by-bit, using pb/pa passes)

## Usage
```bash
make
./push_swap 3 1 4 1 5 9 2 6
# Pass numbers as separate arguments or as a single quoted string:
bash./push_swap "3 1 4 1 5 9 2 6"
# Error cases
Prints Error to stdout and exits with code 1 if:
Any argument is not a valid integer
A value exceeds INT_MAX or INT_MIN
Duplicate values are present 
If the stack is already sorted, no output is produced.
```
## Project structure
push_swap/
├── main.c            # Entry point, argument dispatch
├── parsing.c         # Stack initialization and input validation
├── error.c           # Error handling and duplicate detection
├── utils.c           # Stack helpers (size, is_sorted, free, split)
├── push.c            # pa / pb operations
├── swap.c            # sa / sb / ss operations
├── rotate.c          # ra / rb / rr operations
├── reverse_rotate.c  # rra / rrb / rrr operations
├── small_sort.c      # sort_3 / sort_5
├── radix_sort.c      # index_stack + radix sort for large inputs
├── push_swap.h       # Structs and prototypes
├── libft/            # Custom C library
└── Makefile

## Build
bashmake        # build push_swap
make clean      # remove object files
make fclean     # remove objects + binary
make re         # fclean + all
Compiled with cc -Wall -Wextra -Werror.

## License
42Luxembourg


## Author
Alexandra Henriques (alehenri - 42 Luxembourg)
