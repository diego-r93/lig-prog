#include "ponto.h"

Ponto::Ponto(double x, double y, double z) {
   coordenadaX = x;
   coordenadaY = y;
   coordenadaZ = z;
}

void Ponto::setCoordenadaX(double x) {
   coordenadaX = x;
}

void Ponto::setCoordenadaY(double y) {
   coordenadaY = y;
}

void Ponto::setCoordenadaZ(double z) {
   coordenadaZ = z;
}

double Ponto::getCoordenadaX() {
   return coordenadaX;
}

double Ponto::getCoordenadaY() {
   return coordenadaY;
}

double Ponto::getCoordenadaZ() {
   return coordenadaZ;
}