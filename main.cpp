#include <iostream>
#include <string>
#include "hotel.h"

using namespace std;

int main() {
  // Inicio del programa.

  Hotel hotel;
  // Crea el objeto principal del sistema.

  int opcion = 0;
  int numero = 0;
  int noches = 0;
  double precio = 0;
  double cargo = 0;
  double servicio = 0;
  double descuento = 0;
  string tipo;
  char respuesta;

  do {
    // Menú interactivo para que el usuario use el sistema.

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
      // Agregar habitación individual.

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
    }

    else if (opcion == 2) {
      // Agregar habitación doble.

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
    }

    else if (opcion == 3) {
      // Agregar suite.

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
    }

    else if (opcion == 4) {
      // Mostrar todas las habitaciones.

      cout << "\nHabitaciones registradas:\n\n";
      hotel.muestra_habitaciones();
    }

    else if (opcion == 5) {
      // Mostrar habitaciones filtradas por tipo.

      cout << "\nEscribe el tipo de habitacion.\n";
      cout << "Opciones: individual, doble, suite\n";
      cout << "Tipo: ";
      cin >> tipo;

      cout << "\nHabitaciones tipo " << tipo << ":\n\n";
      hotel.muestra_habitaciones(tipo);
    }

    else if (opcion == 6) {
      // Calcular ingreso total.

      cout << "\nIngreso total del hotel: ";
      cout << hotel.calc_ingreso_total() << endl;
    }

    else if (opcion == 7) {
      // Calcular ingreso por tipo.

      cout << "\nEscribe el tipo de habitacion.\n";
      cout << "Opciones: individual, doble, suite\n";
      cout << "Tipo: ";
      cin >> tipo;

      cout << "Ingreso total por " << tipo << ": ";
      cout << hotel.calc_ingreso_total(tipo) << endl;
    }

    else if (opcion == 8) {
      // Salir del sistema.

      cout << "\nSaliendo del sistema...\n";
    }

    else {
      // Validación de opción incorrecta.

      cout << "\nOpcion no valida.\n";
    }

  } while (opcion != 8);

  return 0;
}
