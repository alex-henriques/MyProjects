# CPPModule06

This project consists of C++ type casting: `static_cast`, `reintrepret_cast`, and `dynamic_cast`. Contains three exercises

## ex00 - Scalar Converter

A non instatiable `ScalarConverter` class with a single static method `convert()`. Takes a string literal, detects its type (char, int, float or double), and prints the value converted to all four scalar types.

Handles pseudo literals: `nan`, `nanf`, `+inf`, `+inff`, `-inff`.

## Build & Run

```bash
make
./ScalarConverter <literal>
```

```bash
./ScalarConverter 42
./ScalarConverter 3.14f
./ScalarConverter "'a'"
./ScalarConverter nan
```
Output:

```
char: '*'
int: 42
float: 42.0f
double: 42.0
```

---

## ex01 - Serialization

A non instatiable `Serialization` class demonstrating `reinterpret_cast`. Converts a `Data*` pointer to a `uintptr_t` integer (`serialize`) and back to a pointer (`deserualize`), verifying that the address is preserved across the round trip.

### Build & Run

```bash
make
./serializer
```

---


## ex02 - Real Type Identification

Implements runtime type identification using `dynamic_cast` without `typeinfo`. A `Base` class with a virtual destructor and three empty derived classes `A`, `B`, `C`. Two overloads of `identify()` determine the actual type; one via pointer (returns `NULL` on failure), one via reference (catches `std::bad_cast`).

### Build & Run

```bash
make
./IdentifyRealType
```
