#include "UnionFindO.h"

UnionFind::UnionFind(int n) {
    this->n = n;
    parent = new int[n];
    size = new int[n];
    for (int i = 0; i < n; ++i) {
        parent[i] = i;   // Cada nodo es su propio representante
        size[i] = 1;     // Cada conjunto empieza con tamaño 1
    }
}

UnionFind::~UnionFind() {
    delete[] parent;
    delete[] size;
}

int UnionFind::find(int u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]);  // Path compression
    }
    return parent[u];
}

void UnionFind::unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

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