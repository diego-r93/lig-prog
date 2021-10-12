#ifndef ARESTA_H
#define ARESTA_H

#include <iostream>

#include "vertice.h"

using namespace std;

class Aresta {
   public:
      Aresta(Vertice *, Vertice *, double = 1.0);

      Vertice *getPrimeiroVertice();
      Vertice *getSegundoVertice();

      double getPeso();

   private:
      Vertice *primeiroVertice, *segundoVertice;
      double peso;
};

#endif