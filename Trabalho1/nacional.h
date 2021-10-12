#ifndef NACIONAL_H
#define NACIONAL_H

#include <vector>
#include <string>

#include "estadual.h"

using namespace std;

class Nacional {
   public:
      void setEstado(Estadual);

      vector <Estadual> getEstados();

      double calcularMediaMovelBrasil(int, int);

      double calcularEstabilidadeBrasil(int, int);

      Estadual calcularMaiorAlta(int, int);
      
      Estadual calcularMaiorBaixa(int, int); 

      int calcularTotalBrasil();

   private:
      vector <Estadual> estados;
};

#endif