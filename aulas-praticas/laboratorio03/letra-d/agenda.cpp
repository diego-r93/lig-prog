#include "agenda.h"

void Agenda::insereCadastro(Cadastro &cadastro) {
   if (dados.size() >= maxNomes) {
      cout << "Agenda cheia!" << endl;
   }
   else {
      dados.push_back(cadastro);
   }
}

void Agenda::mostraCadastros() {
   for (auto nome: dados) {
      cout << "----------------------------------" << endl;
      cout << "Nome: " << nome.getNome() << endl;
      cout << "Profissao: " << nome.getProfissao() << endl;
      cout << "Idade: " << nome.getIdade() << endl;
   }
}