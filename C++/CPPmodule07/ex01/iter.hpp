#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

//Template function that iterates oven an array and applies a function to each element (works with both const and non-const)
template <typename T_array, typename T_function>
void    iter(T_array *arr, size_t len, T_function func) {
    if (!arr || !func) {
        return;
    }
    for (size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
}

//overload for const arrays with const functions
template <typename T_array, typename T_function>
void    iter(T_array const *arr, size_t len, T_function func) {
    if (!arr || !func) {
        return;
    }
    for (size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
}

#endif