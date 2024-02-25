/*
Author: Kevin Weng
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3, task A, Opening an Account
 */

#include "Account.hpp" // anything from your Account.hpp file will be included here

std::string Account::generateAccountNumber() {
    std::string an_str = "";
    for(int i{0}; i < 8; i++ ){
        int temp = rand() % 10;
        an_str += std::to_string(temp);
    }
    return an_str;
}

// default constructor
Account::Account() { // we are calling the default constructor "Account" from the class "Account"
    first_name_ = "anonymous";
    last_name_ = "anonymous";
    pin_number_ = "0000";
    account_number_ = generateAccountNumber();
    account_balance_ = 0;
} 

Account::Account(std::string first_name, std::string last_name, std::string pin) {
    first_name_ = first_name;
    last_name_ = last_name;

    if(pin.length() != 4) {
        pin_number_ = "0000";
    } else {
        pin_number_ = pin;
    }
    account_number_ = generateAccountNumber();
    account_balance_ = 0;
}

//Mutators (set)
void Account::setFirstName(std::string first_name) {
    first_name_ = first_name; 
}

void Account::setLastName(std::string last_name) {
    last_name_ = last_name;
}

bool Account::setPin(std::string pin) {
    if(pin.length() == 4) {
        pin_number_ = pin;
        return true;
    } else {
        return false;
    }
}

//Acessors (get)
std::string Account::getFirstName() {
    return first_name_;
}

std::string Account::getLastName() {
    return last_name_;
}

std::string Account::getPin() {
    return pin_number_;
}

std::string Account::getAccountNumber() {
    return account_number_;
}

int Account::getBalance() {
    return account_balance_;
}

//Transaction
bool Account::transaction(int amount) {
    if(account_balance_ + amount < 0) {
        return false;

    } else {
        account_balance_ = account_balance_ + amount;
        return true;
    }
}
