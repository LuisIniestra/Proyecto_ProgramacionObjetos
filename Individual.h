#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_

#include "habitacion.h"
#include <string>

using namespace std;

class Individual: public Habitacion {
  // La clase Individual hereda de Habitacion.
  // Aquí se aplica herencia.
  // Individual es una habitación concreta, a diferencia de Habitacion que es abstracta.

  private:
    bool desayuno_incluido;
    // Atributo propio de la habitación individual.
    // Es private porque solo la clase Individual debe controlarlo directamente.
    // Aquí se aplica encapsulamiento.

  public:
    Individual();
    // Constructor por default.
    // Permite crear una habitación individual con valores base.
    // También ayuda a mostrar sobrecarga de constructores.

    Individual(int num, int noch, double precio);
    // Constructor con parámetros básicos.
    // Recibe número de habitación, noches y precio.
    // No recibe desayuno, por eso se puede manejar como false por default.

    Individual(int num, int noch, double precio, bool desayuno);
    // Constructor sobrecargado.
    // Recibe los mismos datos anteriores, pero también si incluye desayuno.
    // Aquí se ve overloading porque hay varios constructores Individual con diferentes parámetros.

    double costo_total() const override;
    // Sobreescritura del método costo_total().
    // Este método venía como virtual puro en Habitacion.
    // Individual está obligada a implementarlo porque Habitacion es abstracta.
    // Aquí se aplica overriding.

    string to_string() const override;
    // Sobreescritura del método to_string().
    // También venía como virtual puro en Habitacion.
    // Sirve para que Individual tenga su propia forma de mostrar información.
    // Aquí también se aplica overriding.
};

#endif
