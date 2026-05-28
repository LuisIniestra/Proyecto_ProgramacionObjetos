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

  public:
    Habitacion();
    Habitacion(int num, int noch, double precio, string tip);

    int get_numero();
    int get_noches();
    double get_precio_noche();
    string get_tipo();

    virtual double costo_total();
    virtual string to_string();

};

#endif
