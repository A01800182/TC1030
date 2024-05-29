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