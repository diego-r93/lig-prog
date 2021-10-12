#ifndef PARALELEPIPEDO_H
#define PARALELEPIPEDO_H

#include <iostream>

using namespace std;

class Paralelepipedo {
   public:
      Paralelepipedo(double, double, double);

      void setDimensionX(double);
      void setDimensionY(double);
      void setDimensionZ(double);

      double getVolume();

   private:
      double dimensionX, dimensionY, dimensionZ;
      double computeVolume();
};

#endif