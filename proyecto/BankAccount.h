// ----------------------------------------------------------
// Proyecto: Simulador de sistema bancario
// Fecha: 12 de junio, 2024.
// Autores:
//          A01800182 Daniel Alvarez Sil.
//          A01800935 Miranda Martínez Jiménez.
// ----------------------------------------------------------

#pragma once 
#include <string>

class BankAccount{
    private: 
        std::string _account_number; 
        std::string _account_holder_name; 
        double _balance; 
    public: 
        BankAccount(std::string account_number, std::string account_holder_name, double balance);
        virtual void deposit(double amount); 
        virtual void withdraw(double amount); 
        std::string to_string() const; 
};

std::ostream& operator<<(std::ostream& os, const BankAccount& b);