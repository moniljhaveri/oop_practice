#include <iostream>
#include <string>
#include "Person.hpp"
#include "BankAccount.hpp"

int main()
{
    BankAccount myBankAccount = BankAccount("Monil Jhaveri", "555555", 10);
    myBankAccount.deposit(550);
    myBankAccount.withdraw(20);
    myBankAccount.display();
    Person one;
    Person two("Smythecraft");
    one.Show();
    two.Show();
    two.FormalShow();
    return 0;
}