#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool    ScalarConverter::isChar(const std::string& literal) {
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        return true;
    }
    return false;
}

bool    ScalarConverter::isInt(const std::string& literal) {
    size_t  i = 0;

    if (literal.empty()) {
        return false;
    }
    if (literal[0] == '+' || literal[0] == '-') {
        i = 1;
    }
    if (i>= literal.length()) {
        return false;
    }
    for (; i < literal.length(); i++) { //initialised above.
        if (!isdigit(literal[i])) {
            return false;
        }
    }
    return true;
}

bool    ScalarConverter::isFloat(const std::string& literal) {
    std::string noF = literal.substr(0, literal.length() - 1);
    size_t  i = 0;
    //check for pseudo literals
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        return true;
    }
    if (literal.empty() || literal[literal.length() - 1] != 'f') { //adds the f
        return false;
    }
    if (noF.empty()) {
        return false;
    }
    if (noF[0] == '+' || noF[0] == '-') {
        i = 1;
    }
    bool hasDot = false;
    bool hasDigit = false;
    for (; i < noF.length(); i++) {
        if (noF[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        } else if (isdigit(noF[i])) {
            hasDigit = true;
        } else {
            return false;
        }
    }
    return hasDigit && hasDot;
}

bool    ScalarConverter::isDouble(const std::string& literal) {
    size_t  i = 0;
    //check for pseudo-literals
    if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        return true;
    }
    if (literal.empty()) {
        return false;
    }
    if (literal[0] == '+' || literal[0] == '-') {
        i = 1;
    }
    bool hasDot = false;
    bool hasDigit = false;
    for(; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDot) {
                return false;
            }
            hasDot = true;
        } else if (isdigit(literal[i])) {
            hasDigit = true;
        } else {
            return false;
        }
    }
    return hasDigit && hasDot;
}

ScalarConverter::LiteralType ScalarConverter::detectType(const std::string& literal) {
    if (isChar(literal)) {
        return CHAR;
    }
    if (isFloat(literal)) {
        return FLOAT;
    }
    if (isDouble(literal)) {
        return DOUBLE;
    }
    if (isInt(literal)) {
        return INT;
    }
    return INVALID;
}

void    ScalarConverter::convertFromChar(const std::string& literal) {
    char c = literal[1];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void    ScalarConverter::convertFromInt(const std::string& literal) {
    long long val = std::atoll(literal.c_str()); //c_str() = c style string.
    if (val > INT_MAX || val < INT_MIN) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (static_cast<int>(val) < 0 || static_cast<int>(val) > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (!isprint(static_cast<int>(val))) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(static_cast<int>(val)) << "'" << std::endl;
    }
    std::cout << "int: " << static_cast<int>(val) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(static_cast<int>(val)) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(static_cast<int>(val)) << std::endl;
}

void    ScalarConverter::convertFromFloat(const std::string& literal) {
    float floatVal;
    //handle pseudo-literals
    if (literal == "nanf") {
        floatVal = std::numeric_limits<float>::quiet_NaN();
    } else if (literal == "+inff" || literal == "inff") {
        floatVal = std::numeric_limits<float>::infinity();
    } else if (literal == "-inff") {
        floatVal = -std::numeric_limits<float>::infinity();
    } else {
        floatVal = std::atof(literal.c_str());
    }
    //char
    if (std::isnan(floatVal) || std::isinf(floatVal)) {
        std::cout << "char: impossible" << std::endl;
    } else if (floatVal < 0 || floatVal > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (!isprint(static_cast<int>(floatVal))) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char '" << static_cast<char>(floatVal) << "'" << std::endl;
    }
    //int
    if (std::isnan(floatVal) || std::isinf(floatVal)) {
        std::cout << "int: impossible" << std::endl;
    } else if (floatVal > INT_MAX || floatVal > INT_MIN) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(floatVal) << std::endl;
    }
    //float
    std::cout << "float: " << std::fixed << std::setprecision(1) << floatVal << "f" << std::endl;
    //double
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(floatVal) << std::endl;
}

void    ScalarConverter::convertFromDouble(const std::string& literal) {
    double  doubleVal;
    //handle pseudo_literals
    if (literal == "nan") {
        doubleVal = std::numeric_limits<double>::quiet_NaN();
    } else if (literal == "+inf" || literal == "inff") {
        doubleVal = std::numeric_limits<double>::infinity();
    } else if (literal == "-inff") {
        doubleVal = std::numeric_limits<double>::infinity();
    } else {
        doubleVal = std::atof(literal.c_str());
    }
    //char
    if (std::isnan(doubleVal) ||std::isinf(doubleVal)) {
        std::cout << "char: impossible" << std::endl;
    } else if (doubleVal < 0 || doubleVal > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (!isprint(static_cast<int>(doubleVal))) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(doubleVal) << "'" << std::endl;
    }
    //int
    if (std::isnan(doubleVal) ||std::isinf(doubleVal)) {
        std::cout << "int: impossible" << std::endl;
    } else if (doubleVal > INT_MAX || doubleVal < INT_MIN) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(doubleVal) << std::endl;
    }
    //float
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(doubleVal) << "f" << std::endl;
    //double
    std::cout << "double: " << std::fixed << std::setprecision(1) << doubleVal << std::endl;
}

void    ScalarConverter::convert(const std::string& literal) {
    LiteralType type = detectType(literal);
    switch (type) {
        case CHAR:
            convertFromChar(literal);
            break;
        case INT:
            convertFromInt(literal);
            break;
        case FLOAT:
            convertFromFloat(literal);
            break;
        case DOUBLE:
            convertFromDouble(literal);
            break;
        default:
            std::cout << "NAH-HUH! That's an invalid literal!" << std::endl;
            break;
    }
}