// ----------------------------------------------------------
// Proyecto: Simulador de sistema bancario
// Fecha: 12 de junio, 2024.
// Autores:
//          A01800182 Daniel Alvarez Sil.
//          A01800935 Miranda Martínez Jiménez.
// ----------------------------------------------------------

#pragma once
#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string account_number, std::string account_holder_name, double balance, double overdraft_limit)
{
    BankAccount *cuenta = this; 
    *cuenta = BankAccount(account_number, account_holder_name, balance);
    this->_overdraft_limit = overdraft_limit;
}

void CheckingAccount::withdraw(double amount)
{
    if (this->_balance - amount <= -this->_overdraft_limit)
        throw std::invalid_argument("Error: Fondos insuficientes en la cuenta para realizar el retiro. \n");
    else 
        this->_balance -= amount; 
}

std::ostream& operator <<(std::ostream& os, conts CheckingAccount& c)
{
    return BankAccount::to_string() + "Limite de sobregiro: " + std::to_string(this->_overdraft_limit) + "\n";
}