/*
 *
 * Proyecto Hotel clase Individual
 *
 * Esta clase define el objeto Individual que hereda de Habitacion.
 * Representa una habitacion individual del hotel.
 */

#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

#include "habitacion.h"
#include <string>

using namespace std;

//Declaro objeto Individual que hereda de Habitacion
class Individual: public Habitacion {

  //Declaro variables de instancia privadas
  private:
    bool desayuno_incluido;

  //Declaro constructores y metodos publicos
  public:
    Individual();
    Individual(int num, int noch, double precio);
    Individual(int num, int noch, double precio, bool desayuno);

    double costo_total() const override;
    string to_string() const override;
};

#endif // INDIVIDUAL_H_
