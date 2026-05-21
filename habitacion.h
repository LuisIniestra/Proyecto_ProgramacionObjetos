#ifndef HABITACION_H_
#define HABITACION_H_

#include <string>
#include <sstream>

using namespace std;

class Habitacion {

  protected:
    int numero;
    int noches;
    double precio_noche;
    string tipo;

  public:
    Habitacion(): numero(0), noches(0), precio_noche(0), tipo("habitacion") {};

    Habitacion(int num, int noch, double precio, string tip):
      numero(num), noches(noch), precio_noche(precio), tipo(tip) {};

    int get_numero() {
      return numero;
    }

    int get_noches() {
      return noches;
    }

    double get_precio_noche() {
      return precio_noche;
    }

    string get_tipo() {
      return tipo;
    }

    double costo_total() {
      return precio_noche * noches;
    }

    string to_string() {
      stringstream aux;

      aux << "Habitacion " << numero
          << " tipo " << tipo
          << " noches " << noches
          << " precio por noche " << precio_noche
          << " costo total " << costo_total()
          << "\n";

      return aux.str();
    }
};

class Individual: public Habitacion {

  private:
    bool desayuno_incluido;

  public:
    Individual(): Habitacion(0, 0, 0, "individual"), desayuno_incluido(false) {};

    Individual(int num, int noch, double precio):
      Habitacion(num, noch, precio, "individual"), desayuno_incluido(false) {};

    Individual(int num, int noch, double precio, bool desayuno):
      Habitacion(num, noch, precio, "individual"), desayuno_incluido(desayuno) {};

    double costo_total() {
      return precio_noche * noches;
    }

    string to_string() {
      stringstream aux;

      aux << "Habitacion " << numero
          << " tipo " << tipo
          << " noches " << noches
          << " precio por noche " << precio_noche
          << " desayuno incluido " << (desayuno_incluido ? "si" : "no")
          << " costo total " << costo_total()
          << "\n";

      return aux.str();
    }
};

class Doble: public Habitacion {

  private:
    double cargo_extra;

  public:
    Doble(): Habitacion(0, 0, 0, "doble"), cargo_extra(0) {};

    Doble(int num, int noch, double precio):
      Habitacion(num, noch, precio, "doble"), cargo_extra(0) {};

    Doble(int num, int noch, double precio, double cargo):
      Habitacion(num, noch, precio, "doble"), cargo_extra(cargo) {};

    double costo_total() {
      return (precio_noche * noches) + cargo_extra;
    }

    string to_string() {
      stringstream aux;

      aux << "Habitacion " << numero
          << " tipo " << tipo
          << " noches " << noches
          << " precio por noche " << precio_noche
          << " cargo extra " << cargo_extra
          << " costo total " << costo_total()
          << "\n";

      return aux.str();
    }
};

class Suite: public Habitacion {

  private:
    double servicio_extra;
    double descuento;

  public:
    Suite(): Habitacion(0, 0, 0, "suite"), servicio_extra(0), descuento(0) {};

    Suite(int num, int noch, double precio, double servicio):
      Habitacion(num, noch, precio, "suite"), servicio_extra(servicio), descuento(0) {};

    Suite(int num, int noch, double precio, double servicio, double desc):
      Habitacion(num, noch, precio, "suite"), servicio_extra(servicio), descuento(desc) {};

    double costo_total() {
      return (precio_noche * noches) + servicio_extra - descuento;
    }

    string to_string() {
      stringstream aux;

      aux << "Habitacion " << numero
          << " tipo " << tipo
          << " noches " << noches
          << " precio por noche " << precio_noche
          << " servicio extra " << servicio_extra
          << " descuento " << descuento
          << " costo total " << costo_total()
          << "\n";

      return aux.str();
    }
};
#endif
