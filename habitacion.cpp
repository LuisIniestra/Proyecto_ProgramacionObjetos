#include "habitacion.h"
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

ostream& operator<<(ostream& salida, const Habitacion& habitacion) {
  salida << habitacion.to_string();
  return salida;
}
