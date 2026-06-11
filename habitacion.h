/*
 *
 * Proyecto Hotel clase Habitacion
 *
 * Esta clase define el objeto abstracto Habitacion que contiene los atributos
 * generales de cualquier habitacion del hotel. De esta clase heredan
 * Individual, Doble y Suite.
 */

#ifndef HABITACION_H_
#define HABITACION_H_

#include <string>

using namespace std;

//Declaracion de clase Habitacion que es abstracta
class Habitacion {

  //Declaro variables de instancia protegidas
  protected:
    int numero;
    int noches;
    double precio_noche;
    string tipo;

  //Declaro constructores y metodos publicos
  public:
    Habitacion();
    Habitacion(int num, int noch, double precio, string tip);

    virtual ~Habitacion();

    int get_numero() const;
    int get_noches() const;
    double get_precio_noche() const;
    string get_tipo() const;

    virtual double costo_total() const = 0; //metodo abstracto sera sobreescrito
    virtual string to_string() const = 0;   //metodo abstracto sera sobreescrito
};

#endif // HABITACION_H_
