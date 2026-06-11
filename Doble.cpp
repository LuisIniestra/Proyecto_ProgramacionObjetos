#include "doble.h"
#include <sstream>

using namespace std;

Doble::Doble(): Habitacion(0, 0, 0, "doble") {
  // Constructor por default de Doble.
  // Llama al constructor de Habitacion con valores base.
  // Aquí se ve herencia porque Doble reutiliza la inicialización de la clase padre.

  cargo_extra = 0;
  // Inicializa el cargo extra en cero.
}

Doble::Doble(int num, int noch, double precio):
  Habitacion(num, noch, precio, "doble") {
  // Constructor con parámetros básicos.
  // Recibe número, noches y precio.
  // Llama al constructor de Habitacion para inicializar los atributos heredados.

  cargo_extra = 0;
  // Como este constructor no recibe cargo extra, lo deja en cero.
}

Doble::Doble(int num, int noch, double precio, double cargo):
  Habitacion(num, noch, precio, "doble") {
  // Constructor sobrecargado.
  // Recibe número, noches, precio y cargo extra.
  // Aquí se aplica sobrecarga porque existen varios constructores Doble con distintos parámetros.

  cargo_extra = cargo;
  // Guarda el cargo extra recibido.
}

double Doble::costo_total() const {
  // Implementación de costo_total().
  // Este método viene de Habitacion como método virtual puro.
  // Aquí se aplica overriding porque Doble le da su propia versión.

  return (precio_noche * noches) + cargo_extra;
  // Calcula el costo de la habitación doble.
  // Primero multiplica precio por noche y luego suma el cargo extra.
}

string Doble::to_string() const {
  // Implementación de to_string().
  // También sobreescribe el método virtual puro de Habitacion.

  stringstream aux;
  // Se usa para construir un texto con los datos de la habitación.

  aux << "Habitacion " << numero
      << " tipo " << tipo
      << " noches " << noches
      << " precio por noche " << precio_noche
      << " cargo extra " << cargo_extra
      << " costo total " << costo_total()
      << "\n";
  // Aquí se arma el texto que se va a imprimir.
  // Usa atributos heredados de Habitacion y el atributo propio cargo_extra.

  return aux.str();
  // Convierte el stringstream a string y lo regresa.
}
