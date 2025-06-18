// UnionFind.h
#ifndef UNIONFIND_H
#define UNIONFIND_H

class UnionFind {
private:
    int* parent;
    int* size;
    int n;

public:
    UnionFind(int n);         // Constructor
    ~UnionFind();             // Destructor

    int find(int u);          // Encuentra el representante de u (sin compresión de caminos)
    void unite(int u, int v); // Une los conjuntos que contienen u y v (por rank)
};

#endif // UNIONFIND_H
