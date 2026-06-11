#include "suite.h"
#include <sstream>

using namespace std;

Suite::Suite(): Habitacion(0, 0, 0, "suite") {
  // Constructor por default.

  servicio_extra = 0;
  descuento = 0;
}

Suite::Suite(int num, int noch, double precio, double servicio):
  Habitacion(num, noch, precio, "suite") {
  // Constructor con servicio extra.

  servicio_extra = servicio;
  descuento = 0;
}

Suite::Suite(int num, int noch, double precio, double servicio, double desc):
  Habitacion(num, noch, precio, "suite") {
  // Constructor sobrecargado.
  // Recibe servicio extra y descuento.

  servicio_extra = servicio;
  descuento = desc;
}

double Suite::costo_total() const {
  // Cálculo propio de suite.
  // Aquí se aplica overriding.

  return (precio_noche * noches) + servicio_extra - descuento;
}

string Suite::to_string() const {
  // Convierte los datos de Suite a texto.

  stringstream aux;

  aux << "Habitacion " << numero
      << " tipo " << tipo
      << " noches " << noches
      << " precio por noche " << precio_noche
      << " servicio extra " << servicio_extra
      << " descuento " << descuento
      << " costo total " << costo_total()
      << "\n";

  return aux.str();
}
