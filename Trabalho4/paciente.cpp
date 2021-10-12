#include <iostream>

#include "paciente.h"

using std::cin;
using std::cout;
using std::endl;

ostream &operator<<(ostream &output, Paciente &patient) {
   output << "Name: " << patient.getName() << endl;
   output << "Status: " << patient.patientStatus;
   output << endl;

   return output;
}

istream &operator>>(istream &input, Paciente &patient) {
   cin.ignore();
   getline(input, patient.patientName);

   return input;
}

Paciente::Paciente() {
   patientStatus = "No data";
}

Paciente::Paciente(string patientName) {
   this->patientName = patientName;
}

Paciente::Paciente(const Paciente &patient) {
   this->patientName = patient.patientName;
   this->patientStatus = patient.patientStatus;
}

string &Paciente::getName() {
   return patientName;
}

bool Paciente::operator>(const Paciente &paciente) {
   return this->patientName > paciente.patientName;
}

bool Paciente::operator<(const Paciente &paciente) {
   return this->patientName < paciente.patientName;
}

bool Paciente::operator==(const Paciente &paciente) {
   return this->patientName == paciente.patientName;
}

CovidPatient::CovidPatient() {
   patientStatus = "Severity = " + severity;
}

EmergencyPatient::EmergencyPatient() {
   patientStatus = "Severity = " + severity;
}

void CovidPatient::setSeverity(string severity) {
   this->severity = severity;
   patientStatus = "Severity = " + this->severity;
}

void EmergencyPatient::setSeverity(string severity) {
   this->severity = severity;
   patientStatus = "Severity = " + this->severity;
}