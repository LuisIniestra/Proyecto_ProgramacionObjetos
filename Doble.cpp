#include "doble.h"
#include <sstream>

using namespace std;

Doble::Doble(): Habitacion(0, 0, 0, "doble") {
  // Constructor por default de Doble
  
  cargo_extra = 0;
  // Inicializa el cargo extra en cero
}

Doble::Doble(int num, int noch, double precio):
  Habitacion(num, noch, precio, "doble") {
  // Constructor con parámetros básicos. Recibe número, noches y precio.

  cargo_extra = 0;

}

Doble::Doble(int num, int noch, double precio, double cargo):
  Habitacion(num, noch, precio, "doble") {
  // Constructor sobrecargado. Recibe número, noches, precio y cargo extra 

  cargo_extra = cargo; // Guarda el cargo extra recibido.
}

double Doble::costo_total() const {
  // Implementación de costo_total() de la clase abstracta

  return (precio_noche * noches) + cargo_extra;
  // Calcula el costo de la habitación doble.
}

string Doble::to_string() const {
  // Implementación de to_string() de la clase abstracta
  
  stringstream aux;
  // Se usa para construir un texto con los datos de la habitación.

  aux << "Habitacion " << numero << " tipo " << tipo << " noches " << noches << " precio por noche " << precio_noche << " cargo extra " << cargo_extra << " costo total " << costo_total() << "\n";
  // Usa atributos heredados de Habitacion y el atributo propio cargo_extra.

  return aux.str();
  // Convierte el stringstream a string y lo regresa.
}
