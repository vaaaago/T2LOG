#include <vector>
#include <algorithm>
#include "UnionFind.h"
#include "grafo.h"
#include "KruskalArray.h"

double kruskalArray(const std::vector<Punto>& puntos) {
    int n = puntos.size();
    std::vector<Arista> aristas;

    // Generar todas las aristas
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            aristas.push_back({i, j, distanciaCuadrada(puntos[i], puntos[j])});

    // Ordenar las aristas
    std::sort(aristas.begin(), aristas.end());

    UnionFind uf(n);
    double pesoTotal = 0.0;

    for (const Arista& a : aristas) {
        if (uf.find(a.u) != uf.find(a.v)) {
            uf.unite(a.u, a.v);
            pesoTotal += a.peso;
        }
    }

    return pesoTotal;
}