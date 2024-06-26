// ----------------------------------------------------------
// Proyecto: Simulador de sistema bancario
// Fecha: 12 de junio, 2024.
// Autores:
//          A01800182 Daniel Alvarez Sil.
//          A01800935 Miranda Martínez Jiménez.
// ----------------------------------------------------------

#include "SavingsAccount.h"
#include <stdexcept>

SavingsAccount::SavingsAccount(std::string account_number, std::string account_holder_name, double balance, double interest_rate)
    : BankAccount(account_number, account_holder_name, balance), _interest_rate(interest_rate) {}

void SavingsAccount::deposit(double amount) {
//     if (amount < 0) {
//         throw std::invalid_argument("El monto del depósito no puede ser negativo. ");
//     } else if (amount == 0) {
//         throw std::invalid_argument("El monto del depósito no puede ser cero. ");
//     }
    BankAccount::deposit(amount);  
    _balance += _balance * (_interest_rate / 100); 
}

void SavingsAccount::withdraw(double amount) {
    // if (amount < 0) 
    //     throw std::invalid_argument("El monto del retiro no puede ser negativo. ");
    /*else*/ if (_balance < amount) 
        throw std::invalid_argument("Fondos insuficientes en la cuenta de ahorros. ");
    // else if (amount == 0)
    //     throw std::invalid_argument("El monto del retiro no puede ser cero. ");
    else
        BankAccount::withdraw(amount);  
}