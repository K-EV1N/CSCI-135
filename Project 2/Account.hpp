/*
Author: Kevin Weng
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3, task A, Opening an Account
 */

#ifndef ACCOUNT_HPP // guards 
#define ACCOUNT_HPP // makes sure it doesn't re-define the same function. Makes sure they are only included once in the cpp file

#include <iostream>
#include <string>


class Account { // creating a class object will run the constructor by itself
    public:
        //Default Constructor
        Account(); 
        Account(std::string first_name, std::string last_name, std::string pin); // Parameterized Constructor

        // Mutators -- they just set things
        void setFirstName(std::string first_name);
        void setLastName(std::string last_name);
        bool setPin(std::string pin);

        // Accessors -- they get the information
        std::string getFirstName();
        std::string getLastName();
        std::string getPin();
        std::string getAccountNumber();
        int getBalance();

        // Transaction
        bool transaction(int amount);

    private:
        std::string generateAccountNumber();
        std::string first_name_;
        std::string last_name_;
        std::string account_number_;
        std::string pin_number_;
        int account_balance_;
};
#endif