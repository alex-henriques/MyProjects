#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : s_stack(other.s_stack) {}

RPN& RPN::operator=(const RPN &other) {
    if (this != &other) {
        s_stack = other.s_stack;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.size() == 1 && std::isdigit(token[0])) {
            s_stack.push(token[0] - '0');
        }
        else if (token.size() == 1 && (token [0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            if (s_stack.size() < 2) {
                throw std::runtime_error("Error");
            }
            int b = s_stack.top(); s_stack.pop();
            int a = s_stack.top(); s_stack.pop();
            switch(token[0]) {
                case '+': 
                    s_stack.push(a + b);
                    break ;

                case '-':
                    s_stack.push(a - b);
                    break ;
                
                case '*':
                    s_stack.push(a * b);
                    break ;

                case '/':
                    if (b == 0) {
                        throw std::runtime_error("Error: division by 0.");
                    }
                    s_stack.push(a / b);
                    break ;
            }
        } else {
            throw std::runtime_error("Error");
        }
    }
    if (s_stack.size() != 1) {
        throw std::runtime_error("Error");
    }
    return s_stack.top();
}