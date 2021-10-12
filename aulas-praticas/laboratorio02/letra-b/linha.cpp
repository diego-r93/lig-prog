#include "linha.h"

Linha::Linha(Ponto p1, Ponto p2) {
   ponto1 = p1;
   ponto2 = p2;
}

void Linha::setPonto1(Ponto ponto) {
   ponto1 = ponto;
}
void Linha::setPonto2(Ponto ponto) {
   ponto2 = ponto;
}

double Linha::getComprimento() {   
   double distanciaX = pow(ponto1.getCoordenadaX(), 2) - pow(ponto2.getCoordenadaX(), 2);
   double distanciaY = pow(ponto1.getCoordenadaY(), 2) - pow(ponto2.getCoordenadaY(), 2);
   double distanciaZ = pow(ponto1.getCoordenadaZ(), 2) - pow(ponto2.getCoordenadaZ(), 2);

   double comprimento = sqrt(distanciaX + distanciaY + distanciaZ);

   return comprimento;
}