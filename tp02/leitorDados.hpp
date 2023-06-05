#ifndef LEITOR_HPP
#define LEITOR_HPP

#include "grafo.hpp"

class Leitor {
public:
    Leitor();

    void ler(Grafo& grafo, int &numUsuarios, int &numOfertas);

    virtual ~Leitor();
};

#endif //LEITOR_HPP