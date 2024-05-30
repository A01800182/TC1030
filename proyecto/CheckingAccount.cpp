// ----------------------------------------------------------
// Proyecto: Simulador de sistema bancario
// Fecha: 12 de junio, 2024.
// Autores:
//          A01800182 Daniel Alvarez Sil.
//          A01800935 Miranda Martínez Jiménez.
// ----------------------------------------------------------

#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string account_number, std::string account_holder_name, double balance, double overdraft_limit):
 BankAccount(account_number, account_holder_name, balance)
{
    this->_overdraft_limit = overdraft_limit; 
}

void CheckingAccount::withdraw(double amount)
{
    if (this->_balance - amount <= -this->_overdraft_limit)
        throw std::invalid_argument("Se superó el límite de sobregiro. ");
    //  else if (amount < 0) 
    //     throw std::invalid_argument("El monto del retiro no puede ser negativo");
    // else if (amount == 0)
    //     throw std::invalid_argument("El monto del retiro no puede ser cero. ");
    else
        BankAccount::withdraw(amount); 
}

std::string CheckingAccount::to_string() const
{
    return BankAccount::to_string() + "Limite de sobregiro: " + std::to_string(this->_overdraft_limit) + "\n";
}

std::ostream& operator <<(std::ostream& os, const CheckingAccount& c)
{
    return os << c.to_string();
}