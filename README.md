# TC1030 Proyecto Hotel

Este proyecto trata sobre un sistema básico para administrar habitaciones de un hotel. La idea principal es manejar distintos tipos de habitaciones y calcular el costo de hospedaje dependiendo de sus características.

El sistema trabaja con habitaciones Individuales, Dobles y Suites. Cada tipo de habitación tiene una forma diferente de calcular su costo, por lo que el proyecto permite aplicar conceptos de Programación Orientada a Objetos como herencia, polimorfismo, abstracción y encapsulamiento.

## Funcionalidad

El programa permitirá registrar diferentes tipos de habitaciones dentro de un hotel.

También permitirá mostrar la información de las habitaciones registradas y calcular el costo total de hospedaje según el tipo de habitación.

Las habitaciones consideradas son:

- Habitación Individual
- Habitación Doble
- Suite

Cada una tendrá atributos y cálculos propios, pero todas partirán de una clase general llamada `Habitacion`.

## Casos que podrían afectar el funcionamiento

El proyecto podría fallar o generar resultados incorrectos si no se validan algunos datos importantes.

Los casos principales son:

- Registrar una habitación con número inválido, como cero o negativo.
- Ingresar cero noches o una cantidad negativa de noches.
- Ingresar un precio por noche igual a cero o negativo.
- Ingresar cargos extra o servicios extra negativos.
- Ingresar texto cuando el programa espera un número.

Estos casos se deben validar para evitar errores en los cálculos y en la ejecución del programa.
