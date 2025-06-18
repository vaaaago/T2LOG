// UnionFind.cpp
#include "UnionFind.h"

UnionFind::UnionFind(int n) {
    this->n = n;
    parent = new int[n];
    size = new int[n];
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
}

UnionFind::~UnionFind() {
    delete[] parent;
    delete[] size;
}

int UnionFind::find(int u) {
    while (u != parent[u]) {
        u = parent[u];  // No compresión de caminos
    }
    return u;
}

void UnionFind::unite(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

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
