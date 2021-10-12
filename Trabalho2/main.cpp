// Trabalho 2 de Linguagens de Programação
// Autor: Diego Rodrigues da Silva
// Compilador Utilizado: g++ 9.3.0
// GNU Make 4.2.1
// Sistema Operacional: Ubuntu 20.04.1 LTS

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "consts.h"

#include "vertice.h"
#include "aresta.h"
#include "grafo.h"

using namespace std;

bool checkOption(uint8_t);

int main(int argc, char **argv) {
   if (argc != ARGUMENTS_SIZE) {
      cout << "Invalid number of arguments." << endl;
      cout << "Use: " << argv[0] << " <OPTION>" << endl;
      exit(INVALID_ARGUMENTS_SIZE);
   }

   string input(argv[1]);
   uint8_t option = atoi(argv[1]);

   if (input.length() > 1) {
      cout << "Invalid argument size." << endl;
      cout << "Use: " << argv[0] << " <DIGIT>" << endl;
      exit(INVALID_ARGUMENT_SIZE);
   }

   else if (any_of(input.begin(), input.end(), [](char ch) { return !isdigit(ch); })) {
      cout << "Invalid argument type." << endl;
      cout << "Use: " << argv[0] << " <DIGIT>" << endl;
      exit(INVALID_ARGUMENT); 
   }   
   else if (!checkOption(option)){
      cout << "Invalid option." << endl;
      cout << "Valid options: 1, 2, 3, 4, 5, 6" << endl;
      cout << "Read the file README to understand the menu." << endl;
      exit(INVALID_OPTION);      
   }

   fstream myFile;
   string line, colname;
   double edgeSize;
   vector <Aresta *> edges;

   Grafo grafo;   

   myFile.open("dados.txt");

   if (!myFile.is_open()) {
      cout << "The chosen file does not exist." << endl;
      exit(ERROR_OPENING_FILE);
   }

   if(myFile.good()) {
      Vertice *firstVertex = nullptr;
      Vertice *secondVertex = nullptr;
      Aresta  *edge = nullptr;      

      while (getline(myFile, line)) {  
         stringstream myStream(line);

         while(getline(myStream, colname, ' ')) {
            firstVertex = new Vertice(colname);           
            getline(myStream, colname, ' ');
            secondVertex = new Vertice(colname);                     
            getline(myStream, colname);
            edgeSize = stod(colname);
            edge = new Aresta(firstVertex, secondVertex, edgeSize);
            edges.push_back(edge);      
         }            
      }
   }   
   myFile.close();

   for (auto indice: edges) {
      grafo.setAresta(indice);
   }
   
   switch (option) {
         case 1:   
            cout << "Vertex Number: " << grafo.getVertexsNumber() << endl;
            cout << "Edges Number: " << grafo.getEdgesNumber() << endl;
            break;
         case 2:
            cout<< "List of Vertexs: " << endl;
            for (auto indice: grafo.getVertexsNames()) {
            cout << indice << endl;
            }
            break;
         case 3:

            break;
         case 4:
            
            break;
         case 5:
            cout << "The vertex with the highest degree centrality is: "
                 << grafo.getCentralityDegree().getVertex() << endl;
            break;
         case 6:
            
            break;
      }

   return OKAY;
}

bool checkOption(uint8_t option)
{
   if (option >= 1 && option <= 6) {      
      return true;
   }
   else {
      return false;
   }
}