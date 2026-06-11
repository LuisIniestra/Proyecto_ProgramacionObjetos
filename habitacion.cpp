#include "habitacion.h"

using namespace std;

Habitacion::Habitacion() {
  // Constructor por default con valores base.

  numero = 0;
  noches = 0;
  precio_noche = 0;
  tipo = "habitacion";
}

Habitacion::Habitacion(int num, int noch, double precio, string tip) {
  // Constructor con parámetros.
  // Lo usan las clases hijas para inicializar atributos heredados.

  numero = num;
  noches = noch;
  precio_noche = precio;
  tipo = tip;
}

Habitacion::~Habitacion() {
  // Destructor virtual.
  // Está vacío porque Habitacion no crea memoria dinámica directamente.
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
