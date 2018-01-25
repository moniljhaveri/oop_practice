#include <iostream> 
#include "Movie.hpp"
#include "Customer.hpp"

int main(){
    Movie myMovie = Movie(); 
    myMovie.setTitle("Hot Fuzz"); 
    myMovie.setDirector("Edgar Wright"); 
    myMovie.setYear(2007); 
    myMovie.printMovieData(); 
    Customer newCustomer = Customer(); 
    newCustomer.setCustomerId(1); 
    newCustomer.setFirstName("Monil"); 
    newCustomer.setLastName("Jhaveri"); 
    newCustomer.setCreditLimit(1000000); 
    newCustomer.printData(); 

    return 0; 
}