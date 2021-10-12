#include <iostream>
#include <string>

#include "agenda.h"

using namespace std;

int main() {
   Agenda agenda;
   string nome, profissao;
   int idade;

   cout << "Entre com três cadastros: " << endl;
   cout << endl;

   for (int i = 0; i < 3; i++) {
      Cadastro cadastro;

      cout << "Nome [" << i << "]: ";
      getline (cin, nome);
      cadastro.setNome(nome);

      cout << "Profissao [" << i << "]: ";
      getline (cin, profissao);
      cadastro.setProfissao(profissao);

      cout << "Idade [" << i << "]: ";
      cin >> idade;
      cin.ignore();
      cadastro.setIdade(idade);

      agenda.insereCadastro(cadastro);

      if (i < 2) {
         cout << "\nInsira o proximo cadastro:" << endl;
      }
   }

   //Mostrar os nomes 
   cout << "\nOs cadastros da agenda são: " << endl;
   agenda.mostraCadastros();

   return 0;
}