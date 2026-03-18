# 42 C++ Modules

A collection of C++ modules completed as part of the 42 curriculum. Each module explores a specific area of C++98 through a series of exercises.

---

## Module 00 - Namespacesm, classes, member functions, stdio streams

- **ex00 - Megaphone:** Uppercase all command line arguments;
- **ex01 - PhoneBook:** In memory phonebook for up to 8 contacts with `ADD`, `SEARCH`, and `EXIT`, commands;
- **ex02 - The Job of Your Dreams:** Reimplementation of `Account.cpp` from a provided header; timestamped bank account logging.

---

## Module 01 - Memory allocation, references, pointers to memebers, file streams

- **ex00 - BraiiiiiiinnnzzzZ:** Zombie class demonstrating heap vs stack allocation;
- **ex01 - Moar brainz!:** `zombieHorde()` allocates N zombies with a single `new[]`;
- **ex02 - HI THIS IS BRAIN:** Pointer vs reference identity demo;
- **ex03 - Unnecessary Violence:** `HumanA` (weapon by reference) vs `HumanB` (weapon by pointer);
- **ex04 - Ser is for losers:** Reads a fie and writes a copy with a string replacement;
- **ex05 - Harl 2.0:** Dispatches log levels via an array of member function pointers;
- **ex06 - Harl Filter:** Prints a given log level and all levels above it using switch fall-through.

---

## Module 02 - Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form

All three exercises build incrementally on a single `Fixed` class representing a fixed point number with 8 fractional bits.

- **ex00 - My First Clss in Orthodox Canonical Form:** Bare bones `Fixed` in OCF with `getRawBits()` and `setRawBits()`;
- **ex01 - Towards a More Useful Fixed Point Number Class:** Adds int/flaot constructors, `toInt()`, `toFloat()`, and `operator<<`;
- **ex02 - Now We're Talking:** Completes the class with comparison operators (`<`, `>`, `<=`, `>=`, `==`, `!=`), arithmetic operators, prefix/postfix `++`/`--`, and static `min()`/`max()` overloads.

---

## Module 03 - Inheritance

A chain of robot classes, each inheriting from the previous, demonstrating inheritance, constructor chaining, and virtual inheritance

| Class | Inherits from | HP | Energy | Attack | Special |
|-------|-------------|-----|--------|--------|---------|
| `ClapTrap` | — | 10 | 10 | 0 | `attack()`, `takeDamage()`, `beRepaired()` |
| `ScavTrap` | `ClapTrap` | 100 | 50 | 20 | `guardGate()` |
| `FragTrap` | `ClapTrap` | 100 | 100 | 30 | `highFiveGuys()` |
| `DiamondTrap` | `ScavTrap` + `FragTrap` (virtual) | FragTrap's | ScavTrap's | FragTrap's | `whoAmI()` |

`DiamondTrap` uses virtual inheritance to resolve the diamond problem; its own `Name` differs from the `ClapTrap::Name` it stores internally (`<name>_clap_name`). `whoAmI()` prints both.

---

## Module 04 - Subtype polymorphism, abstract classes, interfaces

- **ex00 - Polymorphism:** `Animal` base with `virtual makeSound()`; `Dog` and `Cat` subclasses. `WrongAnimal`/`WrongCat` demonstrate non polymorphic behaviour;
- **ex01 - Brain:** `Dog` and `Cat` each own a heap allocated `Brain` (100 `std::string` ideas). Deep copy enforced;
- **ex02 - Abstract Class:** `makeSound() = 0` makes `Animal` uninstatiable directly.

---

## Module 05 - Repetition and exceptions

- **ex00 - Bureaucrat:** `Bureaucrat` class with grade 1-150; throws `GradeTooHighException`/`GradeTooLowException` on invalid grades;
- **ex01 - Form up, Maggots!:** `Form` class with sign/execute grade requirements;
- **ex02 - No, you need form 28B, not 28C...:** Abstract `AForm` base with three concrete forms: `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`;
- **ex03 - At least this beats coffee making:** `Intern::makeForm()` creates the correct form by name using an array of member function pointers.

---

## Module 06 - C++ Casts

- **ex00 - Scalar Converter:** Detects the type of a string literal and converts it to all four scalar types. Handles pseudo-literals;
- **ex01 - Serialization:** `reinterpret_cast` round trip: `Data*` -> `uintptr_t` -> `Data*`;
- **ex02 - Real Type Identification:** `dynamic_cast` identifies the actual derived type of a `Bas*` or `Base&` without `typeinfo`.

---

## Module 07 - C++ Templates

- **ex00 - Start With a Few Functions:** `swap()`, `min()`, `max()` function templates;
- **ex01 - Iter:** `iter(arr, len, func)` applies any callable to every element of an array;
- **ex02 - Array:** Templated `Array<T>` with bounds check `operator[]`. Throws `OutOfRangeException`.

---

## Module 08 - Templated containers, iterators, algorithms

- **ex00 - Easy Find:** `easyFind()` searches any integer sequence container via `std::find`. Throws if not found;
- **ex01 - Span:** Stores up to N integers, comoutes `shortestSpan()` and `longestSpan()`. Bulk insert via templated `addRange()`;
- **ex02 - Mutant Stack:** `MutantStack<T> inherits from `std::stack` and exposes the underlying container's iterators.

---

## Module 09 - STL

- **ex00 - Bitcoin Exchange:** Loads a BTC price database into `std::map`, looks up the closest ealier rate with `lower_bound`;
- **ex01 - Reverse Polish Notation:** Evaluates an RPN expression using `std::stack<int>`, supports `+`, `-`, `/`, `*`;
- **ex02 - PmergeMe:** Ford-Johnson merge-insert sort implemented with both `std::vector` and `std::deque`. Jacobsthal sequence used for insertion order. Timing via `gettimeofday`.
