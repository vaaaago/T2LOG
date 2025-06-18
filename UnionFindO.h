// UnionFindOptimizado.h
#ifndef UNIONFINDO_H
#define UNIONFINDO_H

class UnionFind {
private:
    int* parent;
    int* size;
    int n;

public:
    UnionFind(int n);         // Constructor
    ~UnionFind();             // Destructor

    int find(int u);          // Encuentra el representante de u (con path compression)
    void unite(int u, int v); // Une los conjuntos que contienen u y v (por rank)
};

#endif // UNIONFINDO_H
