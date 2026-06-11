#ifndef HABITACION_H_
#define HABITACION_H_

#include <string>

using namespace std;

class Habitacion {

  protected:
    int numero;
    int noches;
    double precio_noche;
    string tipo;
    bool disponible;

  public:
    Habitacion();
    Habitacion(int num, double precio, string tip);

    virtual ~Habitacion();

    int get_numero() const;
    int get_noches() const;
    double get_precio_noche() const;
    string get_tipo() const;
    bool get_disponible() const;

    void reservar(int noch);
    void liberar();

    virtual double costo_total() const = 0;
    virtual string to_string() const = 0;
};

#endif
