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

    int Find(int u);          // Encuentra el representante de u 
    void Union(int u, int v); // Une los conjuntos que contienen u y v
};

#endif
