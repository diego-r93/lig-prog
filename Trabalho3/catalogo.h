#ifndef CATALOGO_H
#define CATALOGO_H

#include <iostream>
#include <fstream>
#include <vector>

#include "filme.h"

class Catalogo {
   friend bool operator>(const Filme &, const Filme &);                          // Comparação entre filmes
   friend bool operator==(const Filme &, const Filme &);                         // Para verificar nomes iguais
   friend bool operator>(const Filme &, const double &);                         // Para o filme mais bem avaliado

   friend const Catalogo &operator+=(Catalogo &, const Filme &);                 // Inserção
   friend const Catalogo &operator+=(Catalogo &, const std::vector <Filme> &);   // Inserção (Sobrecarga)
   friend const Catalogo &operator-=(Catalogo &, const Filme &);                 // Remoção   

   friend std::ostream &operator<<(std::ostream &, const Catalogo &);            // Impressão do catálogo  

   public:
      Catalogo();

      std::vector <Filme> getTheBest();
      void update();

      Filme *operator()(std::string);
      Filme *operator()(std::string, std::string);
      Filme *operator()(std::string, double);

   private:
      std::vector <Filme> movies;
      const static uint8_t moviesSize = 100;
};

#endif