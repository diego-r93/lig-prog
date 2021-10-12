#include "nacional.h"

void Nacional::setEstado(Estadual estado) {
   estados.push_back(estado);
}

vector <Estadual> Nacional::getEstados() {
   return estados;
}

double Nacional::calcularMediaMovelBrasil(int qtDias, int diaEscolhido) {
   double totalMedias = 0;

   for (auto indice: estados) {
      totalMedias += indice.getMediaMovel(qtDias, diaEscolhido);
   }

   return totalMedias;
}

double Nacional::calcularEstabilidadeBrasil(int qtDias, int diaEscolhido) {
   return 
      calcularMediaMovelBrasil(qtDias, diaEscolhido)/calcularMediaMovelBrasil(qtDias, diaEscolhido - 1);   
}

Estadual Nacional::calcularMaiorAlta(int qtDias, int diaEscolhido) {
   double maiorAlta = 0;
   double tempAlta = 0;
   Estadual estadoMaiorAlta;

   for (auto indice: estados) {
      tempAlta = indice.getEstabilidade(qtDias, diaEscolhido);

      if (tempAlta > maiorAlta)
      {
         maiorAlta = tempAlta;
         estadoMaiorAlta = indice;
      }       
   }

   return estadoMaiorAlta;
}

Estadual Nacional::calcularMaiorBaixa(int qtDias, int diaEscolhido) {
   double maiorBaixa = 1;
   double tempBaixa = 0;
   Estadual estadoMaiorBaixa;

   for (auto indice: estados) {
      tempBaixa = indice.getEstabilidade(qtDias, diaEscolhido);

      if (tempBaixa < maiorBaixa)
      {
         maiorBaixa = tempBaixa;
         estadoMaiorBaixa = indice;
      }       
   }

   return estadoMaiorBaixa;
} 

int Nacional::calcularTotalBrasil() {
   int totalMortes = 0;

   for (auto indice: estados){
      totalMortes += indice.getTotalObitos();
   }

   return totalMortes;
}