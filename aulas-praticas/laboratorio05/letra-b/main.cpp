#include <iostream>
#include <vector>

#include "vertice.h"
#include "aresta.h"
#include "caminho.h"

using namespace std;

int main() {
   Vertice v1 ("A"), v2 ("B"), v3 ("C"), v4 ("D"), v5 ("E");
   Aresta a1 (&v1, &v2), a2 (&v2, &v3, 2.5), a3 (&v3, &v4, 1.5), aerr (&v5, &v3);

   Caminho caminho;

   caminho.insereEnlace(&a1);
   caminho.insereEnlace(&a2);
   caminho.insereEnlace(&a3);   
   caminho.insereEnlace(&aerr);
   
   cout << endl;
   caminho.imprimeCaminho();

   return 0;
}