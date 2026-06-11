#ifndef HOTEL_H_
#define HOTEL_H_

#include <string>
#include "habitacion.h"
#include "individual.h"
#include "doble.h"
#include "suite.h"

using namespace std;

const int MAX_HABITACIONES = 100;
// Capacidad máxima de habitaciones que puede registrar el sistema.

class Hotel {
  // Clase administradora del proyecto.

  private:
    Habitacion *habitaciones[MAX_HABITACIONES];
    // Arreglo de apuntadores a Habitacion.
    // Aquí se aplica polimorfismo porque puede guardar Individual, Doble o Suite.

    int num_habitaciones;
    // Contador de habitaciones registradas.

    bool datos_validos(int numero, int noches, double precio);
    // Valida datos básicos antes de agregar una habitación.

  public:
    Hotel();
    // Constructor de Hotel.

    ~Hotel();
    // Destructor.
    // Borra las habitaciones creadas con new.

    void muestra_habitaciones();
    // Muestra todas las habitaciones.

    void muestra_habitaciones(string tipo);
    // Muestra habitaciones por tipo.
    // Sobrecarga de método.

    double calc_ingreso_total();
    // Calcula el ingreso total de todas las habitaciones.

    double calc_ingreso_total(string tipo);
    // Calcula ingreso por tipo.
    // Sobrecarga de método.

    void agrega_individual(int numero, int noches, double precio);
    // Agrega habitación individual sin desayuno.

    void agrega_individual(int numero, int noches, double precio, bool desayuno);
    // Agrega habitación individual con desayuno.
    // Sobrecarga.

    void agrega_doble(int numero, int noches, double precio);
    // Agrega habitación doble sin cargo extra.

    void agrega_doble(int numero, int noches, double precio, double cargo);
    // Agrega habitación doble con cargo extra.
    // Sobrecarga.

    void agrega_suite(int numero, int noches, double precio, double servicio);
    // Agrega suite con servicio extra.

    void agrega_suite(int numero, int noches, double precio, double servicio, double descuento);
    // Agrega suite con servicio extra y descuento.
    // Sobrecarga.
};

#endif
