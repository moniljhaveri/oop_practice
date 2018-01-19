#include <iostream> 
#include "Movie.hpp"

int main(){
    Movie myMovie = Movie(); 
    myMovie.setTitle("Hot Fuzz"); 
    myMovie.setDirector("Edgar Wright"); 
    myMovie.setYear(2007); 
    myMovie.printMovieData(); 
    return 0; 
}