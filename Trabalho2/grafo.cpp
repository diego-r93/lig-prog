#include <algorithm> 
#include "grafo.h"

#define INFINITY 10000000

void Grafo::setAresta(Aresta *aresta) {
   if (!arestas.size()) {
      arestas.push_back(aresta);
   }
   else {
      if (!(aresta->getOrigin()->getVertex() == aresta->getDestiny()->getVertex())) {
         arestas.push_back(aresta);         
      }
      else
         cout << "Aresta (" << aresta->getOrigin()->getVertex()
              << ", " << aresta->getDestiny()->getVertex()
              << ") NÃO pode ser inserida no caminho..." << endl;
   }
}

vector <string> Grafo::getVertexsNames() {
   vector <string> vertexs;   

   for (auto indice: arestas) {
      vertexs.push_back(indice->getOrigin()->getVertex());
      vertexs.push_back(indice->getDestiny()->getVertex());
   }

   sort(vertexs.begin(), vertexs.end());
   vertexs.erase(unique(vertexs.begin(), vertexs.end() ), vertexs.end());

   return vertexs;
}

int Grafo::getVertexsNumber() {
   return getVertexsNames().size();
}

int Grafo::getEdgesNumber() {
   return arestas.size();
}

// double Grafo::dijkstra(string origin, string destiny)
// {
//    int vertexNumber = getVertexsNumber();	
// 	double distances[vertexNumber];   
// 	string visited[vertexNumber];

// 	// fila de prioridades de pair (distancia, vértice)
// 	priority_queue <pair <double, string>, vector <pair <double, string>>, greater <pair <double, string>>> pq;

// 	// inicia o vetor de distâncias e visitados
// 	for(int i = 0; i < vertexNumber; i++)
// 	{
// 		distances[i] = INFINITY;
// 		visited[i] = false;
// 	}

// 	// a distância de orig para orig é 0
// 	distances[origin] = 0;

// 	// insere na fila
// 	pq.push(make_pair(distances[origin], origin));

// 	// loop do algoritmo
// 	while(!pq.empty())
// 	{
// 		pair <double, string> p = pq.top(); // extrai o pair do topo
// 		string u = p.second;                // obtém o vértice do pair
// 		pq.pop();                           // remove da fila

// 		// verifica se o vértice não foi expandido
// 		if(visited[u] == false)
// 		{
// 			// marca como visitado
// 			visited[u] = true;

// 			list <pair <double, string> >::iterator it;

// 			// percorre os vértices "v" adjacentes de "u"
// 			for(it = adj[u].begin(); it != adj[u].end(); it++)
// 			{
// 				// obtém o vértice adjacente e o custo da aresta
// 				int v = it->first;
// 				int custo_aresta = it->second;

// 			   // relaxamento (u, v)
// 			   if(distances[v] > (distances[u] + custo_aresta))
// 			   {
//                // atualiza a distância de "v" e insere na fila
//                distances[v] = distances[u] + custo_aresta;
//                pq.push(make_pair(distances[v], v));
// 			   }
// 			}
// 		}
// 	}
// 	// retorna a distância mínima até o destino
// 	return distances[destiny];
// }


Vertice Grafo::getCentralityDegree() {
   vector <string> vertexs;   

   for (auto indice: arestas) {
      vertexs.push_back(indice->getOrigin()->getVertex());
      vertexs.push_back(indice->getDestiny()->getVertex());
   }
   sort(vertexs.begin(), vertexs.end());

   auto last_int = vertexs.front();
   auto most_freq_int = vertexs.front();
   int max_freq = 0, current_freq = 0;

   for (const auto &i : vertexs) {
      if (i == last_int)
         ++current_freq;
      else {
         if (current_freq > max_freq) {
               max_freq = current_freq;
               most_freq_int = last_int;
         }
         
         last_int = i;
         current_freq = 1;
      }
    }

    if (current_freq > max_freq) {
        max_freq = current_freq;
        most_freq_int = last_int;
    }

    return most_freq_int;
}
