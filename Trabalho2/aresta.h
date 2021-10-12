#ifndef ARESTA_H
#define ARESTA_H

#include <iostream>

#include "vertice.h"

using namespace std;

class Aresta {
   public:      
      Aresta(Vertice *, Vertice *, double = 1.0);

      Vertice *getOrigin();
      Vertice *getDestiny();
      
      double getEdgeSize();

   private:
      Vertice *origin;
      Vertice *destiny;
      double edgeSize;
};

#endif