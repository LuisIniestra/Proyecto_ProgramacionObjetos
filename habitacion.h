#ifndef HABITACION_H_
#define HABITACION_H_

#include <string>

using namespace std;

class Habitacion {
  // Clase padre del proyecto.
  // Es abstracta porque tiene métodos virtuales puros.

  protected:
    int numero;
    // Número de la habitación.

    int noches;
    // Cantidad de noches que se va a reservar.

    double precio_noche;
    // Precio que el usuario asigna por noche.

    string tipo;
    // Tipo de habitación: individual, doble o suite.

  public:
    Habitacion();
    // Constructor por default.

    Habitacion(int num, int noch, double precio, string tip);
    // Constructor con parámetros.
    // Aquí hay sobrecarga porque existe más de un constructor Habitacion.

    virtual ~Habitacion();
    // Destructor virtual.
    // Es importante porque Hotel borra objetos usando apuntadores Habitacion*.

    int get_numero() const;
    // Regresa el número de habitación.

    int get_noches() const;
    // Regresa la cantidad de noches.

    double get_precio_noche() const;
    // Regresa el precio por noche.

    string get_tipo() const;
    // Regresa el tipo de habitación.

    virtual double costo_total() const = 0;
    // Método virtual puro.
    // Aquí se demuestra que Habitacion es clase abstracta.
    // Obliga a las clases hijas a implementar su propio cálculo.

    virtual string to_string() const = 0;
    // Método virtual puro.
    // Obliga a las clases hijas a implementar su propia forma de mostrar datos.
};

#endif
