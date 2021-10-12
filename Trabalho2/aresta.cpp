#include "aresta.h"

Aresta::Aresta(Vertice *first, Vertice *second, double edgeSize) {
   origin = first;
   destiny = second;
   this->edgeSize = edgeSize;
}

Vertice *Aresta::getOrigin() {
   return origin;
}

Vertice *Aresta::getDestiny() {
   return destiny;
}

double Aresta::getEdgeSize() {
   return edgeSize;
}