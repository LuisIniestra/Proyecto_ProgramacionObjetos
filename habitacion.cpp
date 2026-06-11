#include "habitacion.h"

using namespace std;

Habitacion::Habitacion() {
  // Constructor por default de la clase Habitacion.
  // Aunque Habitacion es abstracta, este constructor puede ser usado
  // por las clases hijas si alguna lo necesita.

  numero = 0;
  // Inicializa el número de habitación con un valor base.

  noches = 0;
  // Inicializa la cantidad de noches con un valor base.

  precio_noche = 0;
  // Inicializa el precio por noche con un valor base.

  tipo = "habitacion";
  // Tipo general.
  // Realmente no se usará directamente porque Habitacion es abstracta.
}

Habitacion::Habitacion(int num, int noch, double precio, string tip) {
  // Constructor con parámetros.
  // Este constructor lo usan las clases hijas para inicializar
  // los atributos heredados desde Habitacion.

  numero = num;
  // Guarda el número de habitación recibido.

  noches = noch;
  // Guarda la cantidad de noches recibida.

  precio_noche = precio;
  // Guarda el precio por noche recibido.

  tipo = tip;
  // Guarda el tipo de habitación recibido.
  // Por ejemplo: "individual", "doble" o "suite".
}

Habitacion::~Habitacion() {
  // Destructor virtual de Habitacion.
  // Aunque está vacío, es importante porque Hotel maneja objetos
  // usando apuntadores de tipo Habitacion*.
  // Esto permite destruir correctamente objetos hijos como Individual,
  // Doble o Suite.
}

int Habitacion::get_numero() const {
  // Getter para consultar el número de habitación.

  return numero;
  // Regresa el número de la habitación.
}

int Habitacion::get_noches() const {
  // Getter para consultar la cantidad de noches.

  return noches;
  // Regresa las noches registradas.
}

double Habitacion::get_precio_noche() const {
  // Getter para consultar el precio por noche.

  return precio_noche;
  // Regresa el precio base por noche.
}

string Habitacion::get_tipo() const {
  // Getter para consultar el tipo de habitación.

  return tipo;
  // Regresa si es individual, doble o suite.
}
