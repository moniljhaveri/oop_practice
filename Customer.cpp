#include <string> 
#include "Customer.hpp"
#include <iostream> 

Customer::Customer(){} 
Customer::~Customer(){}
void Customer::setFirstName(std::string firstName){
    this->firstName = firstName; 
}
void Customer::setLastName(std::string lastName){ 
    this->lastName = lastName; 
}
void Customer::setCreditLimit(int creditLimit){
    if (creditLimit < 10000){
        this->creditLimit = creditLimit; 
    } else {
        this->creditLimit = 0; 
    }
}
void Customer::setCustomerId(int customerID){
    this->customerID = customerID; 
}
void Customer::printData(){
    std::cout << "Customer Name " << this->firstName << " " << this->lastName << "CustomerID " << this->customerID << " Customer Credit Limit " << this->creditLimit << std::endl; 
}