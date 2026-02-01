#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
//original tests
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
delete j;
delete i;
delete meta;

//additional tests
std::cout << "\n==> Copy tests with Brain <==" << std::endl;
Dog originalDog;
originalDog.getBrain()->setIdea(0, "Chase squirrels");
originalDog.getBrain()->setIdea(1, "Fetch");
originalDog.getBrain()->setIdea(2, "Guard");
std::cout << "Copying dog.." << std::endl;
Dog copiedDog(originalDog);
std::cout << "Original dog's ideas:" << std::endl;
std::cout << "Idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
std::cout << "Idea 1: " << originalDog.getBrain()->getIdea(1) << std::endl;
std::cout << "Idea 2: " << originalDog.getBrain()->getIdea(2) << std::endl;
std::cout << "Copied dog's ideas" << std::endl;
std::cout << "Idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;
std::cout << "Idea 1: " << copiedDog.getBrain()->getIdea(1) << std::endl;
std::cout << "Idea 2: " << copiedDog.getBrain()->getIdea(2) << std::endl;
std::cout << "Modifying dog's original ideas..." << std::endl;
originalDog.getBrain()->setIdea(0, "Sleep all day");
std::cout << " Original dog's idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
std::cout << " Copied dog idea: " << copiedDog.getBrain()->getIdea(0) << std::endl;
if (originalDog.getBrain() != copiedDog.getBrain()) {
    std::cout << "Success: Brain pointers are different (working)" << std::endl;
} else {
    std::cout << "Failure: Brain pointers are the same (not working)" << std::endl;
}
return 0;
}
