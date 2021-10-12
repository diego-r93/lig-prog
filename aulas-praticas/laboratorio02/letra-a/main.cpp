#include <iostream>
#include "paralelepipedo.h"

using namespace std;

int main() {
   double dimensionX = 1.23;
   double dimensionY = 4.56;
   double dimensionZ = 7.89;

   Paralelepipedo paralelepipedo(dimensionX, dimensionY, dimensionZ);

   cout << "\nO volume é: " << paralelepipedo.getVolume() << endl;
    
   cout << "\nMudando os valores das dimensões..." << endl;

   paralelepipedo.setDimensionX(-1);
   paralelepipedo.setDimensionY(3.3);
   paralelepipedo.setDimensionZ(4.4);

   cout << "\nO novo volume é: " << paralelepipedo.getVolume() << "\n\n";

   return 0;
}