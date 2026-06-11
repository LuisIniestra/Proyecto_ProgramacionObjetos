#include "individual.h"
#include <sstream>

using namespace std;

Individual::Individual(): Habitacion(0, 0, 0, "individual") {
  // Constructor por default de Individual.
  // Llama al constructor de la clase padre Habitacion.
  // Aquí se inicializan los datos heredados con valores base.

  desayuno_incluido = false;
  // Por default, la habitación individual no incluye desayuno.
}

Individual::Individual(int num, int noch, double precio):
  Habitacion(num, noch, precio, "individual") {
  // Constructor con parámetros básicos.
  // Recibe número, noches y precio.
  // También llama al constructor de Habitacion para inicializar los atributos heredados.
  // Aquí se aplica herencia, porque Individual reutiliza la estructura de Habitacion.

  desayuno_incluido = false;
  // Como este constructor no recibe desayuno, se deja en false.
}

Individual::Individual(int num, int noch, double precio, bool desayuno):
  Habitacion(num, noch, precio, "individual") {
  // Constructor sobrecargado.
  // Recibe número, noches, precio y si incluye desayuno.
  // Aquí se aplica overloading, porque existe otro constructor Individual con diferente cantidad de parámetros.

  desayuno_incluido = desayuno;
  // Guarda el valor recibido en el atributo propio de Individual.
}

double Individual::costo_total() const {
  // Implementación del método costo_total().
  // Este método estaba declarado como virtual puro en Habitacion.
  // Aquí se aplica overriding, porque Individual le da su propia versión.

  return precio_noche * noches;
  // Calcula el costo de una habitación individual.
  // Solo multiplica el precio por noche por la cantidad de noches.
}

string Individual::to_string() const {
  // Implementación del método to_string().
  // También viene de Habitacion como método virtual puro.
  // Aquí se aplica overriding.

  stringstream aux;
  // stringstream permite construir un texto usando varios datos.

  aux << "Habitacion " << numero
      << " tipo " << tipo
      << " noches " << noches
      << " precio por noche " << precio_noche
      << " desayuno incluido " << (desayuno_incluido ? "si" : "no")
      << " costo total " << costo_total()
      << "\n";
  // Aquí se arma el texto con la información de la habitación individual.
  // Se usan atributos heredados de Habitacion y el atributo propio desayuno_incluido.

  return aux.str();
  // Convierte el stringstream en string y lo regresa.
}
