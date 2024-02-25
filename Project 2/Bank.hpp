/*
Author: Kevin Weng
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3, task B, Starting an Account
*/

#ifndef BANK_HPP // guards 
#define BANK_HPP // makes sure it doesn't re-define the same function. Makes sure they are only included once in the cpp file

#include "Account.hpp" // anything from your Account.hpp file will be included here
#include <iostream>
#include <string>

class Bank {
    public:
        Bank();
        std::string createAccount(std::string first_name, std::string last_name, std::string pin);
        bool removeAccount(std::string account_number);
        bool withdraw(int amount, std::string account_number, std::string pin);
        bool deposit(int amount, std::string account_number, std::string pin);
        int getAccountBalance(std::string account_number, std::string pin);

    private:
        Account Accounts[200];
        int total_existing_accounts;

};
#endif

