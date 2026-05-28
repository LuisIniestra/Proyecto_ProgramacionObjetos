#ifndef HOTEL_H_
#define HOTEL_H_

#include <string>
#include "Habitacion.h"
#include "Individual.h"
#include "Doble.h"
#include "Suite.h"

using namespace std;

const int MAX_HABITACIONES = 100;

class Hotel {

  private:
    Habitacion *habitaciones[MAX_HABITACIONES];
    int num_habitaciones;

  public:
    Hotel();
    ~Hotel();

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

#endif
