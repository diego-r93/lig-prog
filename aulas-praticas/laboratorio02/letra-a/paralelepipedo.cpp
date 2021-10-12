#include "paralelepipedo.h"

Paralelepipedo::Paralelepipedo(double x, double y, double z) {
    setDimensionX(x);
    setDimensionY(y);
    setDimensionZ(z);
}

void Paralelepipedo::setDimensionX(double x) {
   if (x > 0)
      dimensionX = x;
   else
      dimensionX = 1;
}

void Paralelepipedo::setDimensionY(double y) {
   if (y > 0)
      dimensionY = y;
   else
      dimensionY = 1;
}

void Paralelepipedo::setDimensionZ(double z) {
   if (z > 0)
      dimensionZ = z;
   else
      dimensionZ = 1;
}

double Paralelepipedo::getVolume() {
   return computeVolume();
}

double Paralelepipedo::computeVolume() {
   return dimensionX * dimensionY * dimensionZ;
}