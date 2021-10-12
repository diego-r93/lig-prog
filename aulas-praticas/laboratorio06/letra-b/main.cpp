#include <iostream>

#include "vertice.h"
#include "grafo.h"

using namespace std;

int main() {
   Grafo grafo(0.25);
   Vertice v1("L"), v2("I"), v3("N"), v4("G");

   grafo.insereVertice(v1);
   grafo.imprimeMatriz();

   grafo.insereVertice(v2);
   grafo.imprimeMatriz();

   grafo.insereVertice(v3);
   grafo.imprimeMatriz();

   grafo.insereVertice(v4);
   grafo.imprimeMatriz();

   cout << "\nCONECTIVIDADE: " << grafo.getConectividade() << endl;

   return 0;
}