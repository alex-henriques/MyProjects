#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <iomanip>
#include <climits>

class   ScalarConverter {
    private:
    //private constructors to prevent instatiation
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        enum LiteralType {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            INVALID
        };

        static LiteralType detectType(const std::string& literal);
        static bool isChar(const std::string& literal);
        static bool isInt(const std::string& literal);
        static bool isFloat(const std::string& literal);
        static bool isDouble(const std::string& literal);
        static void convertFromChar(const std::string& literal);
        static void convertFromInt(const std::string& literal);
        static void convertFromFloat(const std::string& literal);
        static void convertFromDouble(const std::string& literal);

    public:
        static void convert(const std::string& literal);
};

#endif