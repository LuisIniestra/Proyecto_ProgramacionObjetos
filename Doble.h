#ifndef DOBLE_H_
#define DOBLE_H_

#include "Habitacion.h"
#include <string>

using namespace std;

class Doble: public Habitacion {

  private:
    double cargo_extra;

  public:
    Doble();
    Doble(int num, int noch, double precio);
    Doble(int num, int noch, double precio, double cargo);

    double costo_total();
    string to_string();

};

#endif
