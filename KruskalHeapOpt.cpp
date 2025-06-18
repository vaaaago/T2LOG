#include <queue>
#include <vector>
#include "UnionFindOpt.h"
#include "estructuras.h"
#include "KruskalHeapOpt.h"

double kruskalHeap(const std::vector<Punto>& puntos) {
    int n = puntos.size();

    // Comparador invertido para encontrar minimo en el heap
    auto comp = [](const Arista& a, const Arista& b) {
        return a.peso > b.peso;
    };

    std::priority_queue<Arista, std::vector<Arista>, decltype(comp)> heap(comp); //heap

    // creamos y metemos aristas al heap
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            heap.push({i, j, distanciaEuclidiana(puntos[i], puntos[j])});

    UnionFind uf(n);
    double pesoTotal = 0.0;
    int aristasInsertadas = 0;

    while (!heap.empty() && aristasInsertadas < n - 1) {
        Arista arista = heap.top();
        heap.pop();

        if (uf.Find(arista.u) != uf.Find(arista.v)) {  //si no se iguales, se unen
            uf.Union(arista.u, arista.v);
            pesoTotal += arista.peso;
            aristasInsertadas++;
        }
    }

    return pesoTotal;
}
