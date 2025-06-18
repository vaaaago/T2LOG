#ifndef KRUSKAL_HEAP_H
#define KRUSKAL_HEAP_H

#include <vector>
#include "UnionFind.h"
#include "grafo.h"

// Calcula el peso total del MST usando Kruskal con heap y UnionFind sin optimizar
double kruskalHeap(const std::vector<Punto>& puntos);

#endif
