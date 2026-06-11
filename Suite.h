#ifndef SUITE_H_
#define SUITE_H_

#include "habitacion.h"
#include <string>

using namespace std;

class Suite: public Habitacion {
  // Suite hereda de Habitacion.

  private:
    double servicio_extra;
    // Cargo adicional por servicio de suite.

    double descuento;
    // Descuento aplicado a la suite.

  public:
    Suite();
    // Constructor por default.

    Suite(int num, int noch, double precio, double servicio);
    // Constructor con servicio extra.

    Suite(int num, int noch, double precio, double servicio, double desc);
    // Constructor sobrecargado.
    // Permite agregar descuento.

    double costo_total() const override;
    // Sobreescribe costo_total().

    string to_string() const override;
    // Sobreescribe to_string().
};

#endif
