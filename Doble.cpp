#include "doble.h"
#include <sstream>

using namespace std;

Doble::Doble(): Habitacion(0, 0, 0, "doble") {
  // Constructor por default.

  cargo_extra = 0;
}

Doble::Doble(int num, int noch, double precio):
  Habitacion(num, noch, precio, "doble") {
  // Constructor con datos básicos.

  cargo_extra = 0;
}

Doble::Doble(int num, int noch, double precio, double cargo):
  Habitacion(num, noch, precio, "doble") {
  // Constructor sobrecargado.
  // Recibe cargo extra.

  cargo_extra = cargo;
}

double Doble::costo_total() const {
  // Cálculo propio de habitación doble.
  // Aquí se aplica overriding.

  return (precio_noche * noches) + cargo_extra;
}

string Doble::to_string() const {
  // Convierte los datos de Doble a texto.

  stringstream aux;

  aux << "Habitacion " << numero
      << " tipo " << tipo
      << " noches " << noches
      << " precio por noche " << precio_noche
      << " cargo extra " << cargo_extra
      << " costo total " << costo_total()
      << "\n";

  return aux.str();
}
