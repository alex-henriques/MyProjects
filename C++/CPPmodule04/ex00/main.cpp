#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

//original testing
int main() {
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();
delete meta;
delete j;
delete i;

//additional testing
std::cout << "\n==> WrongAnimal test <==" << std::endl;
WrongAnimal* wrongMeta = new WrongAnimal();
WrongAnimal* wrongCat = new WrongCat();
std::cout << "WrongAnimal type: " << wrongMeta->getType() <<std::endl; // empty because base class doesn't set a specific type
std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
std::cout << "WrongAnimal sound: ";
wrongMeta->makeSound();
std::cout << "WrongCat sound: ";
wrongCat->makeSound();
delete wrongMeta;
delete wrongCat;

std::cout << "\n==> Copy constructors <==" <<std::endl;
Dog originalDog;
std::cout << "\nCopy dog " <<std::endl;
Dog copiedDog(originalDog);
std::cout << "Original dog type: " << originalDog.getType() << std::endl;
std::cout << "Copied dog type: " << copiedDog.getType() << std::endl;
std::cout << "Original dog sound: ";
originalDog.makeSound();
std::cout << "copied dog sound: ";
copiedDog.makeSound();

std::cout << "\n==> Assignment operators <==" << std::endl;
Cat cat_00;
Cat cat_01;
std::cout << "\nAssigning cat_00 to cat_01 .." << std::endl;
cat_01 = cat_00;
std::cout << "Cat_00 type: " << cat_00.getType() << std::endl;
std::cout << "Cat_01 type: " << cat_01.getType() << std::endl;

std::cout << "\n==> Animal arrays <==" << std::endl;
const Animal* animals[4];
animals[0] = new Dog();
animals[1] = new Cat();
animals[2] = new Dog();
animals[3] = new Cat();

for (int index = 0; index < 4; index++) {
    std::cout << "Animal[" << index << "] is a " << animals[index]->getType() << " and says: ";
    animals[index]->makeSound();
}
for (int index = 0; index < 4; index++) {
    delete animals[index];
}

std::cout << "\n==> Polymorphic fucntion <==" << std::endl;
Animal* polyAnimal;
polyAnimal = new Cat();
std::cout << "Type: " << polyAnimal->getType() << std::endl;
std::cout << "Sound: ";
polyAnimal->makeSound();
delete polyAnimal;

return 0;
}
