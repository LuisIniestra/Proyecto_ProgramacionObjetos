#include "habitacion.h"

using namespace std;

Habitacion::Habitacion() {
  numero = 0;
  noches = 0;
  precio_noche = 0;
  tipo = "habitacion";
  disponible = true;
}

Habitacion::Habitacion(int num, double precio, string tip) {
  numero = num;
  noches = 0;
  precio_noche = precio;
  tipo = tip;
  disponible = true;
}

Habitacion::~Habitacion() {
}

int Habitacion::get_numero() const {
  return numero;
}

int Habitacion::get_noches() const {
  return noches;
}

double Habitacion::get_precio_noche() const {
  return precio_noche;
}

string Habitacion::get_tipo() const {
  return tipo;
}

bool Habitacion::get_disponible() const {
  return disponible;
}

void Habitacion::reservar(int noch) {
  noches = noch;
  disponible = false;
}

void Habitacion::liberar() {
  noches = 0;
  disponible = true;
}
