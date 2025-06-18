#ifndef KRUSKAL_ARRAY_O_H
#define KRUSKAL_ARRAY_O_H

#include <vector>
#include "UnionFindO.h"
#include "grafo.h"

// Calcula el peso total del MST usando Kruskal con arreglo ordenado y UnionFind optimizado
double kruskalArray(const std::vector<Punto>& puntos);

#endif // KRUSKAL_ARRAY_O_H
