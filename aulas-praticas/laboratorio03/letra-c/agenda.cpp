#include "agenda.h"

int Agenda::numeroNomes = 0;

void Agenda::insereCadastro(Cadastro &cadastro) {
   if (numeroNomes >= maxNomes) {
      cout << "Agenda cheia!" << endl;
   }
   else {
      nomes[numeroNomes++] = cadastro;
   }
}

void Agenda::mostraCadastros() {
   for (auto nome: nomes) {
      cout << "----------------------------------" << endl;
      cout << "Nome: " << nome.getNome() << endl;
      cout << "Profissao: " << nome.getProfissao() << endl;
      cout << "Idade: " << nome.getIdade() << endl;
   }
}