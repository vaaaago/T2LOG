// UnionFind.cpp
#include "UnionFind.h"

UnionFind::UnionFind(int n) {
    this->n = n;
    parent = new int[n];
    size = new int[n]; //tamaño del conjunto
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
}

int UnionFind::Find(int u) {
    while (u != parent[u]) {
        u = parent[u];  // Version sin optimizar
    }
    return u;
}

void UnionFind::Union(int u, int v) {
    int rootU = Find(u);
    int rootV = Find(v);

    if (rootU == rootV) return;

    // Union por tamaño
    if (size[rootU] < size[rootV]) {
        parent[rootU] = rootV;
        size[rootV] += size[rootU];
    } else {
        parent[rootV] = rootU;
        size[rootU] += size[rootV];
    }
}
