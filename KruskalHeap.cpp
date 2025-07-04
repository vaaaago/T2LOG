#include <queue>
#include <vector>
#include "UnionFind.h"
#include "estructuras.h"
#include "KruskalHeap.h"

double kruskalHeap(const std::vector<Punto>& puntos) {
    int n = puntos.size();

    // Comparador invertido para encontrar minimo en el heap
    auto comp = [](const Arista& a, const Arista& b) {
        return a.peso > b.peso;
    };

    std::priority_queue<Arista, std::vector<Arista>, decltype(comp)> heap(comp); //heap

    // crear y meter aristas en el heap
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            heap.push({i, j, distanciaEuclidiana(puntos[i], puntos[j])});

    UnionFind uf(n);
    double pesoTotal = 0.0;
    int aristasInsertadas = 0;

    while (!heap.empty() && aristasInsertadas < n - 1) {
        Arista arista = heap.top();
        heap.pop();

        if (uf.Find(arista.u) != uf.Find(arista.v)) {
            uf.Union(arista.u, arista.v);
            pesoTotal += arista.peso;
            aristasInsertadas++;
        }
    }

    return pesoTotal;
}
