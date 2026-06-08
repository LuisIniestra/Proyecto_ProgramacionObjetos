#ifndef SUITE_H_
#define SUITE_H_

#include "habitacion.h"
#include <string>

using namespace std;

class Suite: public Habitacion { // La clase Suite hereda de Habitacion.

  private:
    double servicio_extra;
    // Atributo propio de Suite.

    double descuento;
    // Atributo propio de Suite.

  public:
    Suite();
    // Constructor por default.

    Suite(int num, int noch, double precio, double servicio);
    // Constructor con número, noches, precio y servicio extra.

    Suite(int num, int noch, double precio, double servicio, double desc);
    // Constructor sobrecargado. Recibe número, noches, precio, servicio extra y descuento.

    double costo_total() const override;
    // Sobreescritura del método costo_total() de la clase abstracta.

    string to_string() const override;
    // Sobreescritura del método to_string() de la clase abstracta.
};

#endif
