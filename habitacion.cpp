#include "habitacion.h"

using namespace std;

Habitacion::Habitacion() {
  // Constructor por default de la clase Habitacion

  numero = 0;

  noches = 0;

  precio_noche = 0;
  // Inicializa las variables en cero

  tipo = "habitacion";
  // Inicializa el tipo en un valor generico
}

Habitacion::Habitacion(int num, int noch, double precio, string tip) {
  // Constructor con parámetros.
  
  numero = num;// Guarda el numero de habitacion recibido

  noches = noch; // Guarda la cantidad de noches recibida

  precio_noche = precio; // Guarda el precio por noche recibido

  tipo = tip; // Guarda el tipo de habitacion recibido

}

Habitacion::~Habitacion() {
  // Destructor virtual de Habitacion permite destruir correctamente objetos hijos como Individual,Doble o Suite.
}

int Habitacion::get_numero() const { // Getter para consultar el número de habitacion

  return numero; // Regresa el numero de la habitacion
}

int Habitacion::get_noches() const { // Getter para consultar la cantidad de noches

  return noches; // Regresa las noches registradas
}

double Habitacion::get_precio_noche() const {// Getter para consultar el precio por noche

  return precio_noche; // Regresa el precio base por noche
}

string Habitacion::get_tipo() const { // Getter para consultar el tipo de habitacion

  return tipo; // Regresa si es individual, doble o suite
}
