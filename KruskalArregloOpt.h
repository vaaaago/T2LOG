#ifndef KRUSKAL_ARRAY_O_H
#define KRUSKAL_ARRAY_O_H

#include <vector>
#include "UnionFindOpt.h"
#include "estructuras.h"

// Calcula el peso total del MST usando Kruskal con arreglo ordenado y UnionFind optimizado
double kruskalArreglo(const std::vector<Punto>& puntos);

#endif

