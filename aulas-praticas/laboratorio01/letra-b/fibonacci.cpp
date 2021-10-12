#include "fibonacci.h"

void Fibonacci::setFibonacci(int indice) {
   resultado = computeFibonacci(indice);
}

int Fibonacci::getFibonacci() {
   return resultado;
}

int Fibonacci::computeFibonacci(int indice) {
   if (indice == 0) {
      return indice;
   }
   else if (indice == 1) {
      return indice;
   }
   else {
      return computeFibonacci(indice - 1) + computeFibonacci(indice - 2);
   }
}