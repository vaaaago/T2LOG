#include <queue>
#include <vector>
#include "UnionFindO.h"
#include "grafo.h"
#include "KruskalHeapO.h"

double kruskalHeap(const std::vector<Punto>& puntos) {
    int n = puntos.size();

    // Comparador invertido para min-heap
    auto comp = [](const Arista& a, const Arista& b) {
        return a.peso > b.peso;
    };

    std::priority_queue<Arista, std::vector<Arista>, decltype(comp)> heap(comp);

    // Insertar aristas al heap
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            heap.push({i, j, distanciaCuadrada(puntos[i], puntos[j])});

    UnionFind uf(n);
    double pesoTotal = 0.0;
    int aristasTomadas = 0;

    while (!heap.empty() && aristasTomadas < n - 1) {
        Arista a = heap.top();
        heap.pop();

        if (uf.find(a.u) != uf.find(a.v)) {
            uf.unite(a.u, a.v);
            pesoTotal += a.peso;
            aristasTomadas++;
        }
    }

    return pesoTotal;
}
