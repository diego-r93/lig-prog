#ifndef ESTADUAL_H
#define ESTADUAL_H

#include <vector>
#include <string>

using namespace std;

class Estadual {
   public:
      void setEstado(string estado);
      string getEstado();

      void setMortesDiarias (vector <int>);
      vector <int> getMortesDiarias ();

      double getMediaMovel(int, int);
      double getEstabilidade(int, int);

      int getTotalObitos(); 

   private:
      string nomeEstado;
      vector <int> serieHistorica;

      double computeMediaMovel(int, int);
      int computeTotalObitos();
};

#endif