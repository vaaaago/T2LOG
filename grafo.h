#ifndef GRAFO_H
#define GRAFO_H

struct Punto {
    double x, y;
};

struct Arista {
    int u, v;
    double peso;

    bool operator<(const Arista& other) const {
        return peso < other.peso;
    }
};

// Calcula la distancia euclidiana al cuadrado entre dos puntos
inline double distanciaCuadrada(const Punto& a, const Punto& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

#endif // GRAFO_H
