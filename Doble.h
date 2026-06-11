#ifndef DOBLE_H_
#define DOBLE_H_

#include "habitacion.h"
#include <string>

using namespace std;

class Doble: public Habitacion {
  // Doble hereda de Habitacion.

  private:
    double cargo_extra;
    // Atributo propio de la habitación doble.

  public:
    Doble();
    // Constructor por default.

    Doble(int num, double precio);
    // Constructor con número y precio.

    Doble(int num, double precio, double cargo);
    // Constructor sobrecargado.
    // Permite agregar cargo extra.

    double costo_total() const override;
    // Sobreescribe el cálculo de Habitacion.

    string to_string() const override;
    // Sobreescribe la forma de mostrar información.
};

#endif
