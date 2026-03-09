#ifndef WHATEVER_HPP
#define WHATEVER_HPP

//Template function to swap 2 vals
template <typename T>
void    swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

//Template function to find min of 2 vals. Returns 2nd val if they're ==
template <typename T>
T const &min(T const &a, T const &b) {
    return (a < b) ? a : b;
}

//Template function to find max of 2 vals. Returns 2nd val if they're ==
template <typename T>
T const &max(T const &a, T const &b) {
    return (a > b) ? a : b;
}

#endif