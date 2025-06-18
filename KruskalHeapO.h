#ifndef KRUSKAL_HEAP_O_H
#define KRUSKAL_HEAP_O_H

#include <vector>
#include "UnionFindO.h"
#include "grafo.h"

// Calcula el peso total del MST usando Kruskal con heap y UnionFind optimizado
double kruskalHeap(const std::vector<Punto>& puntos);

#endif // KRUSKAL_HEAP_O_H
