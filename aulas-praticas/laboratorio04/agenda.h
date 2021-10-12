#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

#include "contato.h"

using namespace std;

class Agenda {
   public:
      Agenda(int = 3);

      void insereContato(string, string, int);
      void removeContato(string);

      void editaIdadeContato(string, int);
      void editaProfissaoContato(string, string);

      bool existeContato(string);

      void mostraContatos();

      void lerArquivo();
      void escreveArquivo();

   private:
      vector <Contato> contatos;
      unsigned tamMaxAgenda;
      unsigned tamMaxNome;

      fstream file;
      string nomeArquivo;

      string verificaNome(string);
};

#endif