#ifndef HABITACION_H_
#define HABITACION_H_

#include <string>
#include <ostream>

using namespace std;

class Habitacion {   // Clase padre del proyecto, tambien es la clase abstracta porque tiene métodos virtuales iguales a cero.

  protected:
    int numero;
    int noches;
    double precio_noche;
    string tipo;

  public:
    Habitacion();
    Habitacion(int num, int noch, double precio, string tip);

    virtual ~Habitacion();

    int get_numero() const;
    int get_noches() const;
    double get_precio_noche() const;
    string get_tipo() const;

    virtual double costo_total() const = 0;
    virtual string to_string() const = 0;

    friend ostream& operator<<(ostream& salida, const Habitacion& habitacion);
};

#endif
