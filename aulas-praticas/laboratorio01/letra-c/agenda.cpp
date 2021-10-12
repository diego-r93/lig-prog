#include "agenda.h"

void Agenda::setNames() {
   string name;

   for (int i = 0; i < 3; i++) {
      cout << "Digite o " << (i + 1) << "° nome: ";
      getline(cin, name);
      names[i] = checkName(name);
   }
}

void Agenda::getNames() {
   cout << "\nNomes presentes na agenda: " << endl;

   for (int i = 0; i < 3; i++) {
      cout << names[i] << endl;
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