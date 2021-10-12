#ifndef CADASTRO_H
#define CADASTRO_H

#include <iostream>
#include <string>

using namespace std;

class Cadastro {
   public:
      void setNome(string);
      string getNome();

      void setProfissao(string);
      string getProfissao();

      void setIdade(int);
      int getIdade();

   private:
      string nome, profissao;
      int idade;

      string checkName(string);
};

#endif