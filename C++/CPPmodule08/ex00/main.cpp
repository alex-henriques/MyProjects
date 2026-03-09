#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

//tester for easyfind()
template <typename T>
void    testEasyFind(T& container, int val) 
{
    try {
        typename T::iterator it = easyFind(container, val);
        std::cout << "Found " << val << " at position " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error, value at position " << val << ": " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "==> vector <==" << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(29);
    vec.push_back(3);
    vec.push_back(42);
    vec.push_back(5);
    testEasyFind(vec, 42);
    testEasyFind(vec, 19);
    testEasyFind(vec, 1);
    std::cout << std::endl;

    std::cout << "==> list <==" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    testEasyFind(lst, 20);
    testEasyFind(lst, 2);
    std::cout << std::endl;

    std::cout << "==> deque <==" << std::endl;
    std::deque<int> deq;
    deq.push_back(40);
    deq.push_back(50);
    deq.push_back(60);
    testEasyFind(deq, 60);
    testEasyFind(deq, 6);
    
    return 0;
}