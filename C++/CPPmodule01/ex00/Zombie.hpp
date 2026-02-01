#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class   Zombie {
private:
    std::string name;
    

public:
    Zombie(std::string zombieName);
    ~Zombie();
    void    announce(void);
};

Zombie*	newZombie(std::string name); //heap
void    randomChump(std::string name); //stack

#endif