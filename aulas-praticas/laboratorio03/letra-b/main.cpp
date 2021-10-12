#include <iostream>
#include <string>

#include "agenda.h"

using namespace std;

int main() {
   Agenda agenda;
   string nome;

   cout << "Entre com três nomes: " << endl;
   cout << endl;

   for (int i = 0; i < 3; i++) {
      cout << "Nome [" << i << "]: ";
      getline (cin, nome);
      agenda.insereNome(nome);
   }

   //Mostrar os nomes 
   cout << "\nOs nomes da agenda são: " << endl;
   agenda.mostraNomes();

   return 0;
}