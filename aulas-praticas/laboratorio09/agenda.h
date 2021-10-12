#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <string>
#include <vector>

class Agenda {
   friend std::ostream &operator<<(std::ostream &, Agenda &);

   public:
      Agenda();
      Agenda(const Agenda &);
      
      Agenda operator-(const Agenda &);
      Agenda operator+(const Agenda &);
};

#endif