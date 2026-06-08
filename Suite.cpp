#include "suite.h"
#include <sstream>

using namespace std;

Suite::Suite(): Habitacion(0, 0, 0, "suite") {
  // Constructor por default de Suite

  servicio_extra = 0;

  descuento = 0;
  // Inicializa las variables en cero
}

Suite::Suite(int num, int noch, double precio, double servicio):
  Habitacion(num, noch, precio, "suite") {
  // Constructor con parámetros. Llama al constructor de Habitacion para inicializar los atributos heredados

  servicio_extra = servicio;
  // Guarda el servicio extra recibido

  descuento = 0;
  // Como este constructor no recibe descuento, se deja en cero
}

Suite::Suite(int num, int noch, double precio, double servicio, double desc):
  Habitacion(num, noch, precio, "suite") {
  // Constructor sobrecargado. Recibe número, noches, precio, servicio extra y descuento
  // Aquí se aplica sobrecarga porque Suite tiene varios constructores con distintos parámetros

  servicio_extra = servicio;
  // Guarda el servicio extra recibido

  descuento = desc;
  // Guarda el descuento recibido
}

double Suite::costo_total() const {
  // Implementación de costo_total() de la clase abstracta
  
  return (precio_noche * noches) + servicio_extra - descuento;
  // Calcula el costo total de la suite
}

string Suite::to_string() const {
  // Implementación de to_string() de la clase abstracta

  stringstream aux;
  // Se usa para construir el texto que se va a mostrar

  aux << "Habitacion " << numero << " tipo " << tipo << " noches " << noches << " precio por noche " << precio_noche << " servicio extra " << servicio_extra << " descuento " << descuento << " costo total " << costo_total() << "\n";
  // Aquí se arma el texto de salida
  // Usa atributos heredados de Habitacion y atributos propios de Suite

  return aux.str();
  // Convierte el stringstream en string y lo regresa
}
