#include <iostream>

#include "relogio.h"

using namespace std;

int main() {
   Relogio pontual;
   Relogio atrasado(8, 10, 30);
   
   cout << "pontual: "; 
   pontual.mostreHorario ();
   cout << "atrasado: "; 
   atrasado.mostreHorario ();
   
   pontual.resetHora(1, 2, 59);
   atrasado.resetHora();
   
   cout << endl;
   cout << "pontual: ";
   pontual.mostreHorario ();
   cout << "atrasado: "; 
   atrasado.mostreHorario ();

   return 0;
}