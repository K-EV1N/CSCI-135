/*
Author: Kevin Weng
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Project 3, task B, Starting an Account
*/

#include "Bank.hpp" // anything from your Bank.hpp file will be included here
#include "Account.hpp"


Bank::Bank() {
    total_existing_accounts = 0;
}

std::string Bank::createAccount(std::string first_name, std::string last_name, std::string pin) {
    if(total_existing_accounts < 200) {
        Accounts[total_existing_accounts] = Account(first_name, last_name, pin);
        total_existing_accounts++;
        return Accounts[total_existing_accounts - 1].getAccountNumber();
        }
        return "-1";
    } 


bool Bank::removeAccount(std::string account_number) {
    for(int i = 0; i < total_existing_accounts; i++) {
        if(Accounts[i].getAccountNumber() == account_number) {
            Accounts[i] = Accounts[total_existing_accounts - 1];
            total_existing_accounts--;
            return true;
        }
    }
    return false;
}

bool Bank::withdraw(int amount, std::string account_number, std::string pin) {
    for(int i = 0; i < total_existing_accounts; i++) {
        if(Accounts[i].getAccountNumber() ==  account_number && Accounts[i].getPin() == pin) {
            return Accounts[i].transaction(amount * -1);
        }
    }
    return false;
}
bool Bank::deposit(int amount, std::string account_number, std::string pin) {
    for(int i = 0; i < total_existing_accounts; i++) {
        if(Accounts[i].getAccountNumber() ==  account_number && Accounts[i].getPin() == pin) {
            return Accounts[i].transaction(amount);
        }
    }
    return false;
}

int Bank::getAccountBalance(std::string account_number, std::string pin) {
    for(int i = 0; i < total_existing_accounts; i++) {
        if(Accounts[i].getAccountNumber() ==  account_number && Accounts[i].getPin() == pin) {
            return Accounts[i].getBalance();
        }
    }
    return -1;
}   