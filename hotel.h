#ifndef HOTEL_H_
#define HOTEL_H_

#include <string>
#include "habitacion.h"
#include "individual.h"
#include "doble.h"
#include "suite.h"

using namespace std;

const int MAX_HABITACIONES = 100;
// Define el máximo de habitaciones que puede guardar el sistema.
// Esto evita crecer el arreglo sin control.

class Hotel {
  // Clase administradora del proyecto.
  // Su trabajo es manejar las habitaciones registradas.

  private:
    Habitacion *habitaciones[MAX_HABITACIONES];
    // Arreglo de apuntadores de tipo Habitacion*.
    // Aquí se aplica polimorfismo.
    // Aunque el arreglo es de Habitacion*, puede guardar objetos Individual, Doble o Suite.
    // Ejemplo: habitaciones[0] puede apuntar a una Individual.

    int num_habitaciones;
    // Contador de habitaciones registradas.
    // Sirve para saber cuántos espacios del arreglo ya están ocupados.

    bool datos_validos(int numero, int noches, double precio);
    // Método privado para validar datos básicos antes de crear una habitación.
    // Es private porque solo Hotel lo usa internamente.

  public:
    Hotel();
    // Constructor de Hotel.
    // Inicializa el contador y prepara el arreglo de apuntadores.

    ~Hotel();
    // Destructor de Hotel.
    // Libera la memoria de las habitaciones creadas con new.

    void crea_ejemplos();
    // Crea habitaciones de prueba para no capturar datos manualmente.

    void muestra_habitaciones();
    // Muestra todas las habitaciones registradas.

    void muestra_habitaciones(string tipo);
    // Muestra habitaciones filtradas por tipo.
    // Aquí hay sobrecarga porque existe otro método con el mismo nombre,
    // pero sin parámetros.

    double calc_ingreso_total();
    // Calcula el ingreso total de todas las habitaciones.

    double calc_ingreso_total(string tipo);
    // Calcula el ingreso total de un solo tipo de habitación.
    // Aquí también hay sobrecarga porque existe otra versión sin parámetros.

    void agrega_individual(int numero, int noches, double precio);
    // Agrega una habitación individual sin desayuno.
    // Usa el constructor de Individual sin el parámetro desayuno.

    void agrega_individual(int numero, int noches, double precio, bool desayuno);
    // Agrega una habitación individual con desayuno.
    // Hay sobrecarga porque este método tiene el mismo nombre,
    // pero recibe un parámetro extra.

    void agrega_doble(int numero, int noches, double precio);
    // Agrega una habitación doble sin cargo extra.

    void agrega_doble(int numero, int noches, double precio, double cargo);
    // Agrega una habitación doble con cargo extra.
    // Sobrecarga del método agrega_doble.

    void agrega_suite(int numero, int noches, double precio, double servicio);
    // Agrega una suite con servicio extra, pero sin descuento.

    void agrega_suite(int numero, int noches, double precio, double servicio, double descuento);
    // Agrega una suite con servicio extra y descuento.
    // Sobrecarga del método agrega_suite.
};

#endif
