# CPPModule05

This project consists of repetition and execution in C++98. Models a bureaucratic system with `Bureaucrat` and form classes, introducing exception handling, abstract classes, and the Intern pattern. Contains four exercises.

## ex00 - Mommy, when I grow up, I want to be a bureaucrat!

Implements a `Bureaucrat` class with a constant name and a grade between 1(highest) and 150(lowest). Attemptinf to construct or modify a grade outside this rane throws a nested exception (`GradeTooHighException` or `GradeTooLowException`).

### Build & Run

```bash
make
./bureaucrat
```

---

## ex01 - Form up, maggots!

Adds a `Form` class with a name, a signed status, and two grade requirements (to sign and to execute). `Bureaucrat::signForm()` attempts to sign the form and prints the outcome. Throws an execption if the bureaucrat's grade is insufficient.

### Build & Run

```bash
make
./form
```

---

## ex02 - No, you need form 28B, not 28C...

Renames `Form` to `AForm` (abstract base class) and introduces three concrete form types:

| Form | Grade to sign | Grade to execute | Effect |
|------|--------------|-----------------|--------|
| `ShrubberyCreationForm` | 145 | 137 | Writes an ASCII tree to `<target>_shrubbery` |
| `RobotomyRequestForm` | 72 | 45 | 50% chance of successful robotomy |
| `PresidentialPardonForm` | 25 | 5 | Announces a presidential pardon |

`Bureaucrat::executeForm()` attempts to execute a signed form and reports the result.

### Build & Run

```bash
make ./forms
```

---

## ex03 - At least this beats coffee making

Adds an `Intern` class with no name or grade. `Intern::makeForm(formName, target)` creates and returns a pointer to the correct `AForm` subclass using an array of member function pointers. No `if/else` chain. Throws `FormNotFoundException` for unknown form names.

### Build & Run

```bash
make
./AtLeastThisBeatsCoffeeMaking
```

```cpp
Intern intern;
Aform* form = intern.makeForm("robotomy request", "Bender");
// caller is responsible for deleting the form
delete form;
```
