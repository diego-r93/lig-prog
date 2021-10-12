#include "grafo.h"

Grafo::Grafo(double p) : matriz(NULL), probabilidadeAresta(p), numArestas(0) {
   srand(time(0));
}

Grafo::~Grafo() {
   zerarMatriz();
}

void Grafo::insereVertice(Vertice &v) {
   vertices.push_back(v);
   popularMatriz();
}

void Grafo::zerarMatriz() {
   for (unsigned long i = 0; i < vertices.size() - 1; i++)
   {
      free(matriz[i]);
   }
   free(matriz);
}

void Grafo::popularMatriz() {
   numArestas = 0;
   int **matrizNova = (int **)malloc(vertices.size() * sizeof(int *));
   for (unsigned long i = 0; i < vertices.size(); i++)
      matrizNova[i] = (int *)malloc(vertices.size() * sizeof(int));
   for (unsigned long i = 0; i < vertices.size(); i++) {
      for (unsigned long j = 0; j < vertices.size(); j++) {
         unsigned ultimoVertice = vertices.size() - 1;
         if ((i == ultimoVertice) || (j == ultimoVertice))
            matrizNova[i][j] = existeAresta(i, j);
         else
            matrizNova[i][j] = matriz[i][j];
         numArestas += matrizNova[i][j];
      }
   }

   if (vertices.size() > 1)
      zerarMatriz();
   matriz = matrizNova;
}

int Grafo::existeAresta(int i, int j) {
   if ((i == j) || ((static_cast<double>(rand() % 101)) / 100 > probabilidadeAresta))
      return 0;
   else
      return 1;
}

double Grafo::getConectividade() {
   return static_cast<double>(numArestas) / (vertices.size() * (vertices.size() - 1));
}

void Grafo::imprimeMatriz() {
   cout << setw(3) << " ";
   for (unsigned long i = 0; i < vertices.size(); i++) {
      cout << left << setw(3) << vertices.at(i).getRotulo();
   }   
   cout << endl;

   for (unsigned long i = 0; i < vertices.size(); i++) {
      cout << setw(3) << vertices.at(i).getRotulo();
      for (unsigned long j = 0; j < vertices.size(); j++) {
         cout << left << setw(3) << matriz[i][j];
      }
      cout << endl;
   }
}