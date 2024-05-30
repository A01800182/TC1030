// ----------------------------------------------------------
// Proyecto: Simulador de sistema bancario
// Fecha: 12 de junio, 2024.
// Autores:
//          A01800182 Daniel Alvarez Sil.
//          A01800935 Miranda Martínez Jiménez.
// ----------------------------------------------------------

#pragma once
#include "BankAccount.h"

class CheckingAccount: public BankAccount{
    private: 
        double _overdraft_limit; 
    public: 
        CheckingAccount(std::string account_number, std::string account_holder_name, double balance, double overdraft_limit);
        void withdraw(double amount);
        std::string to_string() const;
};

std::ostream& operator<<(std::ostream& os, const CheckingAccount& c);