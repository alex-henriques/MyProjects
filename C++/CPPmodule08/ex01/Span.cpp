#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int n) : max(n) {} //stores max capacity n into max. 

Span::Span(const Span& other) : max(other.max), data(other.data) {} //

Span& Span::operator=(const Span& other) {
    if(this != &other) {
        max = other.max;
        data = other.data;
    }
    return *this;
}

Span::~Span() {} //std::vector<int> cleans up automatically so no need to do it manually.

void    Span::addNumber(int n) { //check if it reached capacity.
    if (data.size() >= max) {
        throw std::runtime_error("Span is full");
    }
    data.push_back(n);
}

int  Span::shortestSpan() const { //checks if there are at least 2 nbrs. after sorting the smallest diff must always be between 2 adjacent elements (ex.: 6-3=3; 9-6=3)
    if (data.size() < 2) {
        throw std::runtime_error("Not enough numbers stored");
    }
    std::vector<int> sorted(data);
    std::sort(sorted.begin(), sorted.end());
    int shortest = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < shortest) {
            shortest = diff;
        }
    }
    return shortest;
}

int Span::longestSpan() const { //checks if there are at least 2 nbrs. always max - min (distance between tge smallest and largest vals, no sorting needed)
    if (data.size() < 2) {
        throw std::runtime_error("Not enough numbers stored");
    }
    int min = *std::min_element(data.begin(), data.end()); //deference with * to get actual values
    int max = *std::max_element(data.begin(), data.end());
    return max - min;
}

/*int Span::shortestSpan() const {
    if (data.size() >= max) {
        throw NotEnoughNbrsException();
    }
    std::vector<int> sorted(data);
    std::sort(sorted.begin(), sorted.end());
    int shortest = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); ++i) {
        int diff = sorted[1] - sorted[i - 1];
        if (diff < shortest) {
            shortest = diff;
        }
    }
    return shortest;
}

int Span::longestSpan() const {
    if (data.size() < 2) {
        throw NotEnoughNbrsException();
    }
    int min = *std::min_element(data.begin(), data.end());
    int max = *std::max_element(data.begin(), data.end());
    return max - min;
}

const char* Span::FullSpanException::what() const throw() {
    return "Span is full";
}

const char* Span::NotEnoughNbrsException::what() const throw(){
    return "Not enough numbers stored";
}*/