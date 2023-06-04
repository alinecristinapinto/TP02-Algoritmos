#include "leitorDados.hpp"
#include <iostream>

#include <map>

using namespace std;

Leitor::Leitor(){}

void Leitor::ler(Grafo& grafo, int &numUsuarios, int &numOfertas){
    int numQualificacoes;
    cin >> numUsuarios >> numOfertas >> numQualificacoes;

    grafo = Grafo(numUsuarios);
    std::map<string, int> mapVerticesParaNum; // map auxiliar para transformar string em numero
    int idUsuario = 0;  // será incrementado para usuarios = 1 ... numero de usuarios
    int idOferta = numUsuarios;  // será incrementado para ofertas = numero de usuarios + 1 ... numero de ofertas

    string usuario, vaga;
    for(int i=0; i<numQualificacoes; i++){
        cin >> usuario >> vaga;

        // mapeia os vertices de string para numeros
        if(mapVerticesParaNum.count(usuario) == 0)
            mapVerticesParaNum.insert(make_pair(usuario, ++idUsuario));
  
        if(mapVerticesParaNum.count(vaga) == 0)
            mapVerticesParaNum.insert(make_pair(vaga, ++idOferta));
        
        int numUsuario = mapVerticesParaNum.find(usuario)->second;
        int numVaga = mapVerticesParaNum.find(vaga)->second;

        grafo.adicionarAresta(numUsuario, numVaga);
    }
}

Leitor::~Leitor(){}