#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

#include "habitacion.h"
#include <string>

using namespace std;

class Individual: public Habitacion {

  private:
    bool desayuno_incluido;

  public:
    Individual();
    Individual(int num, double precio);
    Individual(int num, double precio, bool desayuno);

    double costo_total() const override;
    string to_string() const override;
};

#endif
