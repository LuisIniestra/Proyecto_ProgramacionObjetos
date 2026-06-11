/*
 *
 * Proyecto Hotel clase Doble
 *
 * Esta clase define el objeto Doble que hereda de Habitacion.
 * Representa una habitacion doble del hotel.
 */

#ifndef DOBLE_H_
#define DOBLE_H_

#include "habitacion.h"
#include <string>

using namespace std;

//Declaro objeto Doble que hereda de Habitacion
class Doble: public Habitacion {

  //Declaro variables de instancia privadas
  private:
    double cargo_extra;

  //Declaro constructores y metodos publicos
  public:
    Doble();
    Doble(int num, int noch, double precio);
    Doble(int num, int noch, double precio, double cargo);

    double costo_total() const override;
    string to_string() const override;
};

#endif // DOBLE_H_
