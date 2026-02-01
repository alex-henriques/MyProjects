#include "FileName.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./sedisforlosers <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    FileReplace replacer(argv[1], argv[2], argv[3]);
    if(!replacer.processFile()) {
        return 1;
    }
    return 0;
}