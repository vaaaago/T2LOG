#include <vector>
#include <algorithm>
#include "UnionFindOpt.h"
#include "estructuras.h"
#include "KruskalArregloOpt.h"

double kruskalArray(const std::vector<Punto>& puntos) {
    int n = puntos.size();
    std::vector<Arista> arreglo_aristas;

    // Generar todas las aristas y meterlas al arreglo con sus pesos
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            arreglo_aristas.push_back({i, j, distanciaEuclidiana(puntos[i], puntos[j])});

    // Ordenar el arreglo de aristas
    std::sort(arreglo_aristas.begin(), arreglo_aristas.end());

    UnionFind uf(n);
    double pesoTotal = 0.0;

    for (const Arista& arista : arreglo_aristas) {
        if (uf.Find(arista.u) != uf.Find(arista.v)) {
            uf.Union(arista.u, arista.v);
            pesoTotal += arista.peso;
        }
    }

    return pesoTotal;
}