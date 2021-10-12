#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <string>
#include <vector>

#include "cadastro.h"

using namespace std;

class Agenda {
   public:
      void insereCadastro(Cadastro &);
      void mostraCadastros();

   private:
      const static int maxNomes = 3;
      
      vector <Cadastro> dados;
};

#endif