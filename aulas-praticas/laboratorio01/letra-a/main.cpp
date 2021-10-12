#include <iostream>
#include "fibonacci.h"

using namespace std;

int main(void) {
   int indiceFibonacci;

   cout << "Digite o indice da Serie de Fibonacci: ";
   cin >> indiceFibonacci;

   cout << "\nFib(" << indiceFibonacci << ") = " << calcularFibonacci(indiceFibonacci) << endl;
   
   return 0;
}