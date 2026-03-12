#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <algorithm>
#include <string>
#include <climits>
//#include <ctime>
#include <vector>
#include <deque>

class PmergeMe {
    private:
        std::vector<int>    v_vec;
        std::deque<int>     d_deq;

        void    sortVector();
        void    sortDeque();

        void    insertionVector(std::vector<int> &main, std::vector<int> & pend);
        void    insertionDeque(std::deque<int> &main, std::deque<int> &pend);


    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();

        void    fill(int ac, char **av); //parses input into both containers
        void    sort(); //sorts both, times both and prints results.
};


//std::vector and std::deque

#endif