
#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include <iostream> 
#include <string> 

class Customer
{
public: 
    Customer(); 
    ~Customer();
    void setCustomerId(int customerId); 
    void setCreditLimit(int creditLimit); 
    void setFirstName(std::string firstName); 
    void setLastName(std::string lastName); 
    void printData(); 
private: 
    int customerID; 
    int creditLimit; 
    std::string firstName; 
    std::string lastName; 
}; 
#endif 