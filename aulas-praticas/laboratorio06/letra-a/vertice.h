#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <string>

using namespace std;

class Vertice {
   public:
      Vertice(string = "semrotulo");

      string getRotulo();
      string getRotulo() const;
   
   private:
      const string rotulo;
};

#endif