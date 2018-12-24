# tree-balancer
Tree balancer with search binary tree data structure using C++ language.


## Objetivo
El objetivo de esta práctica es implementar un programa que equilibre el peso que tienen que soportar las ramas de un árbol ficticio del que cuelgan bolas de plomo. Es decir, un equilibrador de árboles.

## Comportamiento del programa
Las bolas que colgarán de las ramas del árbol tiene un peso que varía entre los siguientes valores: 1, 2, 3, 5, 7 y 10 kg. El programa se ejecuta en varios pasos:
* El árbol se inicia creando un elemento raíz que soporta dos ramas principales (izquierda y derecha) que se deben equilibrar para que el árbol no caiga al suelo.
* Cada rama puede dividirse en dos ramas secundarias, que a su vez se pueden dividir en dos ramas terciarias, repitiéndose este proceso de forma indefinida.
* A continuación se crea una bola, cuyo peso varía entre los valores descritos anteriormente, y se coloca en una de las dos ramas.
* Se crea una nueva bola y se coloca de modo que compense, en la medida de lo posible, el peso soportado por la rama principal opuesta.
* Este proceso se repite tantas veces como sea necesario hasta que se cumpla esta regla: “la diferencia de pesos soportados por las ramas principales no debe exceder el 2% del peso total soportado por el árbol”.
* En ese caso, se considera que se ha equilibrado el árbol y el programa finaliza.

## Implementación
En la presente práctica se debe modelar el comportamiento del equilibrado del árbol teniendo en cuenta las siguientes consideraciones:
* Se modelará el árbol como un Árbol Binario de Búsqueda.
* Los valores de los pesos que colgarán de las ramas del árbol se generarán de forma aleatoria tomando, en cada turno, uno de los siguientes valores: 1, 2, 3, 5, 7 y 10 kg.
* El programa se ejecuta paso a paso y debe permitir la monitorización de los pesos soportados por las ramas principales del árbol, así como el número de pesos colgados
en cada rama y la altura total del árbol.
* Se valorará positivamente la implementación de cualquier mejora en el programa que permita la interacción entre el usuario y el programa. Algunas ideas pueden ser:
   * Que se permita al usuario quitar un peso de una de las dos ramas y el programa reequilibre automáticamente el árbol minimizando la diferencia de peso entre las dos ramas principales.
   * Que partiendo de un árbol inicial descompensado, el programa permita al usuario añadir pesos en cualquiera de las ramas hasta lograr equilibrarlo. Esta mejora podría considerarse un juego interactivo en el que se enfrentan, por turnos, el jugador contra el ordenador.