#include "grafo.hpp"
#include <iostream>

using namespace std;

Grafo::Grafo(){}

Grafo::Grafo(int numeroVertices){
    this->numeroVertices = numeroVertices;
    this->listaAdj = new std::vector<Aresta>[numeroVertices + 2];
}

void Grafo::adicionarAresta(int fonte, int destino){
    Aresta aresta = Aresta();

    aresta.fonte = fonte;
    aresta.destino = destino;

    this->listaAdj[fonte].push_back(aresta);
}

int Grafo::getNumeroVertices(){
    return this->numeroVertices;
}

vector<Aresta>* Grafo::getListaAdj(){
    return this->listaAdj;
}

bool Grafo::arestaPertencente(int fonte, int destino){
    for (Aresta v: this->listaAdj[fonte]) {
       if(v.destino == destino) return true;     
    }

    return false;
}

void Grafo::imprimir(){
    for(int i = 0; i < this->numeroVertices; i++){
        for (Aresta v: this->listaAdj[i]) {
            cout << "Fonte: " << v.fonte << ", Destino: " << v.destino << endl;
        }
    }
}

Grafo::~Grafo(){}