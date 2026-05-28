#include "Hotel.h"
#include <iostream>

using namespace std;

Hotel::Hotel() {
  num_habitaciones = 0;

  for (int i = 0; i < MAX_HABITACIONES; i++) {
    habitaciones[i] = 0;
  }
}

Hotel::~Hotel() {
  for (int i = 0; i < num_habitaciones; i++) {
    delete habitaciones[i];
  }
}

void Hotel::crea_ejemplos() {
  agrega_individual(101, 2, 850, true);
  agrega_individual(102, 1, 750);

  agrega_doble(201, 3, 1200, 300);
  agrega_doble(202, 2, 1100);

  agrega_suite(301, 2, 2500, 900, 300);
  agrega_suite(302, 1, 2800, 1000);
}

void Hotel::muestra_habitaciones() {
  for (int i = 0; i < num_habitaciones; i++) {
    cout << habitaciones[i]->to_string();
  }
}

void Hotel::muestra_habitaciones(string tipo) {
  for (int i = 0; i < num_habitaciones; i++) {
    if (habitaciones[i]->get_tipo() == tipo) {
      cout << habitaciones[i]->to_string();
    }
  }
}

double Hotel::calc_ingreso_total() {
  double total = 0;

  for (int i = 0; i < num_habitaciones; i++) {
    total = total + habitaciones[i]->costo_total();
  }

  return total;
}

double Hotel::calc_ingreso_total(string tipo) {
  double total = 0;

  for (int i = 0; i < num_habitaciones; i++) {
    if (habitaciones[i]->get_tipo() == tipo) {
      total = total + habitaciones[i]->costo_total();
    }
  }

  return total;
}

void Hotel::agrega_individual(int numero, int noches, double precio) {
  if (num_habitaciones < MAX_HABITACIONES) {
    habitaciones[num_habitaciones] = new Individual(numero, noches, precio);
    num_habitaciones++;
  }
}

void Hotel::agrega_individual(int numero, int noches, double precio, bool desayuno) {
  if (num_habitaciones < MAX_HABITACIONES) {
    habitaciones[num_habitaciones] = new Individual(numero, noches, precio, desayuno);
    num_habitaciones++;
  }
}

void Hotel::agrega_doble(int numero, int noches, double precio) {
  if (num_habitaciones < MAX_HABITACIONES) {
    habitaciones[num_habitaciones] = new Doble(numero, noches, precio);
    num_habitaciones++;
  }
}

void Hotel::agrega_doble(int numero, int noches, double precio, double cargo) {
  if (num_habitaciones < MAX_HABITACIONES) {
    habitaciones[num_habitaciones] = new Doble(numero, noches, precio, cargo);
    num_habitaciones++;
  }
}

void Hotel::agrega_suite(int numero, int noches, double precio, double servicio) {
  if (num_habitaciones < MAX_HABITACIONES) {
    habitaciones[num_habitaciones] = new Suite(numero, noches, precio, servicio);
    num_habitaciones++;
  }
}

void Hotel::agrega_suite(int numero, int noches, double precio, double servicio, double descuento) {
  if (num_habitaciones < MAX_HABITACIONES) {
    habitaciones[num_habitaciones] = new Suite(numero, noches, precio, servicio, descuento);
    num_habitaciones++;
  }
}
