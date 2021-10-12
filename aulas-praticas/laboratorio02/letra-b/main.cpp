#include <iostream>

#include "linha.h"
#include "ponto.h"

using namespace std;

void printCoordenadas(Ponto ponto) {
   static int count = 1;

   cout << "[Impressao no. " << count
   << "] : Coordenadas do ponto (" << ponto.getCoordenadaX()
   << ", " << ponto.getCoordenadaY()
   << ", " << ponto.getCoordenadaZ()
   << ")" << endl;
   count++;
}

int main() {
   Ponto p1 (2, 2, 1);
   Ponto p2;
   Linha linha (p1, p2);

   printCoordenadas(p1);
   printCoordenadas(p2);

   cout << "== O comprimento da linha é: " << linha.getComprimento () << endl;
   cout << "\nNovas coordenadas para p2...\n" << endl;

   p2.setCoordenadaX(2);
   printCoordenadas (p2);
   linha.setPonto2 (p2);
   cout << "== O novo comprimento da linha é: " << linha.getComprimento () << endl;

   return 0;
}