#include "hotel.h"
#include <iostream>

using namespace std;

Hotel::Hotel() {
  // Constructor de Hotel.

  num_habitaciones = 0;
  // Al inicio no hay habitaciones creadas.

  for (int i = 0; i < MAX_HABITACIONES; i++) {
    habitaciones[i] = 0;
    // Inicializa apuntadores para evitar basura de memoria.
  }
}

Hotel::~Hotel() {
  // Destructor de Hotel.

  for (int i = 0; i < num_habitaciones; i++) {
    delete habitaciones[i];
    // Libera la memoria de cada habitación creada con new.
  }
}

bool Hotel::noches_validas(int noches) {
  return noches > 0;
  // Solo acepta reservas de una o más noches.
}

void Hotel::crea_habitaciones_hotel() {
  // Crea automáticamente todas las habitaciones del hotel.
  // El usuario ya no inventa números ni precios.

  if (num_habitaciones > 0) {
    return;
    // Evita crear habitaciones duplicadas si el método se llama más de una vez.
  }

  int numero = 0;

  for (int piso = 1; piso <= 5; piso++) {
    // Pisos 1 al 5: habitaciones individuales.

    for (int cuarto = 1; cuarto <= 10; cuarto++) {
      // 10 habitaciones individuales por piso.

      numero = piso * 100 + cuarto;
      // Genera números como 101, 102, ..., 510.

      habitaciones[num_habitaciones] = new Individual(numero, 850, true);
      // Crea una habitación individual con precio fijo.

      num_habitaciones++;
    }
  }

  for (int piso = 6; piso <= 10; piso++) {
    // Pisos 6 al 10: habitaciones dobles.

    for (int cuarto = 1; cuarto <= 6; cuarto++) {
      // 6 habitaciones dobles por piso.

      numero = piso * 100 + cuarto;
      // Genera números como 601, 602, ..., 1006.

      habitaciones[num_habitaciones] = new Doble(numero, 1200, 250);
      // Crea una habitación doble con precio y cargo fijo.

      num_habitaciones++;
    }
  }

  for (int piso = 11; piso <= 12; piso++) {
    // Pisos 11 y 12: suites.

    for (int cuarto = 1; cuarto <= 4; cuarto++) {
      // 4 suites por piso.

      numero = piso * 100 + cuarto;
      // Genera números como 1101, 1102, ..., 1204.

      habitaciones[num_habitaciones] = new Suite(numero, 2500, 900, 300);
      // Crea una suite con precio, servicio extra y descuento fijo.

      num_habitaciones++;
    }
  }
}

void Hotel::muestra_habitaciones() {
  // Muestra todas las habitaciones del hotel.

  for (int i = 0; i < num_habitaciones; i++) {
    cout << habitaciones[i]->to_string();
    // Polimorfismo:
    // se ejecuta el to_string() correcto según el tipo real.
  }
}

void Hotel::muestra_disponibles() {
  // Muestra solo habitaciones disponibles.

  bool hay_disponibles = false;

  for (int i = 0; i < num_habitaciones; i++) {
    if (habitaciones[i]->get_disponible()) {
      cout << habitaciones[i]->to_string();
      hay_disponibles = true;
    }
  }

  if (!hay_disponibles) {
    cout << "No hay habitaciones disponibles.\n";
  }
}

void Hotel::muestra_disponibles(string tipo) {
  // Muestra habitaciones disponibles filtradas por tipo.

  bool hay_disponibles = false;

  for (int i = 0; i < num_habitaciones; i++) {
    if (habitaciones[i]->get_disponible() && habitaciones[i]->get_tipo() == tipo) {
      cout << habitaciones[i]->to_string();
      hay_disponibles = true;
    }
  }

  if (!hay_disponibles) {
    cout << "No hay habitaciones disponibles de tipo " << tipo << ".\n";
  }
}

void Hotel::muestra_ocupadas() {
  // Muestra habitaciones ocupadas.

  bool hay_ocupadas = false;

  for (int i = 0; i < num_habitaciones; i++) {
    if (!habitaciones[i]->get_disponible()) {
      cout << habitaciones[i]->to_string();
      hay_ocupadas = true;
    }
  }

  if (!hay_ocupadas) {
    cout << "No hay habitaciones ocupadas.\n";
  }
}

void Hotel::muestra_ocupadas(string tipo) {
  // Muestra habitaciones ocupadas filtradas por tipo.

  bool hay_ocupadas = false;

  for (int i = 0; i < num_habitaciones; i++) {
    if (!habitaciones[i]->get_disponible() && habitaciones[i]->get_tipo() == tipo) {
      cout << habitaciones[i]->to_string();
      hay_ocupadas = true;
    }
  }

  if (!hay_ocupadas) {
    cout << "No hay habitaciones ocupadas de tipo " << tipo << ".\n";
  }
}

bool Hotel::reservar_habitacion(string tipo, int noches) {
  // Reserva la primera habitación disponible del tipo solicitado.

  if (!noches_validas(noches)) {
    cout << "La cantidad de noches no es valida.\n";
    return false;
  }

  for (int i = 0; i < num_habitaciones; i++) {
    if (habitaciones[i]->get_tipo() == tipo && habitaciones[i]->get_disponible()) {
      // Busca la primera habitación disponible que coincida con el tipo.

      habitaciones[i]->reservar(noches);
      // Cambia el estado de la habitación a ocupada.

      cout << "Reservacion realizada correctamente.\n";
      cout << "Habitacion asignada:\n";
      cout << habitaciones[i]->to_string();

      return true;
    }
  }

  cout << "No hay habitaciones disponibles de tipo " << tipo << ".\n";
  return false;
}

double Hotel::calc_ingreso_total() {
  // Calcula el ingreso total de habitaciones ocupadas.

  double total = 0;

  for (int i = 0; i < num_habitaciones; i++) {
    if (!habitaciones[i]->get_disponible()) {
      total = total + habitaciones[i]->costo_total();
      // Polimorfismo:
      // cada habitación calcula su costo según su clase real.
    }
  }

  return total;
}

double Hotel::calc_ingreso_total(string tipo) {
  // Calcula el ingreso total de un tipo específico.

  double total = 0;

  for (int i = 0; i < num_habitaciones; i++) {
    if (!habitaciones[i]->get_disponible() && habitaciones[i]->get_tipo() == tipo) {
      total = total + habitaciones[i]->costo_total();
    }
  }

  return total;
}
