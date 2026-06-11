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

    Doble(int num, int noch, double precio);
    // Constructor con número, noches y precio.

    Doble(int num, int noch, double precio, double cargo);
    // Constructor sobrecargado.
    // Permite agregar cargo extra.

    double costo_total() const override;
    // Sobreescribe el método abstracto costo_total().

    string to_string() const override;
    // Sobreescribe el método abstracto to_string().
};

#endif
