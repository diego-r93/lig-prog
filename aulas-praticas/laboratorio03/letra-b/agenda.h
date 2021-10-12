#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <string>

#include "cadastro.h"

using namespace std;

class Agenda {
   public:
      void insereNome(string);
      void mostraNomes();

      static int numeroNomes;

   private:
      const static int maxNomes = 3;
      string contatos[maxNomes];
      string checkName(string);
};

#endif