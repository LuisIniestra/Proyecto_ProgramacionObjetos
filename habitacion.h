#ifndef HABITACION_H_
#define HABITACION_H_

#include <string>
#include <ostream>

using namespace std;

class Habitacion { // Esta es la clase padre del proyecto, tambien es la clase abstracta porque tiene métodos virtuales iguales a cero

  protected: // protected permite que las clases hijas usen este atributo
    int numero; 

    int noches; 

    double precio_noche; 

    string tipo; // Tipo de habitacion: individual, doble o suite

  public:
    Habitacion(); // Constructor para las clases hijas

    Habitacion(int num, int noch, double precio, string tip); 
    // Constructor con parametros, aqui hay sobrecarga porque existe mas de un constructor habitacion

    virtual ~Habitacion(); //destructor

    int get_numero() const; // Getter para consultar el número de habitación.

    int get_noches() const; // Getter para consultar el número de noches.

    double get_precio_noche() const; // Getter para consultar el precio por noche.

    string get_tipo() const; // Getter para consultar el tipo de habitación.

    virtual double costo_total() const = 0; 
    // METODO VIRTUAL ABSTRACTO.

    virtual string to_string() const = 0; 
   // METODO VIRTUAL ABSTRACTO.

    friend ostream& operator<<(ostream& salida, const Habitacion& habitacion); 
    // Sobrecarga del operador <<.
    // Permite imprimir una habitación con cout << habitacion.
};

#endif
