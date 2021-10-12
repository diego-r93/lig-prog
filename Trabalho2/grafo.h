#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <queue>

#include "aresta.h"

using namespace std;

class Grafo{
    public:
        void setAresta(Aresta *);

        vector <string> getVertexsNames();
        int getVertexsNumber();
        int getEdgesNumber();

        // double Grafo::dijkstra(string, string);
        Vertice getCentralityDegree();
        // Vertice getCentralityIntermediation();

    private:
        vector <Aresta *> arestas;
};

#endif