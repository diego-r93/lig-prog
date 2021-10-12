#include "consts.h"
#include "catalogo.h"

bool operator>(const Filme &first, const Filme &second) {
   return first.movieName > second.movieName ? true : false;
}

bool operator==(const Filme &first, const Filme &second) {
   return first.movieName == second.movieName ? true : false;
}

bool operator>(const Filme &selectedMovie, const double &movieGrade) {
   return selectedMovie.grade > movieGrade ? true : false;
}

const Catalogo &operator+=(Catalogo &catalogo, const Filme &chosenMovie) {
   bool repeated = false;

   if (catalogo.movies.size() == 0) {
      catalogo.movies.push_back(chosenMovie);
   }   

   for (auto indice: catalogo.movies) {
      if (indice == chosenMovie) 
         repeated = true;
   }
   
   if (!repeated) {
      uint8_t index = 0;
      for (auto indice: catalogo.movies) {
         // Insere no começo
         if (indice > chosenMovie and index == 0) {
            catalogo.movies.insert(catalogo.movies.begin(), chosenMovie);
            break;
         }
         // Insere no meio
         else if (indice > chosenMovie) {
            catalogo.movies.insert(catalogo.movies.begin() + index, chosenMovie);
            break;
         }
         // Insere no final
         else if (index == catalogo.movies.size() - 1) {
            catalogo.movies.push_back(chosenMovie);
            break;
         }

         index++;
      }
   }
   else {
      std::cout << "This movie has already been inserted." << std::endl;
   }
    
   return catalogo;
}

const Catalogo &operator+=(Catalogo &catalogo, const std::vector <Filme> &insertedMovies) {
   if (catalogo.movies.size() == 0) 
      catalogo.movies.insert(catalogo.movies.end(), insertedMovies.begin(), insertedMovies.end());

   else if (catalogo.movies.size() + 1 > catalogo.moviesSize) 
      std::cout << "Maximum size exceeded." << std::endl;

   else {
      for (auto insertedMovie: insertedMovies) {

         bool repeated = false;
         
         for (auto movie: catalogo.movies) {
            if (movie == insertedMovie) 
               repeated = true;
         }

         if (!repeated)
            catalogo += insertedMovie;
         else {
            std::cout << "This movie has already been inserted." << std::endl;
            break;
         }
      }
   }
   return catalogo;
}

const Catalogo &operator-=(Catalogo &catalogo, const Filme &chosenMovie) {
   uint8_t index = 0;
   for (auto indice: catalogo.movies) {
      if (indice == chosenMovie) {
         catalogo.movies.erase(catalogo.movies.begin() + index);
      }
      index++;
   }

   return catalogo;
}

std::ostream &operator<<(std::ostream &saida, const Catalogo &catalogo) {
   for (auto indice: catalogo.movies)
      saida << indice;
    
   return saida;
}

Catalogo::Catalogo() {
   std::string nomeArquivo = "data.txt";
   Filme filmeAuxiliar;
   std::string notaAuxiliar;
   std::vector <Filme> filmesAuxiliar;

   std::fstream myFile;
   myFile.open (nomeArquivo, std::fstream::in);

   if (!myFile.is_open()) {
      std::cout << "The chosen file does not exist." << std::endl;
      exit(ERROR_OPENING_FILE);
   }

   while (!myFile.eof()) {
      getline (myFile, filmeAuxiliar.movieName, ',');
      getline (myFile, filmeAuxiliar.filmProducer, ',');
      getline (myFile, notaAuxiliar);
      filmeAuxiliar.grade = std::stod(notaAuxiliar);

      if (!myFile.eof()) {
         filmesAuxiliar.push_back (filmeAuxiliar);
      }
   }
    
   myFile.close();
    
   movies = filmesAuxiliar;

}

std::vector<Filme> Catalogo::getTheBest() {
   std::vector<Filme> tempMovies;
   double tempGrade = 0;

   for (auto index: movies) {
      if (index > tempGrade) 
         tempGrade = index.grade;
   }   

   uint8_t index = 0;
   for (auto indice: movies) {
      if (indice.grade == tempGrade)
      {
         tempMovies.push_back(movies.at(index));
      }
      index++;
   }

   return tempMovies;
}

void Catalogo::update() {
   std::fstream myFile;
   std::string fileName = "data.txt";
   myFile.open(fileName, std::fstream::out);

   if (!myFile.is_open()) {
      std::cout << "The chosen file does not exist." << std::endl;
      exit(ERROR_OPENING_FILE);
   }
  
   for (auto index: movies) {
      myFile << index.movieName << ',';
      myFile << index.filmProducer << ',';
      myFile << index.grade << std::endl;
   }

   myFile.close();
}

Filme *Catalogo::operator()(std::string selectedMovieName) {
   if (movies.size() == 0) {
      std::cout << "Empty." << std::endl;
      return nullptr;
   }

   uint8_t index = 0;
   for (auto indice: movies) {
      if (indice.movieName == selectedMovieName) {
         return &movies.at(index);
      }
      index++;         
   }

   return nullptr;
}

Filme *Catalogo::operator()(std::string selectedMovieName, std::string selectedFilmProducer) {
   if (movies.size() == 0) {
      std::cout << "Empty." << std::endl;
      return nullptr;
   }

   uint8_t index = 0;
   for (auto indice: movies) {
      if (indice.movieName == selectedMovieName) {
         movies.at(index).filmProducer = selectedFilmProducer;
         return &movies.at(index);
      }
      index++;
   }

   return nullptr; 
}

Filme *Catalogo::operator()(std::string selectedMovieName, double selectedGrade) {
   if (movies.size() == 0) {
      std::cout << "Empty." << std::endl;
      return nullptr;
   }

   uint8_t index = 0;
   for (auto indice: movies) {
      if (indice.movieName == selectedMovieName) {
         movies.at(index).grade= selectedGrade;
         return &movies.at(index);
      }
      index++;
   }

   return nullptr;
}