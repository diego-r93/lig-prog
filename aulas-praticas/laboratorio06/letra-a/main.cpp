#include <iostream>
#include <string>

#include "vertice.h"

using namespace std;

int main() {
   Vertice vertice("A");
   const Vertice constVertice("B");

   cout << "Vertice: " << vertice.getRotulo() << endl;
   cout << "Const Vertice: " << constVertice.getRotulo() << endl;

   return 0;
}