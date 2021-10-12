// Trabalho 4 de Linguagens de Programação
// Autor: Diego Rodrigues da Silva
// Compilador Utilizado: g++ 9.3.0
// GNU Make 4.2.1
// Sistema Operacional: Ubuntu 20.04.1 LTS

#include <iostream>
#include <string>
#include <algorithm>

#include "paciente.h"
#include "cadastro.h"

using std::cout;
using std::cin;

void displayMenu();

int main() {
   string entry;
   int16_t option;

   string patientType, severity;
   string selectedPatient;
   Cadastro cadastro;
   Paciente *patient;   

   do { 
      displayMenu();
      cin >> entry;
      string input(entry);

      if (any_of(input.begin(), input.end(), [](char ch) { return !isdigit(ch); })) {         
         option = 5;      
      }
      else {
         option = stoi(entry);
      } 

      switch (option) {
         case 1:
            cout << "What is the patient type?" << endl;
            cout << ">>> ";
            cin.ignore();
            cin >> patientType;

            if (patientType == "scheduled") {
               patient = new Paciente;
               cout << "What is the patient name?" << endl;
               cout << ">>> ";
               cin >> *patient;
            }
            else if (patientType == "covid") {
               patient = new CovidPatient;
               cout << "What is the patient name?" << endl;
               cout << ">>> ";
               cin >> *patient;
               cout << "What is the severity? " << endl;
               getline(cin, severity);
               static_cast <CovidPatient *>(patient)->setSeverity(severity);    
            }
            else if (patientType == "emergency") {
               patient = new EmergencyPatient;
               cout << "What is the patient name?" << endl;
               cout << ">>> ";
               cin >> *patient;
               cout << "What is the severity? " << endl;
               getline(cin, severity);
               static_cast <EmergencyPatient *>(patient)->setSeverity(severity);    
            }
            else {
               cout << "[ERROR] Invalid patient type." << endl;
            }

            try{
            cadastro.setPatient(*patient);
            }
            catch(InsertPatientException & except){
               cout << except.what() << endl;
            }
            break;

         case 2:
            cout << "Which patient are you looking for?" << endl;
            cout << ">>> ";
            cin.ignore();
            getline(cin, selectedPatient);

            try {
               cout << cadastro.getPatient(selectedPatient) << endl;
            }
            catch(SearchPatientException &except) {
               cout << except.what() << endl;
            }
            break;

         case 3:
            cout << cadastro;
            break;
         case 4:
            break;

         default:
            cout << "Invalid option." << endl;
            cout << "Valid options: 1, 2, 3, 4" << endl;
            cout << "Read the file README to understand the menu." << endl;
            cin.ignore();         
      }
   } while (option != 4);   

   return 0;
}

void displayMenu() {
   cout << "\n\n------------------- MENU ------------------------" << endl;
   cout << "1 - Inserir paciente" << endl;
   cout << "2 - Buscar paciente" << endl;
   cout << "3 - Exibir pacientes cadastrados" << endl;      
   cout << "4 - Sair" << endl;
   cout << "-------------------------------------------------" << endl;
   cout << ">>> ";
}