#include <vector>
#include <random>
#include <cmath>
#include "grafo.h"
#include <iostream>

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

int main() {
    int exponente = 8;
    std::vector<Punto> puntos = generarPuntos(exponente);

    // Ejemplo: imprimir los primeros 5 puntos
    for (int i = 0; i < 5 && i < puntos.size(); ++i) {
        std::cout << "Punto " << i << ": (" << puntos[i].x << ", " << puntos[i].y << ")\n";
    }

    return 0;
}