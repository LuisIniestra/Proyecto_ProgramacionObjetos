/*
 *
 * Proyecto Hotel clase Suite
 *
 * Este archivo contiene la implementacion de los metodos de la clase Suite.
 */

#include "suite.h"
#include <sstream>

using namespace std;

/**
 * Constructor por default de Suite.
 *
 * Inicializa una suite con valores base.
 *
 * @param
 * @return
 */
Suite::Suite(): Habitacion(0, 0, 0, "suite") {
  servicio_extra = 0;
  descuento = 0;
}

/**
 * Constructor de Suite.
 *
 * Inicializa una suite con servicio extra y sin descuento.
 *
 * @param int num numero de habitacion.
 * @param int noch numero de noches.
 * @param double precio precio por noche.
 * @param double servicio servicio extra de la suite.
 * @return
 */
Suite::Suite(int num, int noch, double precio, double servicio):
  Habitacion(num, noch, precio, "suite") {
  servicio_extra = servicio;
  descuento = 0;
}

/**
 * Constructor de Suite.
 *
 * Inicializa una suite con servicio extra y descuento.
 *
 * @param int num numero de habitacion.
 * @param int noch numero de noches.
 * @param double precio precio por noche.
 * @param double servicio servicio extra de la suite.
 * @param double desc descuento aplicado a la suite.
 * @return
 */
Suite::Suite(int num, int noch, double precio, double servicio, double desc):
  Habitacion(num, noch, precio, "suite") {
  servicio_extra = servicio;
  descuento = desc;
}

/**
 * costo_total calcula el costo de una suite.
 *
 * Multiplica el precio por noche por las noches, suma el servicio extra
 * y resta el descuento.
 *
 * @param
 * @return double costo total de la suite.
 */
double Suite::costo_total() const {
  return (precio_noche * noches) + servicio_extra - descuento;
}

/**
 * to_string convierte los atributos de Suite a string.
 *
 * concatena los valores de los atributos en un string para ser impreso.
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Suite::to_string() const {

  stringstream aux;

  aux << "Habitacion " << numero
      << " tipo " << tipo
      << " noches " << noches
      << " precio por noche " << precio_noche
      << " servicio extra " << servicio_extra
      << " descuento " << descuento
      << " costo total " << costo_total()
      << "\n";

  return aux.str();
}
