#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <stdexcept>

class BitcoinExchange {
    private:
        std::map<std::string, float>    database;

        void    loadDatabase(const std::string& filename); //private because it's an internal detail, only the constructor will call it
        float   findRate(const std::string& date) const; // returns a float because once the date is validates, only exchange rate is needed from the map
        bool    isValidDate(const std::string& date) const;
        bool    isValidValue(const std::string& value, float &out) const; //validate and parse at the same time

    public:
        BitcoinExchange(const std::string& dbFile);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void    processInput(const std::string& filename);
};

//std::map

#endif