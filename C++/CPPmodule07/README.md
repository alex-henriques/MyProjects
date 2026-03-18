# CPPModule07

This project consists of C++98 templates: function templates, template iteraction, and a templated array class. Contains three exercises.

## ex00 - Start with a few functions

Three function templates in `whatever.hpp`(obliged name for the file according to the project subject):

-> `swap(a, b)` - swaps two values in place;
-> `min(a, b)`  - returns the smaller value (returns `b` if equal);
-> `max(a, b)`  - returns the larger value (returns `b` if equal).

Work with any type that supports `<` and `>`.

### Build & Run

```bash
make
./whatever
```

---

## ex01 - Iter

A `iter()` function template in `iter.hpp` that applies a function to every element of an array. Takes a pointer, a length, and a callable. Overloaded for const and non const arrays.

```cpp
iter(arr, len, print<int>);
iter(arr, len, square<int>);
```

### Build & Run

```bash
make
./Iter
```

## ex02 - Array

A templated `Array<T>` classed backed by a heap allocated array. Supports construction with a size, deep copy via copy constructor and assignment operator, and bounds checked element access via `operator[]`. Throws `Array::OutOfRangeException` on out of bounds access.

```cpp
Array<int> arr(10);
arr[0] = 42;
arr[10]; // throws OutOfRangeException
```

### Build & Run

```bash
make
./Array
```
