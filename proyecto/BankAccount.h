#pragma once 
#include <string>

class BankAccount{
    private: 
        std::string _account_numer; 
        std::string _account_holder_name; 
        double _balance; 
    public: 
        BankAccount(std::string account_number, std::string account_holder_name, int balance);
        virtual void deposit(double amount); 
        virtual void withdraw(double amount); 
        std::string to_string(); 
};