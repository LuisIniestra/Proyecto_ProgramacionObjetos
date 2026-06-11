/*
 *
 * Proyecto Hotel clase Habitacion
 *
 * Este archivo contiene la implementacion de los constructores y metodos
 * generales de la clase Habitacion.
 */

#include "habitacion.h"

using namespace std;

/**
 * Constructor por default de Habitacion.
 *
 * Inicializa una habitacion con valores base.
 *
 * @param
 * @return
 */
Habitacion::Habitacion() {
  numero = 0;
  noches = 0;
  precio_noche = 0;
  tipo = "habitacion";
}

/**
 * Constructor con parametros de Habitacion.
 *
 * Inicializa una habitacion con numero, noches, precio por noche y tipo.
 * Este constructor es usado por las clases hijas.
 *
 * @param int num numero de habitacion.
 * @param int noch numero de noches.
 * @param double precio precio por noche.
 * @param string tip tipo de habitacion.
 * @return
 */
Habitacion::Habitacion(int num, int noch, double precio, string tip) {
  numero = num;
  noches = noch;
  precio_noche = precio;
  tipo = tip;
}

/**
 * Destructor virtual de Habitacion.
 *
 * Permite eliminar correctamente objetos hijos usando apuntadores de tipo
 * Habitacion.
 *
 * @param
 * @return
 */
Habitacion::~Habitacion() {
}

/**
 * get_numero regresa el numero de habitacion.
 *
 * @param
 * @return int numero de habitacion.
 */
int Habitacion::get_numero() const {
  return numero;
}

/**
 * get_noches regresa la cantidad de noches.
 *
 * @param
 * @return int numero de noches.
 */
int Habitacion::get_noches() const {
  return noches;
}

/**
 * get_precio_noche regresa el precio por noche.
 *
 * @param
 * @return double precio por noche.
 */
double Habitacion::get_precio_noche() const {
  return precio_noche;
}

/**
 * get_tipo regresa el tipo de habitacion.
 *
 * @param
 * @return string tipo de habitacion.
 */
string Habitacion::get_tipo() const {
  return tipo;
}
