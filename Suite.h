#ifndef SUITE_H_
#define SUITE_H_

#include "Habitacion.h"
#include <string>

using namespace std;

class Suite: public Habitacion {

  private:
    double servicio_extra;
    double descuento;

  public:
    Suite();
    Suite(int num, int noch, double precio, double servicio);
    Suite(int num, int noch, double precio, double servicio, double desc);

    double costo_total();
    string to_string();

};

#endif
