#include "habitacion.h"

using namespace std;

Habitacion::Habitacion() {
  // Constructor por default con valores base.

  numero = 0;
  noches = 0;
  precio_noche = 0;
  tipo = "habitacion";
  disponible = true;
}

Habitacion::Habitacion(int num, double precio, string tip) {
  // Constructor que inicializa una habitación con datos reales.

  numero = num;
  noches = 0;
  // Empieza en 0 porque la habitación todavía no está reservada.

  precio_noche = precio;
  tipo = tip;
  disponible = true;
  // Toda habitación nueva comienza disponible.
}

Habitacion::~Habitacion() {
  // Destructor virtual.
  // Está vacío porque no hay memoria dinámica dentro de Habitacion,
  // pero es necesario para borrar correctamente objetos hijos.
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
  // Reserva la habitación.

  noches = noch;
  // Guarda cuántas noches se reservó.

  disponible = false;
  // Cambia el estado a ocupada.
}

void Habitacion::liberar() {
  // Libera la habitación.

  noches = 0;
  // Borra las noches de la reserva anterior.

  disponible = true;
  // Cambia el estado a disponible.
}
