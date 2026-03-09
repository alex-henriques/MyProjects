#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int main() {
    std::cout << "==> Subject test <==" << std::endl;
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << "==> 10,000 number test <==" << std::endl;
    Span big(10000);
    std::vector<int> nbr;
    for (int i = 0; i < 10000; ++i) {
        nbr.push_back(rand() % 1000000); //range of possible values
    }
    big.addRange(nbr.begin(), nbr.end());
    std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
    std::cout << "Longest span: " << big.longestSpan() << std::endl;
    std::cout << std::endl;


    std::cout << "==> Overflow <==" << std::endl;
    try {
        sp.addNumber(42);
    } catch(std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "==> Not enough numbers <==" << std::endl;
    try {
        Span sp2(1);
        sp2.addNumber(6);
        sp2.shortestSpan();
    } catch (std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }

    return 0;
}