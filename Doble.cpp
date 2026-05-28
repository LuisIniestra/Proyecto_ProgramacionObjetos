#include "Doble.h"
#include <sstream>

using namespace std;

Doble::Doble(): Habitacion() {
  tipo = "doble";
  cargo_extra = 0;
}

Doble::Doble(int num, int noch, double precio):
  Habitacion(num, noch, precio, "doble") {
  cargo_extra = 0;
}

Doble::Doble(int num, int noch, double precio, double cargo):
  Habitacion(num, noch, precio, "doble") {
  cargo_extra = cargo;
}

double Doble::costo_total() {
  return (precio_noche * noches) + cargo_extra;
}

string Doble::to_string() {
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
