#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

#include "Habitacion.h"
#include <string>

using namespace std;

class Individual: public Habitacion {

  private:
    bool desayuno_incluido;

  public:
    Individual();
    Individual(int num, int noch, double precio);
    Individual(int num, int noch, double precio, bool desayuno);

    double costo_total();
    string to_string();

};

#endif
