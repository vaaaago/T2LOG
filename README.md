# Tarea 2 Diseño y analisis de algoritmos
Integrantes: 
- Catalina Muñoz
- Javier Venegas

En este README se explican como compilar y ejecutar los archivos de esta entrega para hacer la experimentacion
planteada en la tarea.

Estas instrucciones estan pensadas para que esta tarea se ejecute en un sistema operativo de Linux. Para compilar el programa, ingrese
a la carpeta que contiene los archivos y revise el archivo main.cpp.

En el archivo main.cpp se deben comentar dos de los includes al inicio del archivo segun la version del algoritmo que se quiera testear
(las lineas a comentar estan indicadas en el archivo main.cpp).

Por ejemplo, si quiere testear el algoritmo de Kruskal con las versiones no optimizadas, debe comentar los include de la version optizada y viceversa.
En particular siga los siguientes pasos segun sea el caso:

- Compilacion y ejecucion del algoritmo sin optimizar:

1. en main.cpp comente y deje sin comentar los siguientes includes: 
...
//comentar la version de Kruskal que no desee testear
#include "KruskalArreglo.h"
#include "KruskalHeap.h"
//#include "KruskalArregloOpt.h"
//#include "KruskalHeapOpt.h"
...

2. Compile el programa con el comando:

g++ -std=c++17 -O2 -o expKruskal main.cpp KruskalArreglo.cpp KruskalHeap.cpp UnionFind.cpp 

3. Para ejecutar el programa debe dar como argumento el exponente de la potencia de 2 de la cantidad de puntos con la que se quiere testear, es decir,
si quiere probar con 2^10 puntos por ejemplo, entregue el numero 10 como argumento, como se muestra en el comando de ejemplo a continuación:

./expKruskal 10

4. Para repetir el experimento con una secuencia del mismo largo o de otro largo, repita el paso 3.

- Compilacion y ejecucion del algoritmo con optimización:

1. en main.cpp comente y deje sin comentar los siguientes includes: 
...
//comentar la version de Kruskal que no desee testear
//#include "KruskalArreglo.h"
//#include "KruskalHeap.h"
#include "KruskalArregloOpt.h"
#include "KruskalHeapOpt.h"
...

2. Compile el programa con el comando:

g++ -std=c++17 -O2 -o expKruskalO main.cpp KruskalArregloOpt.cpp KruskalHeapOpt.cpp UnionFindOpt.cpp 

3. Para ejecutar el programa debe dar como argumento el exponente de la potencia de 2 de la cantidad de puntos con la que se quiere testear, es decir,
si quiere probar con 2^10 puntos por ejemplo, entregue el numero 10 como argumento, como se muestra en el comando de ejemplo a continuación:

/expKruskalO 10

4. Para repetir el experimento con una secuencia del mismo largo o de otro largo, repita el paso 3.




