#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <vector>

using namespace std;

class Vertice {
   public:
      Vertice(string);

      string getRotulo();
      
   private:
      string rotulo;
};

#endif