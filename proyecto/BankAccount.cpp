// ----------------------------------------------------------
// Proyecto: Simulador de sistema bancario
// Fecha: 12 de junio, 2024.
// Autores:
//          A01800182 Daniel Alvarez Sil.
//          A01800935 Miranda Martínez Jiménez.
// ----------------------------------------------------------

#include "BankAccount.h"
#include <stdexcept>

BankAccount::BankAccount(std::string account_number, std::string account_holder_name, double balance)
{
    this->_account_number = account_number; 
    this->_account_holder_name = account_holder_name; 
    this->_balance = balance;
}

void BankAccount::deposit(double amount)
{
    if (amount < 0)
        throw std::invalid_argument("Error: El monto del depósito no puede ser negativo. \n");
    else if (amount == 0)
        throw std::invalid_argument("Error: El monto del depósito no puede ser cero. \n");
    else 
        this->_balance += amount; 
}

void BankAccount::withdraw(double amount)
{
    if (this->_balance - amount < 0)
        throw std::invalid_argument("Error: Fondos insuficientes en la cuenta para realizar el retiro. \n");
    else 
        this->_balance -= amount; 
}

std::string BankAccount::to_string()
{
    long int ibalance = (this->_balance * 100);
    double dbalance = 1.00/100.00 * ibalance; 
    return "Número de cuenta: " + this->_account_number 
        + "\nTitular de la cuenta: " + this->_account_holder_name
        + "\nSaldo: $" + std::to_string(dbalance) + "\n";
}
