#ifndef HABITACION_H_
#define HABITACION_H_

#include <string>

using namespace std;

class Habitacion {
  // Clase padre del proyecto.
  // También es la clase abstracta del sistema.

  protected:
    int numero;
    // Número de la habitación.
    // Es protected para que las clases hijas puedan usarlo directamente.

    int noches;
    // Cantidad de noches que se va a rentar la habitación.

    double precio_noche;
    // Precio base por cada noche.

    string tipo;
    // Tipo de habitación: individual, doble o suite.

  public:
    Habitacion();
    // Constructor por default.
    // Lo dejamos como ejemplo de sobrecarga de constructores.

    Habitacion(int num, int noch, double precio, string tip);
    // Constructor con parámetros.
    // Sirve para inicializar una habitación con datos reales.
    // Aquí hay sobrecarga porque existen dos constructores Habitacion.

    virtual ~Habitacion();
    // Destructor virtual.
    // Se usa porque Hotel manejará habitaciones mediante apuntadores Habitacion*.
    // Esto ayuda a destruir correctamente los objetos hijos.

    int get_numero() const;
    // Regresa el número de la habitación.

    int get_noches() const;
    // Regresa la cantidad de noches.

    double get_precio_noche() const;
    // Regresa el precio por noche.

    string get_tipo() const;
    // Regresa el tipo de habitación.

    virtual double costo_total() const = 0;
    // MÉTODO VIRTUAL PURO.
    // Aquí se demuestra que Habitacion es una clase abstracta.
    // El = 0 significa que Habitacion no puede crear objetos directamente.
    // Obliga a las clases hijas a implementar su propio costo_total().

    virtual string to_string() const = 0;
    // MÉTODO VIRTUAL PURO.
    // También demuestra que Habitacion es abstracta.
    // Obliga a las clases hijas a implementar su propia forma de mostrar datos.
};

#endif
