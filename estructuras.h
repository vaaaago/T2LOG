#ifndef GRAFO_H
#define GRAFO_H

struct Punto {
    double x, y;
};

struct Arista {
    int u, v;
    double peso;

    //operador para comparar esta arista con otra
    bool operator<(const Arista& arista) const {
        return peso < arista.peso;
    }
};

// Calcula la distancia euclidiana entre dos puntos
inline double distanciaEuclidiana(const Punto& a, const Punto& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

#endif 
