#include "individual.h"
#include <sstream>

using namespace std;

Individual::Individual(): Habitacion(0, 0, "individual") {
  desayuno_incluido = false;
}

Individual::Individual(int num, double precio):
  Habitacion(num, precio, "individual") {
  desayuno_incluido = false;
}

Individual::Individual(int num, double precio, bool desayuno):
  Habitacion(num, precio, "individual") {
  desayuno_incluido = desayuno;
}

double Individual::costo_total() const {
  if (disponible) {
    return 0;
  }

  return precio_noche * noches;
}

string Individual::to_string() const {
  stringstream aux;

  aux << "Habitacion " << numero
      << " tipo " << tipo
      << " estado " << (disponible ? "disponible" : "ocupada")
      << " precio por noche " << precio_noche
      << " desayuno incluido " << (desayuno_incluido ? "si" : "no");

  if (!disponible) {
    aux << " noches " << noches
        << " costo total " << costo_total();
  }

  aux << "\n";

  return aux.str();
}
