/*
 *
 * Proyecto Hotel clase Hotel
 *
 * Este archivo contiene la implementacion de los metodos de la clase Hotel.
 */

#include "hotel.h"
#include <iostream>

using namespace std;

/**
 * Constructor por default de Hotel.
 *
 * inicializa el contador de habitaciones y limpia el arreglo de apuntadores.
 *
 * @param
 * @return
 */
Hotel::Hotel() {
  num_habitaciones = 0;

  for (int i = 0; i < MAX_HABITACIONES; i++) {
    habitaciones[i] = 0;
  }
}

/**
 * Destructor de Hotel.
 *
 * libera la memoria de las habitaciones creadas con new.
 *
 * @param
 * @return
 */
Hotel::~Hotel() {

  for (int i = 0; i < num_habitaciones; i++) {
    delete habitaciones[i];
  }
}

/**
 * datos_validos valida los datos basicos de una habitacion.
 *
 * revisa que el numero, las noches y el precio sean mayores a cero.
 *
 * @param int numero numero de habitacion.
 * @param int noches numero de noches.
 * @param double precio precio por noche.
 * @return bool con true si los datos son validos.
 */
bool Hotel::datos_validos(int numero, int noches, double precio) {
  return numero > 0 && noches > 0 && precio > 0;
}

/**
 * muestra_habitaciones imprime todas las habitaciones.
 *
 * utiliza el arreglo habitaciones[] y el numero de habitaciones, para recorrer
 * todo el arreglo imprimiendo cada uno de los objetos con su metodo to_string().
 *
 * @param
 * @return
 */
void Hotel::muestra_habitaciones() {

  if (num_habitaciones == 0) {
    cout << "No hay habitaciones registradas.\n";
    return;
  }

  //Ciclo que recorre el arreglo e imprime cada objeto.
  for (int i = 0; i < num_habitaciones; i++) {
    cout << habitaciones[i]->to_string();
  }
}

/**
 * muestra_habitaciones imprime habitaciones que coinciden con tipo.
 *
 * utiliza el arreglo habitaciones[] para imprimir los objetos cuyo get_tipo()
 * coincida con el tipo recibido como parametro.
 *
 * @param string tipo debe ser: 'individual', 'doble' o 'suite'.
 * @return
 */
void Hotel::muestra_habitaciones(string tipo) {

  bool encontrado = false;

  //Ciclo que recorre el arreglo e imprime cada objeto que coincide.
  for (int i = 0; i < num_habitaciones; i++) {
    if (habitaciones[i]->get_tipo() == tipo) {
      cout << habitaciones[i]->to_string();
      encontrado = true;
    }
  }

  if (!encontrado) {
    cout << "No hay habitaciones de tipo " << tipo << ".\n";
  }
}

/**
 * calc_ingreso_total suma el ingreso total de todas las habitaciones.
 *
 * utiliza el arreglo habitaciones[] para acumular el costo total de todas
 * las habitaciones registradas.
 *
 * @param
 * @return double con la suma de todos los costos.
 */
double Hotel::calc_ingreso_total() {

  double total = 0;

  for (int i = 0; i < num_habitaciones; i++) {
    total = total + habitaciones[i]->costo_total();
  }

  return total;
}

/**
 * calc_ingreso_total suma el ingreso total de un tipo de habitacion.
 *
 * utiliza el arreglo habitaciones[] para acumular el costo total de las
 * habitaciones cuyo tipo coincida con el tipo recibido como parametro.
 *
 * @param string tipo debe ser: 'individual', 'doble' o 'suite'.
 * @return double con la suma de costos de ese tipo.
 */
double Hotel::calc_ingreso_total(string tipo) {

  double total = 0;

  for (int i = 0; i < num_habitaciones; i++) {
    if (habitaciones[i]->get_tipo() == tipo) {
      total = total + habitaciones[i]->costo_total();
    }
  }

  return total;
}

/**
 * agrega_individual crea un objeto Individual y lo agrega al arreglo.
 *
 * crea un objeto Individual usando memoria dinamica y lo guarda en el arreglo
 * de habitaciones usando como indice el numero de habitaciones.
 *
 * @param int numero numero de habitacion.
 * @param int noches numero de noches.
 * @param double precio precio por noche.
 * @return
 */
void Hotel::agrega_individual(int numero, int noches, double precio) {

  if (num_habitaciones < MAX_HABITACIONES && datos_validos(numero, noches, precio)) {
    //new crea el objeto en tiempo de ejecucion para usar polimorfismo
    habitaciones[num_habitaciones] = new Individual(numero, noches, precio);
    num_habitaciones++;
  }
  else {
    cout << "No se pudo agregar la habitacion individual.\n";
  }
}

/**
 * agrega_individual crea un objeto Individual con desayuno.
 *
 * crea un objeto Individual con desayuno y lo agrega al arreglo de habitaciones.
 *
 * @param int numero numero de habitacion.
 * @param int noches numero de noches.
 * @param double precio precio por noche.
 * @param bool desayuno indica si incluye desayuno.
 * @return
 */
void Hotel::agrega_individual(int numero, int noches, double precio, bool desayuno) {

  if (num_habitaciones < MAX_HABITACIONES && datos_validos(numero, noches, precio)) {
    //new crea el objeto en tiempo de ejecucion para usar polimorfismo
    habitaciones[num_habitaciones] = new Individual(numero, noches, precio, desayuno);
    num_habitaciones++;
  }
  else {
    cout << "No se pudo agregar la habitacion individual.\n";
  }
}

/**
 * agrega_doble crea un objeto Doble y lo agrega al arreglo.
 *
 * crea un objeto Doble sin cargo extra y lo agrega al arreglo de habitaciones.
 *
 * @param int numero numero de habitacion.
 * @param int noches numero de noches.
 * @param double precio precio por noche.
 * @return
 */
void Hotel::agrega_doble(int numero, int noches, double precio) {

  if (num_habitaciones < MAX_HABITACIONES && datos_validos(numero, noches, precio)) {
    //new crea el objeto en tiempo de ejecucion para usar polimorfismo
    habitaciones[num_habitaciones] = new Doble(numero, noches, precio);
    num_habitaciones++;
  }
  else {
    cout << "No se pudo agregar la habitacion doble.\n";
  }
}

/**
 * agrega_doble crea un objeto Doble con cargo extra.
 *
 * crea un objeto Doble con cargo extra y lo agrega al arreglo de habitaciones.
 *
 * @param int numero numero de habitacion.
 * @param int noches numero de noches.
 * @param double precio precio por noche.
 * @param double cargo cargo extra de la habitacion.
 * @return
 */
void Hotel::agrega_doble(int numero, int noches, double precio, double cargo) {

  if (num_habitaciones < MAX_HABITACIONES &&
      datos_validos(numero, noches, precio) &&
      cargo >= 0) {

    //new crea el objeto en tiempo de ejecucion para usar polimorfismo
    habitaciones[num_habitaciones] = new Doble(numero, noches, precio, cargo);
    num_habitaciones++;
  }
  else {
    cout << "No se pudo agregar la habitacion doble.\n";
  }
}

/**
 * agrega_suite crea un objeto Suite y lo agrega al arreglo.
 *
 * crea un objeto Suite con servicio extra y lo agrega al arreglo de habitaciones.
 *
 * @param int numero numero de habitacion.
 * @param int noches numero de noches.
 * @param double precio precio por noche.
 * @param double servicio servicio extra de la suite.
 * @return
 */
void Hotel::agrega_suite(int numero, int noches, double precio, double servicio) {

  if (num_habitaciones < MAX_HABITACIONES &&
      datos_validos(numero, noches, precio) &&
      servicio >= 0) {

    //new crea el objeto en tiempo de ejecucion para usar polimorfismo
    habitaciones[num_habitaciones] = new Suite(numero, noches, precio, servicio);
    num_habitaciones++;
  }
  else {
    cout << "No se pudo agregar la suite.\n";
  }
}

/**
 * agrega_suite crea un objeto Suite con descuento.
 *
 * crea un objeto Suite con servicio extra y descuento, validando que el descuento
 * no sea mayor que el subtotal.
 *
 * @param int numero numero de habitacion.
 * @param int noches numero de noches.
 * @param double precio precio por noche.
 * @param double servicio servicio extra de la suite.
 * @param double descuento descuento aplicado.
 * @return
 */
void Hotel::agrega_suite(int numero, int noches, double precio, double servicio, double descuento) {

  double subtotal = (precio * noches) + servicio;

  if (num_habitaciones < MAX_HABITACIONES &&
      datos_validos(numero, noches, precio) &&
      servicio >= 0 &&
      descuento >= 0 &&
      descuento <= subtotal) {

    //new crea el objeto en tiempo de ejecucion para usar polimorfismo
    habitaciones[num_habitaciones] = new Suite(numero, noches, precio, servicio, descuento);
    num_habitaciones++;
  }
  else {
    cout << "No se pudo agregar la suite.\n";
  }
}
