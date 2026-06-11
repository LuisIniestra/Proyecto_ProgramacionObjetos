/*
 *
 * Proyecto Hotel clase Individual
 *
 * Este archivo contiene la implementacion de los metodos de la clase Individual.
 */

#include "individual.h"
#include <sstream>

using namespace std;

/**
 * Constructor por default de Individual.
 *
 * Inicializa una habitacion individual con valores base.
 *
 * @param
 * @return
 */
Individual::Individual(): Habitacion(0, 0, 0, "individual") {
  desayuno_incluido = false;
}

/**
 * Constructor de Individual.
 *
 * Inicializa una habitacion individual sin desayuno incluido.
 *
 * @param int num numero de habitacion.
 * @param int noch numero de noches.
 * @param double precio precio por noche.
 * @return
 */
Individual::Individual(int num, int noch, double precio):
  Habitacion(num, noch, precio, "individual") {
  desayuno_incluido = false;
}

/**
 * Constructor de Individual.
 *
 * Inicializa una habitacion individual indicando si incluye desayuno.
 *
 * @param int num numero de habitacion.
 * @param int noch numero de noches.
 * @param double precio precio por noche.
 * @param bool desayuno indica si incluye desayuno.
 * @return
 */
Individual::Individual(int num, int noch, double precio, bool desayuno):
  Habitacion(num, noch, precio, "individual") {
  desayuno_incluido = desayuno;
}

/**
 * costo_total calcula el costo de una habitacion individual.
 *
 * Multiplica el precio por noche por el numero de noches.
 *
 * @param
 * @return double costo total de la habitacion individual.
 */
double Individual::costo_total() const {
  return precio_noche * noches;
}

/**
 * to_string convierte los atributos de Individual a string.
 *
 * concatena los valores de los atributos en un string para ser impreso.
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Individual::to_string() const {

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
