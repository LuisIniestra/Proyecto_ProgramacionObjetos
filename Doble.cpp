#include "doble.h"
#include <sstream>

using namespace std;

Doble::Doble(): Habitacion(0, 0, "doble") {
  // Constructor por default.

  cargo_extra = 0;
}

Doble::Doble(int num, double precio):
  Habitacion(num, precio, "doble") {
  // Constructor con número y precio.

  cargo_extra = 0;
}

Doble::Doble(int num, double precio, double cargo):
  Habitacion(num, precio, "doble") {
  // Constructor sobrecargado.
  // Recibe un cargo extra.

  cargo_extra = cargo;
}

double Doble::costo_total() const {
  // Cálculo propio de habitación doble.
  // Aquí se aplica overriding.

  if (disponible) {
    return 0;
  }

  return (precio_noche * noches) + cargo_extra;
}

string Doble::to_string() const {
  // Convierte los datos de la habitación doble a texto.

  stringstream aux;

  aux << "Habitacion " << numero
      << " tipo " << tipo
      << " estado " << (disponible ? "disponible" : "ocupada")
      << " precio por noche " << precio_noche
      << " cargo extra " << cargo_extra;

  if (!disponible) {
    aux << " noches " << noches
        << " costo total " << costo_total();
  }

  aux << "\n";

  return aux.str();
}
