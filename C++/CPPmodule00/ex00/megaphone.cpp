#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av) {
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    for (int i = 1; i < ac; i++) {
        std::string str = av[i];
        for (size_t j = 0; j <str.length(); j++) {
            std::cout << (char)std::toupper(str[j]);
        }
    }
    std::cout << std::endl;
    return 0;
}

//instead of an if loop use the toupper() for better reading 
//std::string handles memory management automatically, can come in handy.
//(char)std::toupper() = takes char at position j, converts it to uppercase using std::toupper(), casts it back to char then prints it.