#include "algoritmoGuloso.hpp"

#include <iostream>
#include <queue>

using namespace std;

AlgoritmoGuloso::AlgoritmoGuloso(int numUsuarios, int numOfertas){
    this->numUsuarios = numUsuarios;
    this->numOfertas = numOfertas;
}

int AlgoritmoGuloso::calcularNumeroMatch(Grafo& grafo){
    int numMatches = 0; // guarda o numero de vagas ocupadas por usuarios
    int ofertasOcupadas[this->numOfertas] = {}; // guarda as ofertas ocupadas
    
    // Cria heap ordenado de forma crescente com pair (numero de ofertas, usuario)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> prioridade;
    for (int i = 1; i < grafo.getNumeroVertices(); i++) {
        prioridade.push(make_pair(grafo.getListaAdj()[i].size(), i));
    }

    while(!prioridade.empty()){
        pair<int, int> ofertasUsuario = prioridade.top(); // pega o usuario com menos ofertas disponiveis
        prioridade.pop(); // remove o usuario com menos ofertas disponiveis

        int indiceUsuario = ofertasUsuario.second;
        for(Aresta aresta : grafo.getListaAdj()[indiceUsuario]){
            // Na modelagem do grafo, as ofertas comecam a partir de numeroUsuarios + 1
            // para associar com os indices de um vetor iniciando de 0 faco essa subtracao
            int idOferta = aresta.destino - this->numUsuarios - 1;

            // Pega a primeira oferta nao ocupada
            if(!ofertasOcupadas[idOferta]){
                ofertasOcupadas[idOferta] = 1;
                numMatches ++;
                break;
            }
        }
    }

    return numMatches;
}

AlgoritmoGuloso::~AlgoritmoGuloso(){}