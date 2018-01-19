#ifndef MOVIE_HPP
#define MOVIE_HPP 
#include <string> 
#include <iostream> 

class Movie
{
public: 
    Movie(); //class constructor 
    ~Movie(); //class destructor 
    void setTitle(std::string title); 
    void setYear(int year); 
    void setDirector(std::string director); 
    void printMovieData(); 
private:
    std::string title; 
    unsigned int year; 
    std::string director; 
}; 

#endif