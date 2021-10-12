#include "aresta.h"

Aresta::Aresta(Vertice *primeiro, Vertice *segundo, double peso) {
   primeiroVertice = primeiro;
   segundoVertice = segundo;
   this->peso = peso;
}

Vertice *Aresta::getPrimeiroVertice() {
   return primeiroVertice;
}

Vertice *Aresta::getSegundoVertice() {
   return segundoVertice;
}

double Aresta::getPeso() {
   return peso;
}