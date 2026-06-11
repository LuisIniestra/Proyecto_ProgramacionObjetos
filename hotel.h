#ifndef HOTEL_H_
#define HOTEL_H_

#include <string>
#include "habitacion.h"
#include "individual.h"
#include "doble.h"
#include "suite.h"

using namespace std;

const int MAX_HABITACIONES = 100;
// Capacidad máxima del arreglo.
// El hotel usa 88 habitaciones en total.

class Hotel {
  // Clase administradora del sistema.

  private:
    Habitacion *habitaciones[MAX_HABITACIONES];
    // Arreglo de apuntadores a Habitacion.
    // Aquí se aplica polimorfismo porque puede guardar Individual, Doble o Suite.

    int num_habitaciones;
    // Cantidad de habitaciones creadas en el hotel.

    bool noches_validas(int noches);
    // Valida que la reserva tenga noches mayores a cero.

  public:
    Hotel();
    // Constructor de Hotel.

    ~Hotel();
    // Destructor.
    // Borra las habitaciones creadas con new.

    void crea_habitaciones_hotel();
    // Crea automáticamente las 88 habitaciones del hotel.

    void muestra_habitaciones();
    // Muestra todas las habitaciones.

    void muestra_disponibles();
    // Muestra todas las habitaciones disponibles.

    void muestra_disponibles(string tipo);
    // Muestra habitaciones disponibles por tipo.
    // Sobrecarga de método.

    void muestra_ocupadas();
    // Muestra todas las habitaciones ocupadas.

    void muestra_ocupadas(string tipo);
    // Muestra habitaciones ocupadas por tipo.
    // Sobrecarga de método.

    bool reservar_habitacion(string tipo, int noches);
    // Reserva automáticamente la primera habitación disponible del tipo solicitado.

    double calc_ingreso_total();
    // Calcula el ingreso total de habitaciones ocupadas.

    double calc_ingreso_total(string tipo);
    // Calcula ingreso por tipo de habitación.
    // Sobrecarga de método.
};

#endif
