#include <iostream>
#include <string>
#include "BankAccount.hpp"

int main()
{
    BankAccount myBankAccount = BankAccount("Monil Jhaveri", "555555", 10);
    myBankAccount.deposit(550);
    myBankAccount.withdraw(20);
    myBankAccount.display();
    return 0;
}