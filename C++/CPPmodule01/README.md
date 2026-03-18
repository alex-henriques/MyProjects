# CPPModule01

This module consists in memory allocation, pointers to members, and the `switch` statement in C++98. This module has seven exercises.

## ex00 - BraiiiiiiinnnzzzZ

Introduces heap vs stack allocation using a `Zombie` class. `newZombie()` allocates on the heap and returns a pointer (caller must `delete`). `randomChump()` creates a zombie on the stack that is destroyed automatically at the end of scope.

### Build & Run

```bash
make
./zombie
```
---

## ex01 - Moar Brainz!

Allocates an array of `N` zombies on the heap using a single `new[]` call via `zombieHorde()`. All zombies are freed with a single `delete[]`.

### Build & Run

```bash
make
./zombieHorde
```

---

## ex02 - HI THIS IS BRAIN

Demonstrates that a pointer and a reference to the same variable hold the same memory address and expose the same value.

### Build & Run

```bash
make
./brain
```

---

## ex03 - Unnecessary Violence

Explores the difference between references and pointers through two `Human` classes. `HumanA` always holds a weapon (stored as a reference - weapon is mandatory). `HumanB` may or may nor have a weapon (stored as a pointer).

### Build & Run

```bash
make
./violence
```

---

## ex04 - Sed is for losers

A file replacement tool. Readsa  file, replaces all occurrences of a string `s1`, with `s2`, and writes the result to `<filename>.replace`. Uses only C++ file streams - no `sed`, no `std::string::replace`.

### Build & Run

```bash
make
./sedisforlosers <filename> <s1> <s2>
```

```bash
./sedisforlosers file.txt "hello" "world"
# produces file.txt.replace
```

---

## ex05 - Harl 2.0

Implements a `Harl` class that dispatches complaint levels (`DEBUG`, `INFO`, `WARNING`, `ERROR`) using an array of member function pointers instead of a chain of `if/else`.

### Build & Run

```bash
make
./harl
```

---

## ex06 - Harl Filter

Extension of ex05. Takes a log level as argument and prints that leel and all levels above it using a `switch`1 statement with fall-through.

### Build & Run

```bash
make
./harlfilter <LEVEL>
```

```bash
./harlfilter WARNING
# prints WARNING and ERROR
```
