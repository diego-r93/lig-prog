#include "filme.h"

std::istream &operator>>(std::istream &input, Filme &currentMovie){

   getline(input, currentMovie.movieName);
   getline(input, currentMovie.filmProducer);

   input >> currentMovie.grade;

   return input;
}

std::ostream &operator<<(std::ostream &output, const Filme &currentMovie){
   output << "\nMovie: " << currentMovie.movieName << std::endl;
   output << "Film Producer: " << currentMovie.filmProducer << std::endl;
   output << "Grade: " << currentMovie.grade << std::endl;
   output << std::endl;

   return output;
}