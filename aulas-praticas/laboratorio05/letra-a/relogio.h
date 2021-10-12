#ifndef RELOGIO_H
#define RELOGIO_H

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

using namespace std;

class Relogio {
   public:
      Relogio();
      Relogio(int, int, int);

      void resetHora();
      void resetHora(int, int, int);

      void setSegundos(int);
      void setMinutos(int);
      void setHoras(int);

      int getSegundos();
      int getMinutos();
      int getHoras();

      void mostreHorario();
   private:
      time_t hora;
      struct tm *infoHora;
      int segundos, minutos, horas;      
};

#endif