#include "Suite.h"
#include <sstream>

using namespace std;

Suite::Suite(): Habitacion() {
  tipo = "suite";
  servicio_extra = 0;
  descuento = 0;
}

Suite::Suite(int num, int noch, double precio, double servicio):
  Habitacion(num, noch, precio, "suite") {
  servicio_extra = servicio;
  descuento = 0;
}

Suite::Suite(int num, int noch, double precio, double servicio, double desc):
  Habitacion(num, noch, precio, "suite") {
  servicio_extra = servicio;
  descuento = desc;
}

double Suite::costo_total() {
  return (precio_noche * noches) + servicio_extra - descuento;
}

string Suite::to_string() {
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
