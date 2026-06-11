/*
 *
 * Proyecto Hotel clase Suite
 *
 * Esta clase define el objeto Suite que hereda de Habitacion.
 * Representa una suite del hotel.
 */

#ifndef SUITE_H_
#define SUITE_H_

#include "habitacion.h"
#include <string>

using namespace std;

//Declaro objeto Suite que hereda de Habitacion
class Suite: public Habitacion {

  //Declaro variables de instancia privadas
  private:
    double servicio_extra;
    double descuento;

  //Declaro constructores y metodos publicos
  public:
    Suite();
    Suite(int num, int noch, double precio, double servicio);
    Suite(int num, int noch, double precio, double servicio, double desc);

    double costo_total() const override;
    string to_string() const override;
};

#endif // SUITE_H_
