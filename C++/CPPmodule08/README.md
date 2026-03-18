# CPPModule08

This project consists in templated containers, iterators, and algorithms in C++98. Contains three exercises.

## ex00 - Easy Find

A `easyFind()` function template in `easyfind.hpp` that searches any integer sequence container for a value using `std::find`. Returns an iterator to the first match, or throws `std::runtime_error` if not found. Compatible with `std::vector`, `std::list`, `std::deque`, and any container that provides `begin()`/`end()`.

### Build & Run

```bash
make
./easyfind
```

---

## ex01 - Span

A `Span` class storing up to `N` integers. Supports single insertion via `addNumber()` and bulk insertion via the templated `addRange(begin, end)`. Throws on overflow or when fewer than two numbers are sorted.

| Method | Description |
|--------|-------------|
| `shortestSpan()` | Minimum difference between any two stored values |
| `longestSpan()` | `max - min` of all stored values |

### Build & Run

```bash
make
./Span
```

---

## ex02 - Mutant Stack

A `MutantStack<T>` class inheriting from `std::stack` and exposing the underlying container's iterators. Adds `begin()`, `end()`, `rbegin()`, `rend()`, and their `const` variants, making the stack iterable like any STL container while retaining full `std::stack` behaviour.

```cpp
MutantStack<int> mstack;
mstack.push(42);
for(MutantStack<int>::iterator it = mstack.begin(); it ~= mstack.end(); ++it)
    std::cout << *it << std::endl;
```

### Build & Run

```bash
make
./MutantStack
```
