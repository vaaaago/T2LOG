#include <vector>
#include <random>
#include <cmath>
#include <iostream>
#include <chrono>
#include <iomanip>
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
  
    std::cout << std::fixed << std::setprecision(6); // Fuerza formato decimal con 6 decimales
    //generacion de puntos
    auto inicio_puntos = std::chrono::high_resolution_clock::now();
    
    std::vector<Punto> arreglo_puntos = generarPuntos(exponente);

   
    auto fin_puntos = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion_puntos = fin_puntos - inicio_puntos;
    std::cout << "Tiempo para generar puntos: " << duracion_puntos.count() << " segundos\n";

    
    //Test algoritmo de Kruskal con arreglo:

    // Iniciar cronómetro
    auto inicio_arreglo = std::chrono::high_resolution_clock::now();

    double peso_total_arreglo = kruskalArreglo(arreglo_puntos);

    auto fin_arreglo = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion_arreglo = fin_arreglo - inicio_arreglo;
    std::cout << "Tiempo de Kruskal con arreglo: " << duracion_arreglo.count() << " segundos\n";
    std::cout << "Peso total del MST con Kruskal con arreglo: " << peso_total_arreglo << "\n";

    //Test algoritmo de Kruskal con Heap:

    // Iniciar cronómetro
    auto inicio_heap = std::chrono::high_resolution_clock::now();

    double peso_total_Heap = kruskalHeap(arreglo_puntos);

    auto fin_heap = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion_heap = fin_heap - inicio_heap;
    std::cout << "Tiempo de Kruskal con Heap: " << duracion_heap.count() << " segundos\n";
    std::cout << "Peso total del MST con Kruskal con Heap: " << peso_total_Heap << "\n";

    return 0;
}