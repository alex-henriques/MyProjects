# CPPModule00

Introductionn to C++98: namespaces, classes, member functions, stdio streams, and basic OOP concepts. Contains three exercises.

## ex00 - Megaphone

A simple program that uppercases all its arguments.

### Build

```bash
make
```

### Usage

```bash
./megaphone hello world
# HELLO WORLD

./megaphone
# * LOUD AND UNBEARABLE FEEDBACK NOISE *
```
---

## ex01 - My Awesome PhoneBook

A basic in memory phonebook that stores up to 8 contacts using a circular buffer. Implements two classes: `PhoneBook` and `Contact`.

### Build

```bash
make
```

### Usage

```bash
./phonebook
```

Available commands at the prompt: `ADD`, `SEARCH`, `EXIT`.

- `ADD` - prompts for first name, last name, nickname, phone number, and darkest secret;
- `SEARCH` - lists all stored contacts in a formatted table; enter an index to view full details. Fields longer than ten characters are truncated with a `.`
- `EXIT` - exits the program

The phonebook holds a maximum of 8 contacts. Once full, the old is overwritten.

---

## ex02 - The Job of Your Dreams

Reimplementation of `Account.cpp` from a provided header and expected log output. Simulates bank accounts with deposits, withdrawals, and timestamped logging.

### Build

```bash
make
```

### Usage

```bash
./account
```

The output is compared against `19920104_091532.log` (timestamps will differ).

---

## License
42Luxembourg

## Author
Alexandra Henriques (alehenri - 42Luxembourg) 
