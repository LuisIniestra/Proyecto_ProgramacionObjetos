#include <iostream>
#include <string>
#include "hotel.h"

using namespace std;

int main() {
  // Inicio del programa.

  Hotel hotel;
  // Crea el objeto principal del sistema.

  hotel.crea_habitaciones_hotel();
  // Crea las 88 habitaciones fijas del hotel.

  int opcion = 0;
  int noches = 0;
  int tipo_opcion = 0;
  string tipo;

  do {
    // Menú interactivo para el usuario.

    cout << "\n===== SISTEMA DE HOTEL =====\n";
    cout << "1. Mostrar habitaciones disponibles\n";
    cout << "2. Reservar habitacion individual\n";
    cout << "3. Reservar habitacion doble\n";
    cout << "4. Reservar suite\n";
    cout << "5. Mostrar habitaciones ocupadas\n";
    cout << "6. Calcular ingreso total del hotel\n";
    cout << "7. Calcular ingreso por tipo de habitacion\n";
    cout << "8. Mostrar todas las habitaciones\n";
    cout << "9. Salir\n";
    cout << "Selecciona una opcion: ";
    cin >> opcion;

    if (opcion == 1) {
      cout << "\nHabitaciones disponibles:\n\n";
      hotel.muestra_disponibles();
    }

    else if (opcion == 2) {
      cout << "\nNumero de noches: ";
      cin >> noches;

      hotel.reservar_habitacion("individual", noches);
      // Reserva automáticamente la primera individual disponible.
    }

    else if (opcion == 3) {
      cout << "\nNumero de noches: ";
      cin >> noches;

      hotel.reservar_habitacion("doble", noches);
      // Reserva automáticamente la primera doble disponible.
    }

    else if (opcion == 4) {
      cout << "\nNumero de noches: ";
      cin >> noches;

      hotel.reservar_habitacion("suite", noches);
      // Reserva automáticamente la primera suite disponible.
    }

    else if (opcion == 5) {
      cout << "\nHabitaciones ocupadas:\n\n";
      hotel.muestra_ocupadas();
    }

    else if (opcion == 6) {
      cout << "\nIngreso total del hotel: " << hotel.calc_ingreso_total() << endl;
    }

    else if (opcion == 7) {
      cout << "\nTipo de habitacion:\n";
      cout << "1. Individual\n";
      cout << "2. Doble\n";
      cout << "3. Suite\n";
      cout << "Selecciona una opcion: ";
      cin >> tipo_opcion;

      if (tipo_opcion == 1) {
        tipo = "individual";
      }
      else if (tipo_opcion == 2) {
        tipo = "doble";
      }
      else if (tipo_opcion == 3) {
        tipo = "suite";
      }
      else {
        tipo = "";
      }

      if (tipo != "") {
        cout << "Ingreso total por " << tipo << ": ";
        cout << hotel.calc_ingreso_total(tipo) << endl;
      }
      else {
        cout << "Tipo no valido.\n";
      }
    }

    else if (opcion == 8) {
      cout << "\nTodas las habitaciones del hotel:\n\n";
      hotel.muestra_habitaciones();
    }

    else if (opcion == 9) {
      cout << "\nSaliendo del sistema...\n";
    }

    else {
      cout << "\nOpcion no valida.\n";
    }

  } while (opcion != 9);

  return 0;
}
