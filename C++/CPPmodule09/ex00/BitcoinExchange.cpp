#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <cstdlib>


BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : database(other.database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        database = other.database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


void    BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open database.");
    }
    std::string line;
    std::getline(file, line); //skip header file
    while(std::getline(file, line)) {
        size_t comma = line.find(',');
        if (comma == std::string::npos) {
            continue ;
        }
        std::string date = line.substr(0, comma);
        float rate = std::atof(line.substr(comma + 1).c_str()); //converts string to a float.
        database[date] = rate; //simpleste way to insert into a map
    }
}

float BitcoinExchange::findRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = database.lower_bound(date);
    if (it == database.begin() && it->first != date) {  //date is before the entire database
        throw std::runtime_error("Error: date too early => " + date);
    }
    if (it == database.end() || it ->first != date) { //not exact match, step back to get lower date
        --it;
    }
    return (it->second); //exact match or after stepping back
}

bool    BitcoinExchange::isValidDate(const std::string& date) const { //YYYY-MM-DD
    if (date.size() != 10) {
        return false;
    }
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            continue ;
        }
        if (!std::isdigit(date[i])) {
            return false;
        }
    }
    //int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    /*if (year < 2009) {
        return false;
    }*/
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > 31) {
        return false;
    }
    return true;
}

bool    BitcoinExchange::isValidValue(const std::string& value, float &out) const {
    std::istringstream iss(value);
    iss >> out;
    if (iss.fail()) { //check if the conversion worked.
        return false;
    }
    std::string left;
    iss >> left;
    if (!left.empty()) {
        return false;
    }

    if (out < 0) {
        throw std::runtime_error("Error: not a positive number.");
    }
    if (out > 1000) {
        throw std::runtime_error("Error: too large a number.");
    }
    return true;
}

void    BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }
    std::string line;
    std::getline(file, line); //skip header
    while (std::getline(file, line)) {
        size_t  pipe =line.find('|');
        if (pipe == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue ;
        }
        std::string date = line.substr(0, pipe - 1);
        std::string value = line.substr(pipe + 2);
        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue ;
        }
        float amount = 0;
        try {
            if (!isValidValue(value, amount)) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue ;
            }
            float rate = findRate(date);
            std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}