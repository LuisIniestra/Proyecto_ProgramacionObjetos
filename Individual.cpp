#include "Individual.h"
#include <sstream>

using namespace std;

Individual::Individual(): Habitacion() {
  tipo = "individual";
  desayuno_incluido = false;
}

Individual::Individual(int num, int noch, double precio):
  Habitacion(num, noch, precio, "individual") {
  desayuno_incluido = false;
}

Individual::Individual(int num, int noch, double precio, bool desayuno):
  Habitacion(num, noch, precio, "individual") {
  desayuno_incluido = desayuno;
}

double Individual::costo_total() {
  return precio_noche * noches;
}

string Individual::to_string() {
  stringstream aux;

  aux << "Habitacion " << numero
      << " tipo " << tipo
      << " noches " << noches
      << " precio por noche " << precio_noche
      << " desayuno incluido " << (desayuno_incluido ? "si" : "no")
      << " costo total " << costo_total()
      << "\n";

  return aux.str();
}
