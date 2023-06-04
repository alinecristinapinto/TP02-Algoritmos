#ifndef ALGORITMO_GULOSO_HPP
#define ALGORITMO_GULOSO_HPP

#include "grafo.hpp"

// Classe que implementa o algoritmo de match de grafo bipartido
// Baseado em: https://www.geeksforgeeks.org/maximum-bipartite-matching/ 
class AlgoritmoGuloso {
public:
    AlgoritmoGuloso(int numUsuarios, int numOfertas);

    int calcularNumeroMatch(Grafo& grafo);

    virtual ~AlgoritmoGuloso();

private:
    int numUsuarios;
    int numOfertas;
};

#endif //ALGORITMO_GULOSO_HPP