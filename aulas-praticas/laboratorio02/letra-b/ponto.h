#ifndef PONTO_H
#define PONTO_H

using namespace std;

class Ponto {
   public :
      Ponto(double = 1.0, double = 1.0, double = 1.0);

      void setCoordenadaX(double);
      void setCoordenadaY(double);
      void setCoordenadaZ(double);

      double getCoordenadaX();
      double getCoordenadaY();
      double getCoordenadaZ();

   private:
      double coordenadaX;
      double coordenadaY;
      double coordenadaZ;
};

#endif