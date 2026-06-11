/*
 *
 * Proyecto Hotel clase Hotel
 *
 * Esta clase define el objeto Hotel que contiene las operaciones para
 * agregar habitaciones, mostrar habitaciones y calcular ingresos.
 */

#ifndef HOTEL_H_
#define HOTEL_H_

#include <string>
#include "habitacion.h"
#include "individual.h"
#include "doble.h"
#include "suite.h"

using namespace std;

const int MAX_HABITACIONES = 100; //constante de tamaño de arreglos

class Hotel {

  //Declaro las variables privadas de instancia
  private:
    Habitacion *habitaciones[MAX_HABITACIONES]; //se define como apuntador para usar polimorfismo
    int num_habitaciones;

    bool datos_validos(int numero, int noches, double precio);

  //Declaro constructor por default y metodos publicos
  public:
    Hotel();
    ~Hotel();

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

#endif // HOTEL_H_
