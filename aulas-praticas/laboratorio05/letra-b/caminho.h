#ifndef CAMINHO_H
#define CAMINHO_H

#include <iostream>
#include <vector>

#include "aresta.h"

using namespace std;

class Caminho {
   public:
      void insereEnlace(Aresta *);

      void imprimeCaminho();

      double calculaDistancia();

   private:
      vector <Aresta *> caminhos;
};

#endif