#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include <queue>

// Representa uma aresta do grafo
typedef struct Aresta {
    int fonte;
    int destino;
} Aresta;

class Grafo {
public:
    Grafo();

    Grafo(int numeroVertices);

    void adicionarAresta(int fonte, int destino);

    int getNumeroVertices();

    std::vector<Aresta>* getListaAdj();

    bool arestaPertencente(int fonte, int destino);
    
    // DEBUG
    void imprimir(); 

    ~Grafo();

private:
    int numeroVertices;
    std::vector<Aresta>* listaAdj;
};

#endif // GRAFO_HPP