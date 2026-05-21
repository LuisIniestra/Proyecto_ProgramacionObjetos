#include <iostream>

#include "habitacion.h"
#include "hotel.h"

using namespace std;

int main() {

  double total = 0;

  Hotel hotel;

  hotel.crea_ejemplos();

  cout << "Habitaciones registradas:\n\n";
  hotel.muestra_habitaciones();

  cout << "\nHabitaciones individuales:\n\n";
  hotel.muestra_habitaciones("individual");

  cout << "\nHabitaciones dobles:\n\n";
  hotel.muestra_habitaciones("doble");

  cout << "\nSuites:\n\n";
  hotel.muestra_habitaciones("suite");

  total = hotel.calc_ingreso_total();
  cout << "\nIngreso total del hotel: " << total << endl;

  total = hotel.calc_ingreso_total("individual");
  cout << "Ingreso total por habitaciones individuales: " << total << endl;

  total = hotel.calc_ingreso_total("doble");
  cout << "Ingreso total por habitaciones dobles: " << total << endl;

  total = hotel.calc_ingreso_total("suite");
  cout << "Ingreso total por suites: " << total << endl;

  cout << "\nAgregando nuevas habitaciones...\n\n";

  hotel.agrega_individual(103, 3, 800, true);
  hotel.agrega_doble(203, 2, 1300, 250);
  hotel.agrega_suite(303, 4, 3000, 1200, 500);

  cout << "Habitaciones actualizadas:\n\n";
  hotel.muestra_habitaciones();

  total = hotel.calc_ingreso_total();
  cout << "\nNuevo ingreso total del hotel: " << total << endl;

  return 0;
}
