#ifndef DOBLE_H_
#define DOBLE_H_

#include "habitacion.h"
#include <string>

using namespace std;

class Doble: public Habitacion {
  // La clase Doble hereda de Habitacion.
  // Aquí se aplica herencia.
  // Doble es una clase concreta porque implementará los métodos abstractos de Habitacion.

  private:
    double cargo_extra;
    // Atributo propio de la habitación doble.
    // Es private porque solo la clase Doble debe modificarlo directamente.
    // Aquí se aplica encapsulamiento.

  public:
    Doble();
    // Constructor por default.
    // Permite crear una habitación doble con valores base.
    // También ayuda a demostrar sobrecarga de constructores.

    Doble(int num, int noch, double precio);
    // Constructor con parámetros básicos.
    // Recibe número de habitación, noches y precio.
    // No recibe cargo extra, por eso el cargo se puede dejar en 0.

    Doble(int num, int noch, double precio, double cargo);
    // Constructor sobrecargado.
    // Recibe número, noches, precio y cargo extra.
    // Aquí se aplica overloading porque hay varios constructores Doble con diferentes parámetros.

    double costo_total() const override;
    // Sobreescritura del método costo_total().
    // Este método venía como virtual puro en Habitacion.
    // Doble está obligada a implementarlo porque Habitacion es abstracta.

    string to_string() const override;
    // Sobreescritura del método to_string().
    // Sirve para que Doble tenga su propia forma de mostrar información.
};

#endif
