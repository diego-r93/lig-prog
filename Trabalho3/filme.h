#ifndef FILME_H
#define FILME_H

#include <iostream>
#include <string>

typedef struct {
   std::string movieName;
   std::string filmProducer;
   double grade;
} Filme;

std::istream &operator>>(std::istream &, Filme &);
std::ostream &operator<<(std::ostream &, const Filme &);

#endif