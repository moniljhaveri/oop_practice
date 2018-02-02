#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP
#include <iostream>
#include <string>

class BankAccount
{
public:
  BankAccount(std::string depositorsName, std::string accountNum, int accountBalance);
  ~BankAccount();
  void deposit(int deposit);
  void withdraw(int withdrawl);
  void display();

private:
  std::string depositorsName;
  std::string accountNum;
  int accountBalance = 0;
};
#endif