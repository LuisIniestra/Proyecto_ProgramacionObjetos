#include "individual.h"
#include <sstream>

using namespace std;

Individual::Individual(): Habitacion(0, 0, 0, "individual") {
  // Constructor por default.
  // Llama al constructor de Habitacion con valores base.

  desayuno_incluido = false;
}

Individual::Individual(int num, int noch, double precio):
  Habitacion(num, noch, precio, "individual") {
  // Constructor con parámetros básicos.
  // Reutiliza el constructor de la clase padre.

  desayuno_incluido = false;
}

Individual::Individual(int num, int noch, double precio, bool desayuno):
  Habitacion(num, noch, precio, "individual") {
  // Constructor sobrecargado.
  // Recibe también si incluye desayuno.

  desayuno_incluido = desayuno;
}

double Individual::costo_total() const {
  // Cálculo propio de habitación individual.
  // Aquí se aplica overriding.

  return precio_noche * noches;
}

string Individual::to_string() const {
  // Convierte la información de Individual a texto.
  // También es overriding.

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
