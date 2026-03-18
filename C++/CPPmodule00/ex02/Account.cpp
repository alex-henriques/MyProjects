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
    _accountIndex = _nbAccounts; 
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts++; 
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
    // will print like the message format seen in the logs file
}
//destructor
Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";"; 
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

// not static member functions
void    Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout <<"deposit:" << deposit << ";";

    _amount += deposit; 
    _nbDeposits++; 
    _totalAmount += deposit;
    _totalNbDeposits++;

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

int Account::checkAmount(void) const { //returns account's current balance
    return _amount;
}

void    Account::displayStatus(void) const { //shows detailed info about specific account
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

//private member functions
void    Account::_displayTimestamp(void) { //time stamp function
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
