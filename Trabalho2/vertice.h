#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <vector>

using namespace std;

class Vertice {
   public:
      Vertice(string);

      void setVertex(string);
      string getVertex();
      
   private:
      string vertex;
};

#endif