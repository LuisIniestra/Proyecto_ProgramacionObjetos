#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

#include "habitacion.h"
#include <string>

using namespace std;

class Individual: public Habitacion {
  // Individual hereda de Habitacion.
  // Aquí se aplica herencia.

  private:
    bool desayuno_incluido;
    // Atributo propio de la habitación individual.

  public:
    Individual();
    // Constructor por default.

    Individual(int num, double precio);
    // Constructor con número y precio base.

    Individual(int num, double precio, bool desayuno);
    // Constructor sobrecargado.
    // Permite indicar si incluye desayuno.

    double costo_total() const override;
    // Sobreescribe el método abstracto de Habitacion.

    string to_string() const override;
    // Sobreescribe el método abstracto de Habitacion.
};

#endif
