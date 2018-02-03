#include <iostream>
#include <string>
#include "Person.hpp"
#include "BankAccount.hpp"
#include "List.hpp"

void addage(int &item);
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
    List L0;
    List L1(3);
    std::cout << " Is empty " << L0.isEmpty() << std::endl;
    std::cout << " Is full " << L1.isFull() << std::endl;
    L1.insert(0);
    L1.insert(0);
    L1.insert(0);
    L1.insert(0);
    std::cout << " Is full " << L1.isFull() << std::endl;
    L1.visit(addage);
    L1.display();
    return 0;
}
void addage(int &item)
{
    item += 1;
}