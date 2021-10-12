#include <iostream>
#include "fibonacci.h"

using namespace std;

int main(void) {
   Fibonacci fibonacci;
   int indiceFibonacci;

   cout << "Digite o indice da Serie de Fibonacci: ";
   cin >> indiceFibonacci;

   fibonacci.setFibonacci(indiceFibonacci);

   cout << "\nFib(" << indiceFibonacci << ") = " << fibonacci.getFibonacci() << endl;
   
   return 0;
}