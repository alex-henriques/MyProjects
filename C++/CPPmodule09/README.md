# CPPModule09

This project consists in STL containers applied to real algorithms in C++98. Each exercise uses a distinct container. Contains three exercises.

## ex00 - Bitcoin Exchange

Reads historical BTC price database (`data.cvs`) into a `std::map`, then processes an input file of date/value pairs. For each entry it finds the closest earlier exchange rate using `lower_bound` and prints the converted alue. Rejects negative values, values above 1000, malformed dates, and dates earlier than the database.

### Build & Run

```bash
make
./btc <input_file>
```

Input format (`|`-separated):

```
date | value
2011-01-03 | 3
2022-03-29 | 1.5
```

---

## ex01 - Reverse Polish Notation

An `RPN` class that evaluates an infix-free arithmetic expression passed as a single quoted argument. Tokens are pushed onto a `std::stack<int>`; on encountering an operator (`+`, `-`, `*`, `/`) the top two operands are popped, the result is pushed back. Throws on invalid tokens, insufficient operand, or division by zero.

### Build & Run

```bash
make
./RPN "3 4 + 2 *"
# 14
```

---

## ex02 - PmergeMe

Sorts a sequence of positive integers from the command line using the Ford-Johnson merge-insert sort algorithm, implemented independently for both`std::vector` and std::deque`. Pairs are sorted and split into `main`/`pend` chains. `pend` elements are binary inserted into `main` following the Jacobsthal sequence to minimise comparisons. Timing for each container is measured with `gettimeofday` and printed after sorting.

### Build & Run

```bash
make
/PmergeMe 5 3 17 9 11
```

```
Before: 5 3 17 9 11
After : 3 5 9 11 17
Time to process a range of 5 elements with std::vector : 4.00000 us
Time to process a range of 5 elements with std::deque  : 3.00000 us
```
