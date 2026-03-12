#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : v_vec(other.v_vec), d_deq(other.d_deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        v_vec = other.v_vec;
        d_deq = other.d_deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void    PmergeMe::fill(int ac, char **av) {
    if (ac < 2) 
        throw std::runtime_error("Error: no arguments.");
    for (int i = 1; i < ac; i++) {
        std::string tok(av[i]);
        if (tok[0] == '-') { //check for negative ints
            throw std::runtime_error("Error");
        }
        for (size_t j = 0; j < tok.size(); j++) { //check for float
            if (!std::isdigit(tok[j]))
                throw std::runtime_error("Error");
        }
        long nbr = std::strtol(tok.c_str(), NULL, 10); //strtol parses and checks for overflow
        if (nbr > INT_MAX)
            throw std::runtime_error("Error");
        v_vec.push_back(static_cast<int>(nbr));
        d_deq.push_back(static_cast<int>(nbr));
    }
}

void    PmergeMe::insertionVector(std::vector<int> &main, std::vector<int> & pend) {
    if (pend.empty())
        return ;
    std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[0]); //always insert pend first
    main.insert(pos, pend[0]);
    if (pend.size() == 1)
        return ;
    //jacobsthal sequence
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    while (jacobsthal.back() < pend.size()) {
        size_t  next = jacobsthal[jacobsthal.size()-1] + 2 * jacobsthal[jacobsthal.size()-2];
        jacobsthal.push_back(next);
    }
    //insert following jacobsthal order
    for (size_t i = 0; i < jacobsthal.size(); i++) {
        size_t  j = jacobsthal[i];
        if (j >= pend.size())
            break ;
        pos = std::lower_bound(main.begin(), main.end(), pend[j]);
        main.insert(pos, pend[j]);
    }
    //insert any remaining elements jacobsthal skipped
    for (size_t i = 1; i < pend.size(); i++) {
        bool    inserted = false;
        for (size_t j = 0; j < jacobsthal.size(); j++) {
            if (jacobsthal[j] == i) {
                inserted = true;
                break ;
            }
        }
        if (!inserted) {
            pos = std::lower_bound(main.begin(), main.end(), pend[i]);
            main.insert(pos, pend[i]);
        }
    }
}

void    PmergeMe::insertionDeque(std::deque<int> &main, std::deque<int> &pend) {
    if (pend.empty())
        return ;
    std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[0]); //always insert pend first
    main.insert(pos, pend[0]);
    if (pend.size() == 1)
        return ;
    //jacobsthal sequence
    std::deque<size_t> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    while (jacobsthal.back() < pend.size()) {
        size_t  next = jacobsthal[jacobsthal.size()-1] + 2 * jacobsthal[jacobsthal.size()-2];
        jacobsthal.push_back(next);
    }
    //insert following jacobsthal order
    for (size_t i = 0; i < jacobsthal.size(); i++) {
        size_t  j = jacobsthal[i];
        if (j >= pend.size())
            break ;
        pos = std::lower_bound(main.begin(), main.end(), pend[j]);
        main.insert(pos, pend[j]);
    }
    //insert any remaining elements jacobsthal skipped
    for (size_t i = 1; i < pend.size(); i++) {
        bool    inserted = false;
        for (size_t j = 0; j < jacobsthal.size(); j++) {
            if (jacobsthal[j] == i) {
                inserted = true;
                break ;
            }
        }
        if (!inserted) {
            pos = std::lower_bound(main.begin(), main.end(), pend[i]);
            main.insert(pos, pend[i]);
        }
    }
}

void    PmergeMe::sort() {
    std::cout << "Before: ";
    for (size_t i = 0; i < v_vec.size(); i++) {
        std::cout << v_vec[i] << " ";
    }
    std::cout << std::endl;

    /*clock_t start = clock();
    sortVector();
    clock_t end = clock();
    double  vecTime = double(end - start) / CLOCKS_PER_SEC * 1000000;

    start = clock();
    sortDeque();
    end = clock();
    double deqTime = double (end - start) / CLOCKS_PER_SEC * 1000000;*/

    struct timeval start, end;

    gettimeofday(&start, NULL);
    sortVector();
    gettimeofday(&end, NULL);
    double vecTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    sortDeque();
    gettimeofday(&end, NULL);
    double deqTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    std::cout << "After: ";
    for (size_t i = 0; i < v_vec.size(); i++) {
        std::cout << v_vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << v_vec.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << d_deq.size() << " elements with std::deque : " << std::fixed << std::setprecision(5) << deqTime << " us" << std::endl;
}

void    PmergeMe::sortVector() {
    if (v_vec.size() <= 1) 
        return ;
    bool hasLeftElement = (v_vec.size() % 2 != 0);
    int  leftElement = 0;
    if (hasLeftElement)
        leftElement = v_vec.back(); //save last element
    std::vector<int>    main;
    std::vector<int>    pend;
    size_t              limits = v_vec.size() - (hasLeftElement ? 1 : 0);
    for (size_t i = 0; i + 1 < limits; i += 2) {
        if (v_vec[i] > v_vec[i + 1])
            std::swap(v_vec[i], v_vec[i + 1]);
        main.push_back(v_vec[i + 1]); //larger
        pend.push_back(v_vec[i]); //smaller
    }
    //replace v_vec with main to recurse
    v_vec = main;
    sortVector();
    main = v_vec;
    insertionVector(main, pend);
    if (hasLeftElement) { //insert last element if it has any
        std::vector<int>::iterator pos = std::lower_bound(main.begin(), main.end(), leftElement);
        main.insert(pos, leftElement);
    }
    v_vec = main;
}

void    PmergeMe::sortDeque() {
    if (d_deq.size() <= 1) 
        return ;
    bool hasLeftElement = (d_deq.size() % 2 != 0);
    int  leftElement = 0;
    if (hasLeftElement)
        leftElement = d_deq.back(); //save last element
    std::deque<int>    main;
    std::deque<int>    pend;
    size_t             limits = d_deq.size() - (hasLeftElement ? 1 : 0);
    for (size_t i = 0; i + 1 < limits; i += 2) {
        if (d_deq[i] > d_deq[i + 1])
            std::swap(d_deq[i], d_deq[i + 1]);
        main.push_back(d_deq[i + 1]); //larger
        pend.push_back(d_deq[i]); //smaller
    }
    //replace d_deq with main to recurse
    d_deq = main;
    sortDeque();
    main = d_deq;
    insertionDeque(main, pend);
    if (hasLeftElement) { //insert last element if it has any
        std::deque<int>::iterator pos = std::lower_bound(main.begin(), main.end(), leftElement);
        main.insert(pos, leftElement);
    }
    d_deq = main;
}
