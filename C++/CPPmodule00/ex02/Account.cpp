#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//constructor:
Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts; //_nbAccounts start at 0 so the first account gets index 0, second gets 1, etc
    _amount = initial_deposit; // sets the account's balance to the initial deposit amount
    _nbDeposits = 0; //No deposits have been made yet so we initialise it to 0
    _nbWithdrawals = 0; // No withdrawals have been made yet so we initialise it to 0

    _nbAccounts++; //increments total number of accounts
    _totalAmount += initial_deposit; //adds the account's initial deposit to the global total

    _displayTimestamp(); //calls helper function that prints the timestamp
    std::cout << "index:" << _accountIndex << ";"; //prints smth like Index:X; (etc) - message format
    std::cout << "amount:" << _amount << ";"; // prints smth like amount:Y (etc) - message format
    std::cout << "created" << std::endl; // prints "created" followed by a new line.
    // will print like the message format seen in the logs file
}


//destructor: (~ -> this symbol means it's a destructor)
Account::~Account(void) {
    _displayTimestamp(); // prints current time
    std::cout << "index:" << _accountIndex << ";"; //prints which account is being closed
    std::cout << "amount:" << _amount << ";"; // prints how much money is left in that account
    std::cout << "closed" << std::endl;
}

//Static member functions:
int Account::getNbAccounts(void) { //returns how many accounts currently exist
    return _nbAccounts;
}

int Account::getTotalAmount(void) { //returns the sum of money across all accounts
    return _totalAmount;
}

int Account::getNbDeposits(void) { //returns the total nr of deposits made across all accounts
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) { // returns the total nr of withdrawals made across all accounts
    return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos(void) { //summary of all accounts combined
    _displayTimestamp(); // print timestamp
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits" << _totalNbDeposits << ";";
    std::cout << "withdrawals" << _totalNbWithdrawals << std::endl;
}

// not statis member functions
void    Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout <<"deposit:" << deposit << ";";

    _amount += deposit; //add the deposit to the account balance
    _nbDeposits++; //increment this account's deposit by 1
    _totalAmount += deposit; //add the deposit to the global total (all accounts combined)
    _totalNbDeposits++; // increment global deposit by 1. Tracks deposits across all accounts

    std::cout << "account:" << _amount << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal) { //tries to remove money from a specific account
    _displayTimestamp();
    std::cout << "index:" <<_accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    
    if (withdrawal > _amount) {
        std::cout << "Withdrawal:refused" << std::endl;
        return false;
    }
    std::cout << "Withdrawal:" << withdrawal << ";";
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const { //function that returns account's current balance (const means the function promises not to change anything)
    return _amount;
}

void    Account::displayStatus(void) const { //function that shows detailed info about specific account
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

//private member functions
void    Account::_displayTimestamp(void) { //time stamp function -> over-mega-complicated. Send help!!
    std::time_t now = std::time(NULL);
    std::tm *ltm = std::localtime(&now);

    std::cout << "[";
    std::cout << (1900 + ltm->tm_year);
    std::cout << std::setfill('0') << std::setw(2) << (1 + ltm->tm_mon);
    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_mday;
    std::cout << "_";
    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_sec;
    std::cout << "] ";
}