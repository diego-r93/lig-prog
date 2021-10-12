#include "agenda.h"

int Agenda::numeroNomes = 0;

void Agenda::insereNome(string nome) {
   nome = checkName(nome);

   if (numeroNomes >= maxNomes) {
      cout << "Agenda cheia!" << endl;
   }
   else {
      contatos[numeroNomes++] = nome;
   }
}

void Agenda::mostraNomes() {
   for (string nome: contatos) {
      cout << nome << endl;
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