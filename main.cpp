#include <iostream>
#include <string>
#include "hotel.h"

using namespace std;

int main() {

  Hotel hotel;

  int opcion = 0;
  int numero;
  int noches;
  double precio;
  double cargo;
  double servicio;
  double descuento;
  string tipo;
  char respuesta;

  do {
    cout << "\n===== SISTEMA DE HOTEL =====\n";
    cout << "1. Agregar habitacion individual\n";
    cout << "2. Agregar habitacion doble\n";
    cout << "3. Agregar suite\n";
    cout << "4. Mostrar todas las habitaciones\n";
    cout << "5. Mostrar habitaciones por tipo\n";
    cout << "6. Calcular ingreso total del hotel\n";
    cout << "7. Calcular ingreso por tipo de habitacion\n";
    cout << "8. Salir\n";
    cout << "Selecciona una opcion: ";
    cin >> opcion;

    if (opcion == 1) {

      cout << "\nNumero de habitacion: ";
      cin >> numero;

      cout << "Numero de noches: ";
      cin >> noches;

      cout << "Precio por noche: ";
      cin >> precio;

      cout << "Incluye desayuno? (s/n): ";
      cin >> respuesta;

      if (respuesta == 's' || respuesta == 'S') {
        hotel.agrega_individual(numero, noches, precio, true);
      }
      else {
        hotel.agrega_individual(numero, noches, precio);
      }

      cout << "Habitacion individual agregada.\n";
    }

    else if (opcion == 2) {

      cout << "\nNumero de habitacion: ";
      cin >> numero;

      cout << "Numero de noches: ";
      cin >> noches;

      cout << "Precio por noche: ";
      cin >> precio;

      cout << "Deseas agregar cargo extra? (s/n): ";
      cin >> respuesta;

      if (respuesta == 's' || respuesta == 'S') {
        cout << "Cargo extra: ";
        cin >> cargo;

        hotel.agrega_doble(numero, noches, precio, cargo);
      }
      else {
        hotel.agrega_doble(numero, noches, precio);
      }

      cout << "Habitacion doble agregada.\n";
    }

    else if (opcion == 3) {

      cout << "\nNumero de habitacion: ";
      cin >> numero;

      cout << "Numero de noches: ";
      cin >> noches;

      cout << "Precio por noche: ";
      cin >> precio;

      cout << "Servicio extra: ";
      cin >> servicio;

      cout << "Deseas agregar descuento? (s/n): ";
      cin >> respuesta;

      if (respuesta == 's' || respuesta == 'S') {
        cout << "Descuento: ";
        cin >> descuento;

        hotel.agrega_suite(numero, noches, precio, servicio, descuento);
      }
      else {
        hotel.agrega_suite(numero, noches, precio, servicio);
      }

      cout << "Suite agregada.\n";
    }

    else if (opcion == 4) {

      cout << "\nHabitaciones registradas:\n\n";
      hotel.muestra_habitaciones();
    }

    else if (opcion == 5) {

      cout << "\nEscribe el tipo de habitacion que quieres mostrar.\n";
      cout << "Opciones: individual, doble, suite\n";
      cout << "Tipo: ";
      cin >> tipo;

      cout << "\nHabitaciones tipo " << tipo << ":\n\n";
      hotel.muestra_habitaciones(tipo);
    }

    else if (opcion == 6) {

      cout << "\nIngreso total del hotel: ";
      cout << hotel.calc_ingreso_total() << endl;
    }

    else if (opcion == 7) {

      cout << "\nEscribe el tipo de habitacion para calcular ingreso.\n";
      cout << "Opciones: individual, doble, suite\n";
      cout << "Tipo: ";
      cin >> tipo;

      cout << "Ingreso total por habitaciones tipo " << tipo << ": ";
      cout << hotel.calc_ingreso_total(tipo) << endl;
    }

    else if (opcion == 8) {

      cout << "\nSaliendo del sistema...\n";
    }

    else {

      cout << "\nOpcion no valida. Intenta de nuevo.\n";
    }

  } while (opcion != 8);

  return 0;
}
