// Trabalho 3 de Linguagens de Programação
// Autor: Diego Rodrigues da Silva
// Compilador Utilizado: g++ 9.3.0
// GNU Make 4.2.1
// Sistema Operacional: Ubuntu 20.04.1 LTS

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "consts.h"

#include "catalogo.h"

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
   else if (!checkOption(option)) {
      cout << "Invalid option." << endl;
      cout << "Valid options: 1, 2, 3, 4, 5, 6" << endl;
      cout << "Read the file README to understand the menu." << endl;
      exit(INVALID_OPTION);      
   } 

   Catalogo catalogo;
   vector <Filme> movies;

   Filme selectedMovie;
   Filme *movie;  

   string selectedMovieName;
   string selectedFilmProducer;
   double selectedGrade;   

   uint8_t moviesSize = 0;

   uint16_t choosingMovie = 0;
   uint16_t editing = 0;

   string entry;

   switch (option) {
         case 1:
            choosingMovie = 1;
            while (choosingMovie == 1) {
               cout << "Enter the movie data:" << endl;
               cout << "Movie Name: ";
               getline(cin, selectedMovie.movieName);
               cout << "Film Producer: ";
               getline(cin, selectedMovie.filmProducer);
               cout << "Movie Grade: ";
               getline(cin, entry);
               selectedMovie.grade = stod(entry);
               movies.push_back(selectedMovie);
               moviesSize++;

               cout << "\nDo you want to add more movies? Type 1." << endl;
               cout << "To finish type 0. " << endl;
               getline(cin, entry);
               choosingMovie = stoi(entry);   
            }
            
            if (moviesSize == 1) {
               catalogo += selectedMovie;
            }
            else {
               catalogo += movies;
            }            
            break;

         case 2:
            cout << "Which movie do you want to delete?" << endl;
            getline(cin, selectedMovieName);

            movie = catalogo(selectedMovieName);

            if (movie != nullptr) {
               catalogo -= *movie;
            }
            else {
               cout << "Movie not found." << endl;
            }
            break;

         case 3:
            cout << "Which movie are you looking for?" << endl;
            cout << ">>> ";
            getline(cin, selectedMovieName);

            movie = catalogo(selectedMovieName);

            if (movie != nullptr) 
               cout << *movie;
            else 
               cout << "Movie not found." << endl;
            break;

         case 4:
            cout << "Which movie are you looking for?" << endl;
            cout << ">>> ";
            getline(cin, selectedMovieName);

            movie = catalogo(selectedMovieName);

            if (movie != nullptr) {
               cout << *movie;

               while (editing != 3) {
                  cout << "Edit mode selected." << endl;
                  cout << "Type 1 to edit filmProducer." << endl;
                  cout << "Type 2 to edit grade." << endl;
                  cout << "Type 3 to exit." << endl;
                  cout << ">>>  ";
                  cin >> editing;
               
                  if (editing == 1) {
                     cout << "New filmProducer: ";
                     cin.ignore();
                     getline(cin, selectedFilmProducer);
                     catalogo(selectedMovieName, selectedFilmProducer);
                  }

                  if (editing == 2) {
                     cout << "New grade: ";
                     cin >> selectedGrade;
                     catalogo(selectedMovieName, selectedGrade);
                  }
               }
            } 
            else {
               cout << "Movie not found" << endl;
            }
            break;

         case 5:
            cout << catalogo;
            break;

         case 6:
            catalogo.getTheBest();
            std::cout << "The best grades:" << std::endl;
            for (auto index: catalogo.getTheBest()) {
               cout << index;
            }
            break;
   }

   catalogo.update();

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