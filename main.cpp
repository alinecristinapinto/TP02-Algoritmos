#include <iostream>
#include "grafo.hpp"
#include "leitorDados.hpp"
#include "algoritmoExato.hpp"
#include "algoritmoGuloso.hpp"

#include <algorithm>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

int main(int argc, char const *argv[]) {
    Leitor leitor = Leitor();
    Grafo grafo;
    int numUsuarios = 0;
    int numOfertas = 0;

    leitor.ler(grafo, numUsuarios, numOfertas);

    AlgoritmoGuloso guloso = AlgoritmoGuloso(numUsuarios, numOfertas);
    cout << "Guloso: " << guloso.calcularNumeroMatch(grafo) << endl;

    AlgoritmoExato exato = AlgoritmoExato(numUsuarios, numOfertas);
    cout << "Exato: " << exato.calcularNumeroMaximoMatch(grafo) << endl;

    return 0;
}
