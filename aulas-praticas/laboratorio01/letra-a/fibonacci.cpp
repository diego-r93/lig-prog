#include "fibonacci.h"

int calcularFibonacci(int indice) {
   if (indice == 0) {
      return indice;
   }
   else if (indice == 1) {
      return indice;
   }
   else {
      return calcularFibonacci(indice - 1) + calcularFibonacci(indice - 2);
   }
}