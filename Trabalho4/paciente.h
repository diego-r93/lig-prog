#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>

using std::ostream;
using std::istream;
using std::string;

class Paciente {

   friend ostream &operator<<(ostream &, Paciente &);
   friend istream &operator>>(istream &, Paciente &);

   public:
      Paciente();
      Paciente(string);
      Paciente(const Paciente &);
      
      string patientStatus;

      virtual string &getName();

      bool operator>(const Paciente &);
      bool operator<(const Paciente &); 
      bool operator==(const Paciente &);      
    
   private:
      string patientName;
};

// Polymorphism

class CovidPatient: public Paciente {
   public:
      CovidPatient();
      void setSeverity(string);

   private:
      string severity = "serious";      
};

class EmergencyPatient: public Paciente {
   public:
      EmergencyPatient();
      void setSeverity(string);

   private:
      string severity = "not-serius";
};

#endif