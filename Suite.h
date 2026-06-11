#ifndef SUITE_H_
#define SUITE_H_

#include "habitacion.h"
#include <string>

using namespace std;

class Suite: public Habitacion {
  // La clase Suite hereda de Habitacion.
  // Aquí se aplica herencia.
  // Suite es una clase concreta porque implementará los métodos abstractos de Habitacion.

  private:
    double servicio_extra;
    // Atributo propio de Suite.
    // Representa un cobro adicional por servicios de mayor categoría.

    double descuento;
    // Atributo propio de Suite.
    // Representa una reducción aplicada al costo final.

  public:
    Suite();
    // Constructor por default.
    // Crea una suite con valores base.
    // También ayuda a mostrar sobrecarga de constructores.

    Suite(int num, int noch, double precio, double servicio);
    // Constructor con número, noches, precio y servicio extra.
    // No recibe descuento, entonces el descuento se puede dejar en 0.

    Suite(int num, int noch, double precio, double servicio, double desc);
    // Constructor sobrecargado.
    // Recibe número, noches, precio, servicio extra y descuento.
    // Aquí se aplica overloading porque hay varios constructores Suite con diferentes parámetros.

    double costo_total() const override;
    // Sobreescritura del método costo_total().
    // Este método venía como virtual puro en Habitacion.
    // Suite está obligada a implementarlo porque Habitacion es abstracta.

    string to_string() const override;
    // Sobreescritura del método to_string().
    // Sirve para que Suite tenga su propia forma de mostrar información.
};

#endif
