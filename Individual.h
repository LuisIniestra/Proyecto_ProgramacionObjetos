#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

#include "habitacion.h"
#include <string>

using namespace std;

class Individual: public Habitacion { // La clase Individual hereda de Habitacion.

  private:
    bool desayuno_incluido; // Atributo propio de la habitación individual.

  public:
    Individual(); // Constructor.

    Individual(int num, int noch, double precio); // Constructor con parametros.

    Individual(int num, int noch, double precio, bool desayuno);
    // Constructor sobrecargado. Recibe los mismos datos anteriores, pero también si incluye desayuno. (overloading)
   
    double costo_total() const override;
    // Sobreescritura del método costo_total(). Este método venía como virtual en Habitacion.

    string to_string() const override;
    // Sobreescritura del método to_string().

};

#endif
