#include "UnionFindOpt.h"

UnionFind::UnionFind(int n) {
    this->n = n;
    parent = new int[n];
    size = new int[n]; //tamaño del conjunto
    for (int i = 0; i < n; ++i) {
        parent[i] = i;   // Cada nodo es su propio representante
        size[i] = 1;     // Cada conjunto empieza con Size 1
    }
}


int UnionFind::Find(int u) {
    if (u != parent[u]) {
        parent[u] = Find(parent[u]);  // Optimizacion
    }
    return parent[u];
}

void UnionFind::Union(int u, int v) {
    int rootU = Find(u);
    int rootV = Find(v);

    if (rootU == rootV) return;  // Ya están en el mismo conjunto

    // Union by size: el más pequeño apunta al más grande
    if (size[rootU] < size[rootV]) {
        parent[rootU] = rootV;
        size[rootV] += size[rootU];
    } else {
        parent[rootV] = rootU;
        size[rootU] += size[rootV];
    }
}