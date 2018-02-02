#include <iostream>
#include <string>
#include "BankAccount.hpp"

BankAccount::BankAccount(std::string depositorsName, std::string accountNum, int accountBalance)
{
    this->depositorsName = depositorsName;
    this->accountNum = accountNum;
    this->accountBalance = accountBalance;
}
BankAccount::~BankAccount() {}
void BankAccount::deposit(int deposit)
{
    this->accountBalance += deposit;
}
void BankAccount::withdraw(int withdraw)
{
    if ((this - accountBalance - withdraw) > 0)
    {
        this->accountBalance -= withdraw;
    }
}
void BankAccount::display()
{
    std::cout << "Depositor's name " << this->depositorsName << " Account Number " << this->accountNum << " Account Balance " << this->accountBalance << std::endl;
}