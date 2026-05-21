/*
 * Proyecto Hotel clase Hotel
 *
 * Esta clase administra las habitaciones del hotel.
 */

#ifndef HOTEL_H_
#define HOTEL_H_

#include <iostream>
#include <string>

#include "habitacion.h"

using namespace std;

const int MAX = 100;

class Hotel {

  private:
    Individual individuales[MAX];
    Doble dobles[MAX];
    Suite suites[MAX];

    int num_individuales;
    int num_dobles;
    int num_suites;

  public:
    Hotel(): num_individuales(0), num_dobles(0), num_suites(0) {};

    void crea_ejemplos();

    void muestra_habitaciones();
    void muestra_habitaciones(string tipo);

    double calc_ingreso_total();
    double calc_ingreso_total(string tipo);

    void agrega_individual(int numero, int noches, double precio);
    void agrega_individual(int numero, int noches, double precio, bool desayuno);

    void agrega_doble(int numero, int noches, double precio);
    void agrega_doble(int numero, int noches, double precio, double cargo);

    void agrega_suite(int numero, int noches, double precio, double servicio);
    void agrega_suite(int numero, int noches, double precio, double servicio, double descuento);
};

void Hotel::crea_ejemplos() {
  agrega_individual(101, 2, 850, true);
  agrega_individual(102, 1, 750);

  agrega_doble(201, 3, 1200, 300);
  agrega_doble(202, 2, 1100);

  agrega_suite(301, 2, 2500, 900, 300);
  agrega_suite(302, 1, 2800, 1000);
}

void Hotel::muestra_habitaciones() {

  for (int i = 0; i < num_individuales; i++) {
    cout << individuales[i].to_string();
  }

  for (int i = 0; i < num_dobles; i++) {
    cout << dobles[i].to_string();
  }

  for (int i = 0; i < num_suites; i++) {
    cout << suites[i].to_string();
  }
}

void Hotel::muestra_habitaciones(string tipo) {

  if (tipo == "individual") {
    for (int i = 0; i < num_individuales; i++) {
      cout << individuales[i].to_string();
    }
  }

  else if (tipo == "doble") {
    for (int i = 0; i < num_dobles; i++) {
      cout << dobles[i].to_string();
    }
  }

  else if (tipo == "suite") {
    for (int i = 0; i < num_suites; i++) {
      cout << suites[i].to_string();
    }
  }

  else {
    cout << "Tipo de habitacion no valido.\n";
  }
}

double Hotel::calc_ingreso_total() {

  double total = 0;

  for (int i = 0; i < num_individuales; i++) {
    total = total + individuales[i].costo_total();
  }

  for (int i = 0; i < num_dobles; i++) {
    total = total + dobles[i].costo_total();
  }

  for (int i = 0; i < num_suites; i++) {
    total = total + suites[i].costo_total();
  }

  return total;
}

double Hotel::calc_ingreso_total(string tipo) {

  double total = 0;

  if (tipo == "individual") {
    for (int i = 0; i < num_individuales; i++) {
      total = total + individuales[i].costo_total();
    }
  }

  else if (tipo == "doble") {
    for (int i = 0; i < num_dobles; i++) {
      total = total + dobles[i].costo_total();
    }
  }

  else if (tipo == "suite") {
    for (int i = 0; i < num_suites; i++) {
      total = total + suites[i].costo_total();
    }
  }

  return total;
}

void Hotel::agrega_individual(int numero, int noches, double precio) {

  if (num_individuales < MAX) {
    individuales[num_individuales] = Individual(numero, noches, precio);
    num_individuales++;
  }
}

void Hotel::agrega_individual(int numero, int noches, double precio, bool desayuno) {

  if (num_individuales < MAX) {
    individuales[num_individuales] = Individual(numero, noches, precio, desayuno);
    num_individuales++;
  }
}

void Hotel::agrega_doble(int numero, int noches, double precio) {

  if (num_dobles < MAX) {
    dobles[num_dobles] = Doble(numero, noches, precio);
    num_dobles++;
  }
}

void Hotel::agrega_doble(int numero, int noches, double precio, double cargo) {

  if (num_dobles < MAX) {
    dobles[num_dobles] = Doble(numero, noches, precio, cargo);
    num_dobles++;
  }
}

void Hotel::agrega_suite(int numero, int noches, double precio, double servicio) {

  if (num_suites < MAX) {
    suites[num_suites] = Suite(numero, noches, precio, servicio);
    num_suites++;
  }
}

void Hotel::agrega_suite(int numero, int noches, double precio, double servicio, double descuento) {

  if (num_suites < MAX) {
    suites[num_suites] = Suite(numero, noches, precio, servicio, descuento);
    num_suites++;
  }
}

#endif
