// Trabalho 1 de Linguagens de Programação
// Autor: Diego Rodrigues da Silva
// Compilador Utilizado: g++ 9.3.0
// GNU Make 4.2.1
// Sistema Operacional: Ubuntu 20.04.1 LTS

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>

#include "nacional.h"

#define ERRO_ABRINDO_ARQUIVO  1

using namespace std;

int main() {
   Estadual estado;
   string siglaEstado;
   Nacional Brasil;
   
   fstream myFile;
   string line, colname;

   int menuOpcao;
   int qtDias, diaEscolhido;
   double estabilidade;

   myFile.open("dados.csv");

   if (!myFile.is_open()){
      cout << "O arquivo escolhido não existe." << endl;
      return ERRO_ABRINDO_ARQUIVO;
   }

   if(myFile.good()) {
      pair <string, vector <int>> dados;

      while (getline(myFile, line)) {  
         stringstream myStream(line);

         getline(myStream, colname, ',');
         dados.first = colname;

         while (getline(myStream, colname, ',')) {
            dados.second.push_back(stoi(colname));
         }

         estado.setEstado(dados.first);
         estado.setMortesDiarias(dados.second);
         Brasil.setEstado(estado);
         dados = {};
         // free(&dados); // Tem diferença??
      }
   } 

   myFile.close();

   cout << fixed << setprecision(2);      

   cout << "------------------- MENU ------------------------" << endl;
   cout << "1 - Mostra a media movel do Brasil" << endl;
   cout << "2 - Mostra media movel dos estados" << endl;
   cout << "3 - Mostra a estabilidade do Brasil " << endl;
   cout << "4 - Mostra a estabilidade dos estados" << endl;
   cout << "5 - Mostra estados com maior alta e maior baixa" << endl;
   cout << "6 - Mostra o numero de obitos no Brasil" << endl;
   cout << "7 - Mostra o numero de obitos em cada estado" << endl;
   cout << "8 - Sair" << endl;
   cout << "-------------------------------------------------" << endl;
   cout << ">>> ";

   cin >> menuOpcao;

   switch (menuOpcao) {
      case 1:
      case 2:
      case 3:
      case 4:
         cout << "Digite a quantidade de dias da media movel: ";
         cin >> qtDias;
         cout << "Digite o dia da media movel: ";
         cin >> diaEscolhido;
   }
   

   switch (menuOpcao) {         
      case 1:         
         cout << "Media movel do Brasil: ";
         cout << Brasil.calcularMediaMovelBrasil(qtDias, diaEscolhido) << endl;
         break;
      case 2:
         for (auto indice: Brasil.getEstados()) {
            cout << indice.getEstado() << " - ";
            cout << indice.getMediaMovel(qtDias, diaEscolhido) << endl;
         }
         break;
      case 3:
         estabilidade = Brasil.calcularEstabilidadeBrasil(qtDias, diaEscolhido);            
         cout << "Estabilidade do Brasil: ";
         cout << estabilidade << endl;
         if (estabilidade <= 0.9) {
            cout << "Baixa de casos" << endl;
         }
         else if (estabilidade >= 1.1) {
            cout << "Alta de casos" << endl;
         }
         else {
               cout << "Estabilidade de casos" << endl;
            }
         break;
      case 4:
         for (auto indice: Brasil.getEstados()) {
            cout << indice.getEstado() << " - ";
            estabilidade = indice.getEstabilidade(qtDias, diaEscolhido);
            cout << estabilidade << " --- ";
            if (estabilidade <= 0.9) {
               cout << "Baixa de casos" << endl;
            }
            else if (estabilidade >= 1.1) {
               cout << "Alta de casos" << endl;
            }
            else {
               cout << "Estabilidade de casos" << endl;
            }
         }   
         break;
      case 5:
         cout << "Estado com maior alta: ";
         cout << Brasil.calcularMaiorAlta(3, 10).getEstado() << endl;
         cout << "Estado com maior baixa: ";
         cout << Brasil.calcularMaiorBaixa(3, 10).getEstado() << endl;
         break;
      case 6:
         cout << "Total de Obitos no Brasil: ";
         cout << Brasil.calcularTotalBrasil() << endl;
         break;
      case 7:
         for (auto indice: Brasil.getEstados()) {
            cout << indice.getEstado() << " - ";
            cout << indice.getTotalObitos() << endl;
         }
         break;
      case 8:
         break;
      default:
         cout << "Opcao invalida." << endl;
   }      

   return 0;
}