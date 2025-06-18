#include <vector>
#include <random>
#include <cmath>
#include <iostream>
#include <chrono>
#include "estructuras.h"

//comentar la version de Kruskal que no desee testear
#include "KruskalArreglo.h"
#include "KruskalHeap.h"
//#include "KruskalArregloOpt.h"
//#include "KruskalHeapOpt.h"



// Función que genera 2^exponente puntos con coordenadas aleatorias en [0, 1]
std::vector<Punto> generarPuntos(int exponente) {
    std::vector<Punto> puntos;
    size_t cantidad = static_cast<size_t>(1) << exponente; // 2^exponente

    // Motor de números aleatorios y distribución en [0,1]
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    puntos.reserve(cantidad);
    for (size_t i = 0; i < cantidad; ++i) {
        Punto p = { dist(gen), dist(gen) };
        puntos.push_back(p);
    }

    return puntos;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <exponente>\n";
        return 1;
    }

    int exponente = std::atoi(argv[1]); //exponente de la potencia de dos puntos que se generaran
  
    //generacion de puntos
    auto inicio = std::chrono::high_resolution_clock::now();
    
    std::vector<Punto> arreglo_puntos = generarPuntos(exponente);

   
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << "Tiempo para generar puntos: " << duracion.count() << " segundos\n";

    
    //Test algoritmo de Kruskal con arreglo:

    // Iniciar cronómetro
    auto inicio = std::chrono::high_resolution_clock::now();

    double peso_total_arreglo = kruskalArreglo(arreglo_puntos);

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << "Tiempo para generar puntos: " << duracion.count() << " segundos\n";
    std::cout << "Peso total del MST con Kruskal con arreglo: " << peso_total_arreglo << "\n";

    //Test algoritmo de Kruskal con Heap:

    // Iniciar cronómetro
    auto inicio = std::chrono::high_resolution_clock::now();

    double peso_total_Heap = kruskalHeap(arreglo_puntos);

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << "Tiempo para generar puntos: " << duracion.count() << " segundos\n";
    std::cout << "Peso total del MST con Kruskal con Heap: " << peso_total_Heap << "\n";

    return 0;
}