# TC1030 Proyecto Hotel

Este proyecto está hecho para la materia TC1030 y trata sobre un sistema básico para administrar habitaciones de un hotel.

El programa maneja diferentes tipos de habitaciones, por lo que se genera una estructura de clases para poder calcular el costo total de hospedaje dependiendo del tipo de habitación. Los tipos de habitaciones que se manejan son Individual, Doble y Suite.

Cada habitación calcula su costo de forma diferente. La habitación individual calcula el costo con base en el precio por noche y el número de noches. La habitación doble agrega un cargo extra. La suite agrega un servicio extra y puede aplicar un descuento.

## Funcionalidad

El programa permite registrar habitaciones y calcular diferentes tipos de costos de hospedaje:

habitaciones individuales, habitaciones dobles y suites.

Consta de un menú con opciones iniciales y corre sobre consola.

Las funciones principales del programa son:

- agregar habitación individual
- agregar habitación doble
- agregar suite
- mostrar todas las habitaciones
- mostrar habitaciones por tipo
- calcular ingreso total del hotel
- calcular ingreso por tipo de habitación

## Consideraciones

El programa solo corre en consola y está hecho con C++ estándar, por lo que puede correr en diferentes sistemas operativos.

El proyecto aplica conceptos de programación orientada a objetos como clase abstracta, herencia, polimorfismo y encapsulamiento.

La clase `Habitacion` es abstracta y de ella heredan las clases `Individual`, `Doble` y `Suite`. La clase `Hotel` administra las habitaciones usando objetos de tipo `Habitacion`.

Compilar con:

`g++ Habitacion.h Individual.h Doble.h Suite.h Hotel.h main.cpp`

Correr en Linux:

`./a.out`

Correr en Windows:

`a.exe`
