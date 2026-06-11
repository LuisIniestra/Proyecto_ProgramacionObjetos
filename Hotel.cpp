#include "hotel.h"
#include <iostream>

using namespace std;

Hotel::Hotel() {
  // Constructor de Hotel.
  // Se ejecuta cuando en main.cpp hacemos: Hotel hotel;

  num_habitaciones = 0;
  // Inicializa el contador en cero porque al crear el hotel todavía no hay habitaciones registradas.

  for (int i = 0; i < MAX_HABITACIONES; i++) {
    // Recorre todo el arreglo de apuntadores.

    habitaciones[i] = 0;
    // Inicializa cada posición en 0.
    // Esto evita que los apuntadores tengan basura de memoria.
  }
}

Hotel::~Hotel() {
  // Destructor de Hotel.
  // Se ejecuta automáticamente cuando el objeto hotel deja de existir.

  for (int i = 0; i < num_habitaciones; i++) {
    // Recorre solamente las habitaciones que sí fueron registradas.

    delete habitaciones[i];
    // Libera la memoria de cada habitación creada con new.
    // Esto es necesario porque Individual, Doble y Suite se crean en memoria dinámica.
    // Como Habitacion tiene destructor virtual, se destruye correctamente el objeto real.
  }
}

bool Hotel::datos_validos(int numero, int noches, double precio) {
  // Método auxiliar para validar datos antes de crear una habitación.
  // Es private porque solo Hotel lo usa internamente.

  return numero > 0 && noches > 0 && precio > 0;
  // Regresa true si el número, las noches y el precio son mayores a cero.
  // Si alguno no cumple, regresa false.
}

void Hotel::crea_ejemplos() {
  // Crea habitaciones de prueba.
  // Sirve para probar el programa sin pedir datos al usuario.

  agrega_individual(101, 2, 850, true);
  // Agrega una habitación individual con desayuno.
  // Usa la versión sobrecargada de agrega_individual que recibe bool desayuno.

  agrega_individual(102, 1, 750);
  // Agrega una habitación individual sin desayuno.
  // Usa la versión de agrega_individual sin bool desayuno.

  agrega_doble(201, 3, 1200, 300);
  // Agrega una habitación doble con cargo extra.

  agrega_doble(202, 2, 1100);
  // Agrega una habitación doble sin cargo extra.

  agrega_suite(301, 2, 2500, 900, 300);
  // Agrega una suite con servicio extra y descuento.

  agrega_suite(302, 1, 2800, 1000);
  // Agrega una suite con servicio extra, pero sin descuento.
}

void Hotel::muestra_habitaciones() {
  // Método para mostrar todas las habitaciones registradas.

  for (int i = 0; i < num_habitaciones; i++) {
    // Recorre todas las habitaciones que sí existen en el arreglo.

    cout << habitaciones[i]->to_string();
    // Imprime la información de cada habitación.
    // Aquí se aplica polimorfismo:
    // aunque habitaciones[i] es Habitacion*, se ejecuta el to_string() real
    // de Individual, Doble o Suite.
  }
}

void Hotel::muestra_habitaciones(string tipo) {
  // Método sobrecargado.
  // Tiene el mismo nombre que muestra_habitaciones(), pero recibe un string.
  // Sirve para mostrar solo un tipo de habitación.

  for (int i = 0; i < num_habitaciones; i++) {
    // Recorre todas las habitaciones registradas.

    if (habitaciones[i]->get_tipo() == tipo) {
      // Compara el tipo de la habitación con el tipo recibido.
      // Por ejemplo: "individual", "doble" o "suite".

      cout << habitaciones[i]->to_string();
      // Imprime solo las habitaciones que coinciden con el tipo.
      // También se aplica polimorfismo por el uso de to_string().
    }
  }
}

double Hotel::calc_ingreso_total() {
  // Calcula el ingreso total de todas las habitaciones.
  // Es decir, suma todos los costos.

  double total = 0;
  // Variable acumuladora.
  // Aquí se irá sumando el costo de cada habitación.

  for (int i = 0; i < num_habitaciones; i++) {
    // Recorre todas las habitaciones registradas.

    total = total + habitaciones[i]->costo_total();
    // Suma el costo de cada habitación.
    // Aquí se aplica polimorfismo:
    // si el objeto real es Individual, usa costo_total() de Individual.
    // si es Doble, usa costo_total() de Doble.
    // si es Suite, usa costo_total() de Suite.
  }

  return total;
  // Regresa la suma total.
}

double Hotel::calc_ingreso_total(string tipo) {
  // Método sobrecargado.
  // Calcula el ingreso total, pero solo de un tipo de habitación.

  double total = 0;
  // Variable acumuladora.

  for (int i = 0; i < num_habitaciones; i++) {
    // Recorre todas las habitaciones.

    if (habitaciones[i]->get_tipo() == tipo) {
      // Solo toma en cuenta las habitaciones que coinciden con el tipo recibido.

      total = total + habitaciones[i]->costo_total();
      // Suma el costo de esa habitación.
      // Aquí también se aplica polimorfismo.
    }
  }

  return total;
  // Regresa el ingreso total del tipo solicitado.
}

void Hotel::agrega_individual(int numero, int noches, double precio) {
  // Agrega una habitación individual sin desayuno.

  if (num_habitaciones < MAX_HABITACIONES && datos_validos(numero, noches, precio)) {
    // Primero revisa que haya espacio en el arreglo.
    // También revisa que los datos principales sean válidos.

    habitaciones[num_habitaciones] = new Individual(numero, noches, precio);
    // Crea un objeto Individual en memoria dinámica usando new.
    // Aunque el objeto real es Individual, se guarda como Habitacion*.
    // Aquí se aplica polimorfismo.

    num_habitaciones++;
    // Aumenta el contador porque ya se agregó una habitación.
  }
}

void Hotel::agrega_individual(int numero, int noches, double precio, bool desayuno) {
  // Agrega una habitación individual con desayuno.
  // Este método es sobrecarga de agrega_individual.

  if (num_habitaciones < MAX_HABITACIONES && datos_validos(numero, noches, precio)) {
    // Valida espacio disponible y datos correctos.

    habitaciones[num_habitaciones] = new Individual(numero, noches, precio, desayuno);
    // Crea un objeto Individual usando el constructor que recibe desayuno.

    num_habitaciones++;
    // Aumenta el contador de habitaciones.
  }
}

void Hotel::agrega_doble(int numero, int noches, double precio) {
  // Agrega una habitación doble sin cargo extra.

  if (num_habitaciones < MAX_HABITACIONES && datos_validos(numero, noches, precio)) {
    // Valida que haya espacio y que los datos sean correctos.

    habitaciones[num_habitaciones] = new Doble(numero, noches, precio);
    // Crea un objeto Doble en memoria dinámica.
    // Se guarda como Habitacion*, aplicando polimorfismo.

    num_habitaciones++;
    // Aumenta el contador.
  }
}

void Hotel::agrega_doble(int numero, int noches, double precio, double cargo) {
  // Agrega una habitación doble con cargo extra.
  // Es sobrecarga porque tiene el mismo nombre que el método anterior,
  // pero recibe un parámetro extra.

  if (num_habitaciones < MAX_HABITACIONES && datos_validos(numero, noches, precio) && cargo >= 0) {
    // Valida espacio, datos base y que el cargo extra no sea negativo.

    habitaciones[num_habitaciones] = new Doble(numero, noches, precio, cargo);
    // Crea un objeto Doble con cargo extra.

    num_habitaciones++;
    // Aumenta el contador.
  }
}

void Hotel::agrega_suite(int numero, int noches, double precio, double servicio) {
  // Agrega una suite sin descuento.

  if (num_habitaciones < MAX_HABITACIONES && datos_validos(numero, noches, precio) && servicio >= 0) {
    // Valida espacio, datos base y que el servicio extra no sea negativo.

    habitaciones[num_habitaciones] = new Suite(numero, noches, precio, servicio);
    // Crea un objeto Suite con servicio extra.

    num_habitaciones++;
    // Aumenta el contador.
  }
}

void Hotel::agrega_suite(int numero, int noches, double precio, double servicio, double descuento) {
  // Agrega una suite con servicio extra y descuento.
  // Es sobrecarga de agrega_suite.

  double subtotal = (precio * noches) + servicio;
  // Calcula el subtotal antes del descuento.
  // Esto sirve para validar que el descuento no sea mayor al costo real.

  if (num_habitaciones < MAX_HABITACIONES &&
      datos_validos(numero, noches, precio) &&
      servicio >= 0 &&
      descuento >= 0 &&
      descuento <= subtotal) {
    // Valida que haya espacio.
    // Valida datos base.
    // Valida que servicio y descuento no sean negativos.
    // Valida que el descuento no sea mayor que el subtotal.

    habitaciones[num_habitaciones] = new Suite(numero, noches, precio, servicio, descuento);
    // Crea un objeto Suite con servicio extra y descuento.

    num_habitaciones++;
    // Aumenta el contador.
  }
}
