#ifndef HABITACION_H_
#define HABITACION_H_

#include <string>

using namespace std;

class Habitacion {
  // Clase padre del proyecto.
  // Es abstracta porque tiene métodos virtuales puros.

  protected:
    int numero;
    // Número real de la habitación dentro del hotel.

    int noches;
    // Cantidad de noches reservadas.
    // Si la habitación está disponible, este valor queda en 0.

    double precio_noche;
    // Precio base por noche.
    // El usuario ya no lo decide; el sistema lo asigna según el tipo de habitación.

    string tipo;
    // Tipo de habitación: individual, doble o suite.

    bool disponible;
    // Indica si la habitación está disponible o ya fue reservada.

  public:
    Habitacion();
    // Constructor por default.

    Habitacion(int num, double precio, string tip);
    // Constructor con parámetros.
    // Se usa para crear habitaciones reales con número, precio y tipo.

    virtual ~Habitacion();
    // Destructor virtual.
    // Es importante porque Hotel borra objetos usando apuntadores Habitacion*.

    int get_numero() const;
    // Regresa el número de habitación.

    int get_noches() const;
    // Regresa la cantidad de noches reservadas.

    double get_precio_noche() const;
    // Regresa el precio por noche.

    string get_tipo() const;
    // Regresa el tipo de habitación.

    bool get_disponible() const;
    // Regresa true si la habitación está disponible.

    void reservar(int noch);
    // Cambia la habitación a ocupada y guarda el número de noches.

    void liberar();
    // Libera la habitación y reinicia las noches a 0.

    virtual double costo_total() const = 0;
    // Método virtual puro.
    // Aquí se demuestra que Habitacion es una clase abstracta.
    // Obliga a Individual, Doble y Suite a implementar su propio cálculo.

    virtual string to_string() const = 0;
    // Método virtual puro.
    // Obliga a las clases hijas a implementar su propia forma de mostrar datos.
};

#endif
