#include "algoritmoExato.hpp"

#include <iostream>

using namespace std;

AlgoritmoExato::AlgoritmoExato(int numUsuarios, int numOfertas){
    this->numUsuarios = numUsuarios;
    this->numOfertas = numOfertas;
}

// retorna 1 caso seja possivel um match para o usuario e uma oferta
int AlgoritmoExato::verificarMatch(Grafo& grafo, int usuario, int visitados[], int matchVagas[]){
    // i = oferta - como no grafo os numeros que representam a oferta sao posteriores ao numero de
    // usuarios, ao acessar o grafo sempre somaremos i + numUsuarios + 1 (o grafo comeca de 1)
    for (int i = 0; i < this->numOfertas; i++) {
        int iVagaGrafo = i + this->numUsuarios + 1;

        // verifica se usuario possui interesse na oferta i e a mesma nao foi visitada
        if(grafo.arestaPertencente(usuario, iVagaGrafo) && !visitados[i]){
            visitados[i] = 1;

            // se a vaga nao possui match (= 0) com nenhum usuario ou
            // se um usuario previamente associado a vaga possui uma possibilidade alternativa
            // adiciona usuario a vaga
            if(matchVagas[i] <= 0 || this->verificarMatch(grafo, matchVagas[i], visitados, matchVagas)){
                matchVagas[i] = usuario;

                return 1;
            }
        }
    }
    
    return 0;
}

int AlgoritmoExato::calcularNumeroMaximoMatch(Grafo& grafo){
    int numMatches = 0; // guarda o numero de vagas ocupadas por usuarios
    int matchVagas[this->numOfertas] = {}; // indica se ha usuarios aplicados para vagas a partir do indice - 0 indica que nao ha associacoes

    for (int i = 0; i < (this->numUsuarios + 1); i++) {
        int visitados[this->numOfertas] = {}; // indica se a oferta ja foi vista - nesse caso inicia todas como nao visitadas

        // (i+1) representa o usuario, que no grafo comeca de 1
        if(this->verificarMatch(grafo, (i+1), visitados, matchVagas)){
            numMatches ++;
        }
    }

    return numMatches;
}

AlgoritmoExato::~AlgoritmoExato(){}