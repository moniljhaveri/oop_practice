#include <iostream> 
#include "Movie.hpp"

Movie::Movie(){

}
Movie::~Movie(){

}
void Movie::setDirector(std::string director){
    this->director = director; 
}

void Movie::setYear(int year){
    this->year = year; 
}

void Movie::setTitle(std::string title){
    this->title = title; 
}

void Movie::printMovieData(){
    std::cout << "Movie Title: "  << this->title << ", Directed by " << this->director << ", Released in " << this->year << std::endl; 
}