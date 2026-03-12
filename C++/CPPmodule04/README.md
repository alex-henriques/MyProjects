# CPPModule04

This project consists of Subtype Polymorphism, abstract classes, and interfaces in C++98. Contains three exercises.

## ex00 - Polymorphism

Introduces virtual functions and polymorphism through an `Animal` base class with `Dog` and `Cat` subclasses. `makeSound()` is virtual, so calling it through a base class pointer dispatches to the correct derived implementation. `WrongAnimal` and `WrongCat` demonstrates what happens without `virtual`. The base class method is called regardless of the actual object type.

### Build & Run

```bash
make
./animal
```

---

## ex01 - I don't want to set the world on fire

Adds a `Brain` class holding 100 ideas (`std::string ideas[100]`). `Dog` and `Cat` each own a `Brain` allocated on the heap. Copy constructor and assignment operator perform a deep copy. Modifying a copied animal's brain does not affect the original.

### Build & Run

```bash
make
./brain
```

---

## ex02 - Abstract Class

Makes `Animal` abstract by declaring `makeSound()` as a pure virtual function (`= 0`). `Animal` can no longer be instantiated directly. Only concrete subclasses (`Dog`, `Cat`) can. Deep copy of `Brain` is preserved from ex01.

### Build & Run

```bash
make
./abstractclass
```

---

## License

42Luxembourg

## Author
Alexandra Henriques (alehenri - 42Luxembourg)
