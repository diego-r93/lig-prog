#include "vertice.h"

Vertice::Vertice(string vertex) {
   setVertex(vertex);
}

void Vertice::setVertex(string vertex) {
   this->vertex = vertex;
}

string Vertice::getVertex() {
   return vertex;
}