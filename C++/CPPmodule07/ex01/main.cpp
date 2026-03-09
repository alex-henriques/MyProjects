#include "iter.hpp"
#include <iostream>
#include <string>


//test functions to be called by main()
void    increment(int &n) {
    n++;
}

void    toUpper(char &c) {
    if  (c >= 'a' && c <= 'z')
        c = c - 'a' + 'A';
}

template <typename T>
void    square(T &j) {
    j = j * j;
}

template <typename T>
void    print (T const &n) {
    std::cout << n << " ";
}

int main() {
    std::cout << "==> Print int arr <==" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    size_t len= 5;
    iter(arr, len, print<int>);
    std::cout << std::endl;

    std::cout << "==> Square ints <==" << std::endl;
    iter(arr, len, square<int>);
    std::cout << "after squaring: ";
    iter(arr, len, print<int>);
    std::cout << std::endl;

    std::cout << "==> Char arr to upercase <==" << std::endl;
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charLen = 5;
    std::cout << "Before: ";
    iter(charArr, charLen, print<char>);
    std::cout << std::endl;
    iter(charArr, charLen, toUpper);
    std::cout << "After: ";
    iter(charArr, charLen, print<char>);
    std::cout << std::endl;

    std::cout << "==> Print string arr <==" << std::endl;
    std::string strArr[] = {"Hello", "Darkness", "my", "old", "Friend"};
    size_t strLen = 4;
    iter (strArr, strLen, print<std::string>);
    std::cout << std::endl;

    return 0;

}