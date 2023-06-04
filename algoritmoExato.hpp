#ifndef ALGORITMO_EXATO_HPP
#define ALGORITMO_EXATO_HPP

#include "grafo.hpp"

// Classe que implementa o algoritmo de match de grafo bipartido
// Baseado em: https://www.geeksforgeeks.org/maximum-bipartite-matching/ 
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