#include <iostream>
#include <string>

#include "nacional.h"

using namespace std;

void Estadual::setEstado(string estado) {
   nomeEstado = estado;
}

string Estadual::getEstado() {
   return nomeEstado;
}

void Estadual::setMortesDiarias (vector <int> mortesDiarias) {
   serieHistorica = mortesDiarias;
}

vector <int> Estadual::getMortesDiarias() {
   return serieHistorica;
}

double Estadual::getMediaMovel(int qtDias, int diaEscolhido) {   
   return computeMediaMovel(qtDias, diaEscolhido);
}

double Estadual::getEstabilidade(int qtDias, int diaEscolhido) {
   return 
      getMediaMovel(qtDias, diaEscolhido)/getMediaMovel(qtDias, diaEscolhido - 1);      
}

int Estadual::getTotalObitos() {
   return computeTotalObitos();
}

double Estadual::computeMediaMovel(int qtDias, int diaEscolhido) {
   double somaTotal = 0;

   vector <int> tempVector;

   for (int i = 0; i < diaEscolhido; i++) {
      tempVector.push_back(serieHistorica[i]);
   }

   auto reverse = tempVector.crbegin();

   for (int indice = 0; indice < qtDias ; indice++, reverse++) {
      somaTotal += *reverse;
   }

   return somaTotal/qtDias;
}

int Estadual::computeTotalObitos() {
   int somaTotal = 0;

   for (auto indice: serieHistorica) {
      somaTotal += indice;
   }

   return somaTotal;
}