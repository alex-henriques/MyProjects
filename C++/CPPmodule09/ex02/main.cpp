#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error: not enough arguments." << std::endl;
        return 1;
    }
    try {
        PmergeMe pmergeme;
        pmergeme.fill(ac, av);
        pmergeme.sort();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}