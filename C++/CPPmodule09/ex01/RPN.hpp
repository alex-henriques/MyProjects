#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <fstream>
#include <sstream>


class RPN {
    private:
        std::stack<int>    s_stack;
    public:
        RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN &other);
        ~RPN();

        int evaluate(const std::string &expression);

};

//std::stack

#endif