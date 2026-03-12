# CPPModule03

This project consists in Inheritance, constructor/destructor chaining, and multiple inheritance in C++98. Built around a hierarchy of robot like classes derived from `ClapTrap`.

## ex00 - ClapTrap

Base class with hit points (10), energy points (10), and attack damage (0). Implements `attack()`, `takeDamage()`, and beRepaired()`. Each action costs 1 energy point. Demonstrates the orthodox canonical form: default constructor, parameter constructor, copy constructor, copy assignment constructor, and destructor.

### Build & Run

```bash
make
./claptrap
```

---

## ex01 - Serena, my love!

Introduces `ScavTrap`, a class that inherits from `ClapTrap` with different stats (100HP, 50EP, 20ATK) and overrides `attack()`. Adds the `guardGate()` member function. Demonstrates constructor and destructor chaining between parent and child.

### Build & Run

```bash
make
./scavtrap
```

---

## ex02 - FragTrap

Adds `FragTrap`, another class inheriting from `ClapTrap` with its own stats (100HP, 100Ep, 30ATK) and the `highFiveGuys()` member function.

### Build & Run

```bash
make
./fragtrap
```

---

## ex03 - Now it's weird!

Implements `DiamondTrap`, which inherits from both `ScavTrap`, and `FragTrap`, using virtual inheritance to avoid the diamond problem. `DiamondTrap` takes its HP and attack damage from `FragTrap`, and energy points from `ScavTrap`. It holds its own `Name` while `ClapTrap` gets `Name + "_clap_name"`. Adds `whoAmI()` to display both names, and uses `ScavTrap::attack()`.

### Build & Run

```bash
make
./diamondtrap
```

### Inheritance Hierachy

```
        ClapTrap
       /        \
  ScavTrap    FragTrap
       \        /
       DiamondTrap
```

---

## License
42Luxembourg

## Author
Alexandra Henriques (alehenri - 42 Luxembourg)
