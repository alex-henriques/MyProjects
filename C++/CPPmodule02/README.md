# CPPModule02

This project consists in Ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Form in C++98. This module has three exercises, all built around a `Fixed` class implementing fixed point arithmetic with 8 fractional bits.

## ex00 - My First Class in Orthodox Canonical Form 

Introduces the Orthodox Canonical Form: default constructor, copy constructor, copy assignment operator, and destructor. The `Fixed` class stores a raw integer and exposes `getRawBits()` / `setRawBits()`.

### Build & Run

```bash
make
./fixed
```

---

## ex01 - Towards a more useful Fixed point number class

Extends `Fixed` with int and float constructors, `toInt()`, `toFloat()`, and an overload `<<` operator for direct stream output.

### Build & Run

```bash
make
./fixed
```

---

## ex02 - Now we're Talking

Full operator overload suite added to `Fixed`: comparison operators (`<`, `>`, `<=`, `>=`, `==`, `!=`), prefix and postfix increment (`++`), multiplication (`*`), and static `min()` / `max()` overloads for both const and non const reference.

### Build & Run

```bash
make
./fixed
``` 
