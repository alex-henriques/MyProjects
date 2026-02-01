#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    const Animal* j = new Dog();
    const Animal* c = new Cat();
    //get types
    std::cout << "j type: " << j->getType() << std::endl;
    std::cout << "c type: " << c->getType() << std::endl;
    //make sound
    j->makeSound();
    c->makeSound();
    delete j;
    delete c;

    std::cout << "\n==> Brain test <==" << std::endl;
    Cat cat_00;
    cat_00.getBrain()->setIdea(0, "You silly hooman, I am GOD");
    cat_00.getBrain()->setIdea(1, "Leave me to sleep, peasant");
    Cat cat_01 = cat_00;
    std::cout << "Cat_00 idea 0: " << cat_00.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat_01 idea 0: " << cat_01.getBrain()->getIdea(0) << std::endl;
    cat_01.getBrain()->setIdea(0, "Gimmie tuna! Now!"); //modified idea
    std::cout << "Cat_00 idea 0: " << cat_00.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat_01 idea 0: " << cat_01.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n==> wrong animal (non-virtual) <==" << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();
    wrongCat->makeSound();
    delete wrongCat;
    
    /* This can't compile:
    std::cout << "\n==> Try to insatiate Animal (fails) <==" <<std::endl;
    Animal* abstract = new Animal();
    delete abstract;*/

    return 0;
}
