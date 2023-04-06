/**

  * @file ConjuntoLetras.cpp

  * @author Carlos Garcia Segura, Jose Maria Poblador Marquez

  */

#include "BolsaLetras.h"
#include <cstdlib>
#include <vector>
#include <cassert>
#include <ctime>

using namespace std;


BolsaLetras::BolsaLetras(ConjuntoLetras c) {
    deque<Letra> aux;
    deque<Letra>::iterator it;
    aux = c.Getletras();
    for (it = aux.begin(); it != aux.end(); it++) {
        for(int i=0; i<(*it).Getrepeticiones(); i++)
        letras.push_back((*it).Getletra());
    }
}

void BolsaLetras::elimina_letra(char letra) {
    bool esta = false;
    deque<char>::iterator it;
    for (it = dequerandom.begin(); (it != dequerandom.end()) && (!esta); it++) {
        if (*it == letra) {
            esta = true;
            dequerandom.erase(it);
        }
    }
}
deque<char> BolsaLetras::Getdequerandom()
{
  return dequerandom;
}

deque<char> BolsaLetras::GetRandomletras(int n) {
    vector<int> usados;
    deque<char> deck;
    dequerandom.clear();
    for (int i = 0; i < n; ++i) {
        bool usado = false;
        int z = (rand() % letras.size());
        for (int j = 0; j < usados.size(); j++) {
            if (z == usados[j])
                usado = true;
        }
        if (!usado)
        {
            deck.push_back(letras[z]);
            dequerandom.push_back(letras[z]);
        }
            else i--;
    }

		return deck;

}

bool BolsaLetras::pertenece(char l) {
    bool p = false;
    deque<char>::iterator it;
    for (it = letras.begin(); it != letras.end(); it++) {
        if (*it == l) p = true;
    }
    return p;
}
bool BolsaLetras::pertenecerandom(char l) {
    bool p = false;
    deque<char>::iterator it;
    for (it = dequerandom.begin(); it != dequerandom.end(); it++) {
        if (*it == l) p = true;
    }
    return p;
}

BolsaLetras BolsaLetras::operator=(BolsaLetras & otra_bolsa) {
    letras = otra_bolsa.Getdeque();
    dequerandom = otra_bolsa.Getdequerandom();
    return *this;
}

deque<char> BolsaLetras::Getdeque() {
    return letras;
}
