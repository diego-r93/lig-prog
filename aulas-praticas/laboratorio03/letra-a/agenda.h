#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Agenda {
   public: 
      Agenda(int = 3);

      void insereNome(string);
      void mostraNomes();

   private:
      vector <string> contatos;
      string checkName(string);

      unsigned long maxNomes;
};

#endif