// ----------------------------------------------------------
// Proyecto: Simulador de sistema bancario
// Fecha: 12 de junio, 2024.
// Autores:
//          A01800182 Daniel Alvarez Sil.
//          A01800935 Miranda Martínez Jiménez.
// ----------------------------------------------------------

#include "BankAccount.h"

BankAccount::BankAccount(std::string account_number, std::string account_holder_name, double balance)
{
    this->_account_number = account_number; 
    this->_account_holder_name = account_holder_name; 
    this->_balance = balance;
}

void BankAccount::deposit(double amount)
{
    if (amount < 0)
        throw std::invalid_argument("El monto del depósito no puede ser negativo. ");
    else if (amount == 0)
        throw std::invalid_argument("El monto del depósito no puede ser cero. ");
    else 
        this->_balance += amount; 
}

void BankAccount::withdraw(double amount)
{
    // if (this->_balance - amount <= 0)
    //     throw std::invalid_argument("Fondos insuficientes en la cuenta para realizar el retiro. ");
    // else if (amount < 0)
    //     throw std::invalid_argument("El monto del retiro no puede ser negativo. ");
    // else if (amount == 0)
    //     throw std::invalid_argument("Error: El monto del retiro no puede ser cero. ");
    // else
    if (amount < 0) 
        throw std::invalid_argument("El monto del retiro no puede ser negativo. ");
    else if (amount == 0)
        throw std::invalid_argument("El monto del retiro no puede ser cero. ");
    else
        this->_balance -= amount; 
}

std::string BankAccount::to_string() const
{
   long int ibalance = static_cast<int>(this->_balance);
    long int dbalance = std::ceil(1000 * (this->_balance - ibalance))/10;
    std::string sbalance = "00";
    if (dbalance != 0)
        sbalance = std::to_string(dbalance);
    return "Número de cuenta: " + this->_account_number
        + "\nTitular de la cuenta: " + this->_account_holder_name
        + "\nSaldo: $" + std::to_string(ibalance) + "." + sbalance + "\n";
}

std::ostream& operator<<(std::ostream& os, const BankAccount& b)
{
    return os << b.to_string();
}