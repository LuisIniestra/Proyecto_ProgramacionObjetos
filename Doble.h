#ifndef DOBLE_H_
#define DOBLE_H_

#include "habitacion.h"
#include <string>

using namespace std;

class Doble: public Habitacion { // La clase Doble hereda de Habitacion.

  private:
    double cargo_extra;
    // Atributo propio de la habitación doble

  public:
    Doble();
    // Constructor por default

    Doble(int num, int noch, double precio);
    // Constructor con parámetros basicos

    Doble(int num, int noch, double precio, double cargo);
    // Constructor sobrecargado. Recibe numero, noches, precio y cargo extra (overloading)

    double costo_total() const override;
    // Sobreescritura del método costo_total() de la clase abstracta

    string to_string() const override;
    // Sobreescritura del método to_string() de la clase abstracta
};

#endif
