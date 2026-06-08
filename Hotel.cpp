#include "hotel.h"
#include <iostream>

using namespace std;

Hotel::Hotel() { // Constructor de Hotel

  num_habitaciones = 0; // Inicializa el contador en cero porque al crear el hotel todavía no hay habitaciones registradas

  for (int i = 0; i < MAX_HABITACIONES; i++) { // Recorre todo el arreglo de apuntadores

    habitaciones[i] = 0; // Inicializa cada posición en 0. Esto evita que los apuntadores tengan datos de memoria
  }
}

Hotel::~Hotel() { // Destructor de Hotel. Se ejecuta automaticamente cuando el objeto hotel deja de existir

  for (int i = 0; i < num_habitaciones; i++) { // Recorre solamente las habitaciones que sí fueron registradas

    delete habitaciones[i]; // Libera la memoria de cada habitación creada con new. Esto es necesario porque Individual, Doble y Suite se crean en memoria dinamica.
    // Como Habitacion tiene destructor virtual, se destruye correctamente el objeto real.
  }
}

bool Hotel::datos_validos(int numero, int noches, double precio) { // Método auxiliar para validar datos antes de crear una habitacion

  return numero > 0 && noches > 0 && precio > 0;
  // Regresa true si el numero, las noches y el precio son mayores a cero. Si alguno no cumple regresa false
}

void Hotel::crea_ejemplos() { // Crea habitaciones de prueba para probar el programa sin pedir datos al usuario

  agrega_individual(101, 2, 850, true); // Agrega una habitación individual con desayuno. Usa la versión sobrecargada de agrega_individual que recibe bool desayuno

  agrega_individual(102, 1, 750); // Agrega una habitación individual sin desayuno. Usa la versión de agrega_individual sin bool desayuno

  agrega_doble(201, 3, 1200, 300); //Agrega una habitación doble con cargo extra

  agrega_doble(202, 2, 1100); // Agrega una habitación doble sin cargo extra

  agrega_suite(301, 2, 2500, 900, 300); // Agrega una suite con servicio extra y descuento

  agrega_suite(302, 1, 2800, 1000); // Agrega una suite con servicio extra, pero sin descuento
}

void Hotel::muestra_habitaciones() { // Metodo para mostrar todas las habitaciones registradas

  for (int i = 0; i < num_habitaciones; i++) { // Recorre todas las habitaciones que sí existen en el arreglo

    cout << habitaciones[i]->to_string();
    // Imprime la información de cada habitacion
    
}

void Hotel::muestra_habitaciones(string tipo) { // Metodo sobrecargado. Tiene el mismo nombre que muestra_habitaciones(), pero recibe un string

  for (int i = 0; i < num_habitaciones; i++) { // Recorre todas las habitaciones registradas

    if (habitaciones[i]->get_tipo() == tipo) { // Compara el tipo de la habitacion con el tipo recibido

      cout << habitaciones[i]->to_string();
      // Imprime solo las habitaciones que coinciden con el tipo.Tambien se aplica polimorfismo por el uso de to_string()
    }
  }
}

double Hotel::calc_ingreso_total() { // Calcula el ingreso total de todas las habitaciones

  double total = 0;

  for (int i = 0; i < num_habitaciones; i++) { // Recorre todas las habitaciones registradas

    total = total + habitaciones[i]->costo_total();
    // Suma el costo de cada habitacion
    // Si el objeto es Individual usa costo_total() de Individual, si es Doble usa costo_total() de Doble, si es Suite usa costo_total() de Suite
  }

  return total;
}

double Hotel::calc_ingreso_total(string tipo) { // Método sobrecargado. Calcula el ingreso total pero solo de un tipo de habitacion

  double total = 0;

  for (int i = 0; i < num_habitaciones; i++) {

    if (habitaciones[i]->get_tipo() == tipo) { // Solo toma en cuenta las habitaciones que coinciden con el tipo recibido

      total = total + habitaciones[i]->costo_total();
    }
  }

  return total;

}

void Hotel::agrega_individual(int numero, int noches, double precio) { // Agrega una habitación individual sin desayuno

  if (num_habitaciones < MAX_HABITACIONES && datos_validos(numero, noches, precio)) { // Primero revisa que haya espacio en el arreglo y que los datos  sean validos

    habitaciones[num_habitaciones] = new Individual(numero, noches, precio); // Crea un objeto Individual en memoria dinamica usando new

    num_habitaciones++;
  }
}

void Hotel::agrega_individual(int numero, int noches, double precio, bool desayuno) { // Agrega una habitación individual con desayuno (sobrecarga de agrega_individual)

  if (num_habitaciones < MAX_HABITACIONES && datos_validos(numero, noches, precio)) { // Valida espacio disponible y datos correctos

    habitaciones[num_habitaciones] = new Individual(numero, noches, precio, desayuno); // Crea un objeto Individual usando el constructor que recibe desayuno

    num_habitaciones++;

  }
}

void Hotel::agrega_doble(int numero, int noches, double precio) { // Agrega una habitación doble sin cargo extra.

  if (num_habitaciones < MAX_HABITACIONES && datos_validos(numero, noches, precio)) { // Valida que haya espacio y que los datos sean correctos.

    habitaciones[num_habitaciones] = new Doble(numero, noches, precio); // Crea un objeto Doble en memoria dinámica. Se guarda como Habitacion* (polimorfismo)

    num_habitaciones++;
  }
}

void Hotel::agrega_doble(int numero, int noches, double precio, double cargo) { // Agrega una habitación doble con cargo extra.
  // Es sobrecarga porque tiene el mismo nombre que el método anterior, pero recibe un parámetro extra.

  if (num_habitaciones < MAX_HABITACIONES && datos_validos(numero, noches, precio) && cargo >= 0) {
    // Valida espacio, datos base y que el cargo extra no sea negativo.

    habitaciones[num_habitaciones] = new Doble(numero, noches, precio, cargo);// Crea un objeto Doble con cargo extra.

    num_habitaciones++;
  }
}

void Hotel::agrega_suite(int numero, int noches, double precio, double servicio) { // Agrega una suite sin descuento.

  if (num_habitaciones < MAX_HABITACIONES && datos_validos(numero, noches, precio) && servicio >= 0) { // Valida espacio, datos base y que el servicio extra no sea negativo.

    habitaciones[num_habitaciones] = new Suite(numero, noches, precio, servicio); // Crea un objeto Suite con servicio extra.

    num_habitaciones++;
  }
}

void Hotel::agrega_suite(int numero, int noches, double precio, double servicio, double descuento) { // Agrega una suite con servicio extra y descuento.
  // Es sobrecarga de agrega_suite.

  double subtotal = (precio * noches) + servicio; // Calcula el subtotal antes del descuento.

  if (num_habitaciones < MAX_HABITACIONES && // Valida que haya espacio.
      datos_validos(numero, noches, precio) && // Valida datos base.
      servicio >= 0 && // Valida que servicio y descuento no sean negativos.
      descuento >= 0 && 
      descuento <= subtotal) { // Valida que el descuento no sea mayor que el subtotal.

    habitaciones[num_habitaciones] = new Suite(numero, noches, precio, servicio, descuento); // Crea un objeto Suite con servicio extra y descuento.

    num_habitaciones++;

  }
}
}
