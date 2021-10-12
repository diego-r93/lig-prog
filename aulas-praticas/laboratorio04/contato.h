#ifndef CONTATO_H
#define CONTATO_H

#include <iostream>
#include <string>

using namespace std;

class Contato {
   public:
      Contato(string, string, int);

      void setNome(string);
      void setProfissao(string);
      void setIdade(int);

      string getNome();
      string getProfissao();
      int getIdade();

   private:
      string nome, profissao;
      int idade;
};

#endif