#include "Habitacion.h"
#include <sstream>

using namespace std;

Habitacion::Habitacion() {
  numero = 0;
  noches = 0;
  precio_noche = 0;
  tipo = "habitacion";
}

Habitacion::Habitacion(int num, int noch, double precio, string tip) {
  numero = num;
  noches = noch;
  precio_noche = precio;
  tipo = tip;
}

int Habitacion::get_numero() {
  return numero;
}

int Habitacion::get_noches() {
  return noches;
}

double Habitacion::get_precio_noche() {
  return precio_noche;
}

string Habitacion::get_tipo() {
  return tipo;
}

double Habitacion::costo_total() {
  return precio_noche * noches;
}

string Habitacion::to_string() {
  stringstream aux;

  aux << "Habitacion " << numero
      << " tipo " << tipo
      << " noches " << noches
      << " precio por noche " << precio_noche
      << " costo total " << costo_total()
      << "\n";

  return aux.str();
}
