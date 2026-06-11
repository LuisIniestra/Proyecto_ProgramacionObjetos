/*
 *
 * Proyecto Hotel clase Doble
 *
 * Este archivo contiene la implementacion de los metodos de la clase Doble.
 */

#include "doble.h"
#include <sstream>

using namespace std;

/**
 * Constructor por default de Doble.
 *
 * Inicializa una habitacion doble con valores base.
 *
 * @param
 * @return
 */
Doble::Doble(): Habitacion(0, 0, 0, "doble") {
  cargo_extra = 0;
}

/**
 * Constructor de Doble.
 *
 * Inicializa una habitacion doble sin cargo extra.
 *
 * @param int num numero de habitacion.
 * @param int noch numero de noches.
 * @param double precio precio por noche.
 * @return
 */
Doble::Doble(int num, int noch, double precio):
  Habitacion(num, noch, precio, "doble") {
  cargo_extra = 0;
}

/**
 * Constructor de Doble.
 *
 * Inicializa una habitacion doble con cargo extra.
 *
 * @param int num numero de habitacion.
 * @param int noch numero de noches.
 * @param double precio precio por noche.
 * @param double cargo cargo extra de la habitacion.
 * @return
 */
Doble::Doble(int num, int noch, double precio, double cargo):
  Habitacion(num, noch, precio, "doble") {
  cargo_extra = cargo;
}

/**
 * costo_total calcula el costo de una habitacion doble.
 *
 * Multiplica el precio por noche por las noches y suma el cargo extra.
 *
 * @param
 * @return double costo total de la habitacion doble.
 */
double Doble::costo_total() const {
  return (precio_noche * noches) + cargo_extra;
}

/**
 * to_string convierte los atributos de Doble a string.
 *
 * concatena los valores de los atributos en un string para ser impreso.
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Doble::to_string() const {

  stringstream aux;

  aux << "Habitacion " << numero
      << " tipo " << tipo
      << " noches " << noches
      << " precio por noche " << precio_noche
      << " cargo extra " << cargo_extra
      << " costo total " << costo_total()
      << "\n";

  return aux.str();
}
