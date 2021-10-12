#ifndef CADASTRO_H
#define CADASTRO_H

#include <iostream>
#include <string>
#include <stdexcept>

#include "paciente.h"
#include "arvore.h"

using std::exception;
using std::ostream;
using std::string;

class Cadastro {
   friend ostream &operator<<(ostream &, Cadastro &);

   public:
      void setPatient(Paciente);
      Paciente &getPatient(string);

   private:
      Arvore <Paciente> Patients;
};

class InsertPatientException : public exception {
	public:
		virtual const char * what() const throw(); 
};

class SearchPatientException : public exception {
	public:
		virtual const char * what() const throw(); 
};

#endif