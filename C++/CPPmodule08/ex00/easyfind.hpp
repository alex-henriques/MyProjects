#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyFind(T& container, int val)
{
    typename T::iterator it = std::find(container.begin(), container.end(), val);
    if (it == container.end()) {
        throw std::runtime_error("Not found");
    }
    return it;
}

#endif