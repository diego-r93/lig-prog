#include "relogio.h"

Relogio::Relogio() {
   resetHora();
}

Relogio::Relogio(int horas, int minutos, int segundos) {
   resetHora(horas, minutos, segundos);
}

void Relogio::resetHora() {
   time(&hora);
   infoHora = localtime(&hora);

   setHoras(infoHora->tm_hour);
   setMinutos(infoHora->tm_min);
   setSegundos(infoHora->tm_sec);
}

void Relogio::resetHora(int horas, int minutos, int segundos) {
   setHoras(horas);
   setHoras(minutos);
   setHoras(segundos);
}

void Relogio::setSegundos(int segundos) {
   this->segundos = ((segundos < 0) || (segundos > 59)) ? 0 : segundos;
}

void Relogio::setMinutos(int minutos) {
   this->minutos = ((minutos < 0) || (minutos > 59)) ? 0 : minutos;
}

void Relogio::setHoras(int horas) {
   this->horas = ((horas < 0) || (horas > 59)) ? 0 : horas;
}

int Relogio::getSegundos() {
   return segundos;
}

int Relogio::getMinutos() {
   return minutos;
}

int Relogio::getHoras() {
   return horas;
}

void Relogio::mostreHorario() {
   cout << setfill('0') << setw(2) << getHoras()
        << ":" << setw(2) << getMinutos()
        << ":" << setw(2) << getSegundos() << endl;
}