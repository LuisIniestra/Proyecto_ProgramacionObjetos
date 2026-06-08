#include "individual.h"
#include <sstream>

using namespace std;

Individual::Individual(): Habitacion(0, 0, 0, "individual") { // Llama al constructor de la clase padre Habitacion

  desayuno_incluido = false; // Por default la habitación individual no incluye desayuno
}

Individual::Individual(int num, int noch, double precio):
  Habitacion(num, noch, precio, "individual") {
  // Constructor con parametros básicos llama al constructor de Habitacion para inicializar los atributos heredados
  
  desayuno_incluido = false;
  // Como este constructor no recibe desayuno, se deja en false
}

Individual::Individual(int num, int noch, double precio, bool desayuno):
  Habitacion(num, noch, precio, "individual") {
  // Constructor sobrecargado. Aquí se aplica overloading porque existe otro constructor Individual con diferente cantidad de parametros
  
  desayuno_incluido = desayuno;
  // Guarda el valor recibido en el atributo propio de Individual
}

double Individual::costo_total() const {
  // Implementación del método costo_total() de la clase abstracta

  return precio_noche * noches;
  // Calcula el costo de una habitación individual
}

string Individual::to_string() const {
  // Implementación del método to_string() de la clase abstracta (overriding)

  stringstream aux;
  // stringstream permite construir un texto usando varios datos.

  aux << "Habitacion " << numero << " tipo " << tipo << " noches " << noches << " precio por noche " << precio_noche << " desayuno incluido " << (desayuno_incluido ? "si" : "no") << " costo total " << costo_total() << "\n";
  // Se usan atributos heredados de Habitacion y el atributo propio desayuno_incluido.

  return aux.str();
  // Convierte el stringstream en string y lo regresa.
}
