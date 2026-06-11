/*
 * Proyecto Hotel main
 *
 * Este es un proyecto para la clase TC1030 Programacion Orientada a Objetos.
 * Es un programa que captura diferentes tipos de habitaciones con sus costos
 * respectivos, y nos permite calcular ingresos para cada tipo de habitacion.
 */

#include <iostream>   //para imprimir.
#include <string>     //para usar strings.

#include "hotel.h"    //biblioteca con objetos de mi proyecto.

using namespace std;

int main() {

  int opcion = 0;
  int numero = 0;
  int noches = 0;
  double precio = 0;
  double cargo = 0;
  double servicio = 0;
  double descuento = 0;
  string tipo;
  char respuesta;

  Hotel hotel;

  do {

    cout << "\nSISTEMA DE HOTEL\n";
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

      if (respuesta == 's' || respuesta == 'S')
        hotel.agrega_individual(numero, noches, precio, true);
      else
        hotel.agrega_individual(numero, noches, precio);
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
    }

    else if (opcion == 4) {

      hotel.muestra_habitaciones();
    }

    else if (opcion == 5) {

      cout << "\nEscribe el tipo de habitacion: ";
      cin >> tipo;
      hotel.muestra_habitaciones(tipo);
    }

    else if (opcion == 6) {

      cout << "\nIngreso total del hotel: " << hotel.calc_ingreso_total() << endl;
    }

    else if (opcion == 7) {

      cout << "\nEscribe el tipo de habitacion: ";
      cin >> tipo;
      cout << "Ingreso total por " << tipo << ": " << hotel.calc_ingreso_total(tipo) << endl;
    }

    else if (opcion == 8) {

      cout << "\nSaliendo del sistema.\n";
    }

    else {

      cout << "\nOpcion no valida.\n";
    }

  } while (opcion != 8);

  return 0;
}
