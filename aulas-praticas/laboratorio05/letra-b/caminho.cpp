#include "caminho.h"

void Caminho::insereEnlace(Aresta *aresta) {
   if (!caminhos.size()) {
      caminhos.push_back(aresta);
      cout << "Aresta (" << aresta->getPrimeiroVertice()->getRotulo()
           << ", " << aresta->getSegundoVertice()->getRotulo()
           << ") inserida no caminho..." << endl;
   }
   else {
      if (aresta->getPrimeiroVertice() == caminhos.at(caminhos.size() - 1)->getSegundoVertice()) {
         caminhos.push_back(aresta);
         cout << "Aresta (" << aresta->getPrimeiroVertice()->getRotulo()
              << ", " << aresta->getSegundoVertice()->getRotulo()
              << ") inserida no caminho..." << endl;
      }
      else
         cout << "Aresta (" << aresta->getPrimeiroVertice()->getRotulo()
              << ", " << aresta->getSegundoVertice()->getRotulo()
              << ") NÃO pode ser inserida no caminho..." << endl;
   }
}

void Caminho::imprimeCaminho() {
   cout << "Caminho: ";
   for (unsigned i = 0; i < caminhos.size(); i++)
      cout << caminhos.at(i)->getPrimeiroVertice()->getRotulo() << " -- ";
   cout << caminhos.at(caminhos.size() - 1)->getSegundoVertice()->getRotulo() << endl;
   cout << "Distância: " << calculaDistancia() << endl;
}

double Caminho::calculaDistancia() {
   double distancia = 0;
   for (unsigned i = 0; i < caminhos.size(); i++)
      distancia += caminhos.at(i)->getPeso();
   return distancia;
}