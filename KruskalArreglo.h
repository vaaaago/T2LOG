#ifndef KRUSKAL_ARRAY_H
#define KRUSKAL_ARRAY_H

#include <vector>
#include "UnionFind.h"
#include "estructuras.h"

// Calcula el peso total del MST usando Kruskal con arreglo ordenado y UnionFind no optimizado
double kruskalArreglo(const std::vector<Punto>& puntos);

#endif
