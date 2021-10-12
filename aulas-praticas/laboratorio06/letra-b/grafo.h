#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "vertice.h"

using namespace std;

class Grafo {
   public:
      Grafo(double);
      ~Grafo();

      void insereVertice(Vertice &);

      double getConectividade();

      void imprimeMatriz();

   private:
      int **matriz;
      vector <Vertice> vertices;
      double probabilidadeAresta;
      int numArestas;

      void zerarMatriz();
      void popularMatriz();

      int existeAresta(int, int);
};

#endif