// ----------------------------------------------------------
// Proyecto: Simulador de sistema bancario
// Fecha: 12 de junio, 2024.
// Autores:
//          A01800182 Daniel Alvarez Sil.
//          A01800935 Miranda Martínez Jiménez.
// ----------------------------------------------------------

#pragma once
#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private:
    double _interest_rate;
public:
    SavingsAccount(std::string account_number, std::string account_holder_name, double balance, double interest_rate);

    // Sobrescribir método deposit
    void deposit(double amount) override;

    // Sobrescribir método withdraw
    void withdraw(double amount) override;
};

