#ifndef ALGORITMO_GULOSO_HPP
#define ALGORITMO_GULOSO_HPP

#include "grafo.hpp"

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
