#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span {
    private:
            unsigned int max;
            std::vector<int> data;
    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void    addNumber(int n);
        //void    addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        int shortestSpan() const;
        int longestSpan() const;

        template<typename Iterator>
        void    addRange(Iterator begin, Iterator end) {
            for (Iterator it = begin; it != end; ++it) {
                addNumber(*it);
            }
        }

        /*class FullSpanException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class NotEnoughNbrsException : public std::exception {
            public:
                virtual const char* what() const throw();
        };*/
};

#endif