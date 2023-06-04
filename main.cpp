#include <iostream>
#include "grafo.hpp"
#include "leitorDados.hpp"
#include "algoritmoExato.hpp"

#define INF 0x3f3f3f3f

using namespace std;

int main(int argc, char const *argv[]) {
    Leitor leitor = Leitor();
    Grafo grafo;
    int numUsuarios = 0;
    int numOfertas = 0;

    leitor.ler(grafo, numUsuarios, numOfertas);

    AlgoritmoExato exato = AlgoritmoExato(numUsuarios, numOfertas);

    cout << exato.calcularNumeroMaximoMatch(grafo) << endl;

    return 0;
}
