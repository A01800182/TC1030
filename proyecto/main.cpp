// ----------------------------------------------------------
// Proyecto: Simulador de sistema bancario
// Fecha: 12 de junio, 2024.
// Autores:
//          A01800182 Daniel Alvarez Sil.
//          A01800935 Miranda Martínez Jiménez.
// ----------------------------------------------------------

#include <iostream>
#include <stdexcept>
#include <vector>
// Incluir aquí las definiciones de las clases:
// BankAccount, SavingsAccount y CheckingAccount

int main()
{
    // Crear cuentas bancarias
    SavingsAccount c1(
        "SA12345", "Carmen Caramelo", 1000.0, 2.0);
    CheckingAccount c2(
        "CA54321", "Quique Queso", 500.0, 100.0);
    CheckingAccount c3(
        "CA00666", "Damien Thorn", 666.0, 66.0);
    SavingsAccount c4(
        "SA19999", "Waldo Waffles", 100.0, 9.8);
    const std::vector<BankAccount*> accounts = {
        &c1, &c2, &c3, &c4
    };

    // Probando depósitos y retiros
    for (BankAccount* account : accounts) {
        std::cout << *account << "\n";
        account->deposit(100.0);
        account->withdraw(50.0);
        std::cout << "=== Después de transacciones ===\n"
            << *account << "\n\n";
    }

    // Probando el manejo de excepciones
    try {
        c1.withdraw(2000.0);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    try {
        c2.withdraw(700.0);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    try {
        c3.withdraw(-1000.0);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    try {
        c4.deposit(-1.0);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}