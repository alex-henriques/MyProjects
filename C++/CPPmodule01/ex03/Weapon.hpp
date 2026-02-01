#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
private:
    std::string type;

public:
    Weapon(std::string  type);
    const std::string& getType() const;
    void    setType(std::string otherType);
};

//No need for destructors because I'm not dynamically allocating memory.

#endif