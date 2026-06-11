#include "individual.h"
#include <sstream>

using namespace std;

Individual::Individual(): Habitacion(0, 0, "individual") {
  // Constructor por default.
  // Llama al constructor de Habitacion.

  desayuno_incluido = false;
}

Individual::Individual(int num, double precio):
  Habitacion(num, precio, "individual") {
  // Constructor con número y precio.
  // El tipo se define como individual.

  desayuno_incluido = false;
}

Individual::Individual(int num, double precio, bool desayuno):
  Habitacion(num, precio, "individual") {
  // Constructor sobrecargado.
  // Recibe si la habitación incluye desayuno.

  desayuno_incluido = desayuno;
}

double Individual::costo_total() const {
  // Cálculo propio de habitación individual.
  // Aquí se aplica overriding.

  if (disponible) {
    return 0;
    // Si no está reservada, no genera ingreso.
  }

  return precio_noche * noches;
}

string Individual::to_string() const {
  // Convierte los datos de la habitación individual a texto.
  // Aquí también se aplica overriding.

  stringstream aux;

  aux << "Habitacion " << numero
      << " tipo " << tipo
      << " estado " << (disponible ? "disponible" : "ocupada")
      << " precio por noche " << precio_noche
      << " desayuno incluido " << (desayuno_incluido ? "si" : "no");

  if (!disponible) {
    aux << " noches " << noches
        << " costo total " << costo_total();
    // Solo muestra noches y costo si la habitación está ocupada.
  }

  aux << "\n";

  return aux.str();
}
