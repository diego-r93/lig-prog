#include <exception>

#include "cadastro.h"

const char *SearchPatientException::what() const throw() {
   return "[ERROR] Patient not found";
}

const char *InsertPatientException::what() const throw() {
   return "[ERROR] Patient already inserted";
}

ostream &operator<<(ostream &output, Cadastro &cadastro) {
   output << cadastro.Patients;

   return output;
}

void Cadastro::setPatient(Paciente patient) {

   if ((Patients += patient) == NULL)
      throw InsertPatientException();
}

Paciente &Cadastro::getPatient(string patientName) {
   Paciente *paciente_arvore = Patients(patientName);

   if (paciente_arvore == NULL)
      throw SearchPatientException();

   return *paciente_arvore;
}