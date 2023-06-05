#ifndef ALGORITMO_EXATO_HPP
#define ALGORITMO_EXATO_HPP

#include "grafo.hpp"

class AlgoritmoExato {
public:
    AlgoritmoExato(int numUsuarios, int numOfertas);

    int calcularNumeroMaximoMatch(Grafo& grafo);

    virtual ~AlgoritmoExato();

private:
    int numUsuarios;
    int numOfertas;

    int verificarMatch(Grafo& grafo, int usuario, int visitados[], int matchVagas[]);
};

#endif //ALGORITMO_EXATO_HPP
