#include "agenda.h"

Agenda::Agenda(int maxNomes) { 
   this->maxNomes = maxNomes;
}

void Agenda::insereNome(string nome) {
   nome = checkName(nome);

   if (contatos.size() > maxNomes) {
      cout << "Agenda cheia!" << endl;
   }
   else {
      contatos.push_back(nome);
   }
}

void Agenda::mostraNomes() {
   for (string s: contatos) {
      cout << s << endl;
   }
}

string Agenda::checkName(string name) {
   if (name.length() > 10) {
      name = name.substr(0, 10);
      cout << "O nome inserido é maior do que o valor máximo" << endl;
      cout << "O nome foi truncado para: " << name << endl;
   }
   return name;
}