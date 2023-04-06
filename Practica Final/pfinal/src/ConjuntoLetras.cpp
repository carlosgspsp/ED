/**

  * @file ConjuntoLetras.cpp

  * @author Carlos Garcia Segura, Jose Maria Poblador Marquez

  */

#include"ConjuntoLetras.h"
#include<cstdlib>
#include<cctype>

void ConjuntoLetras::push_back(Letra letra) {
    conjunto.push_back(letra);
}

istream& operator>>(istream & is, ConjuntoLetras &C) {
    int veces, puntuacion;
    char letra, lm;
    string bus;
    getline(is, bus);

    while (!is.eof()) {
        is >> letra;
        is >> veces;
        is >> puntuacion;
        lm=tolower(letra);
        Letra caracter(lm, veces, puntuacion);
        for (int i = 0; i < veces; i++) {
            C.conjunto.push_back(caracter);
        }
    }

    return is;
}

ostream& operator<<(ostream & os, ConjuntoLetras &C) {
    deque<Letra>::iterator iter = C.conjunto.begin();
    for (deque<Letra>::iterator it = C.conjunto.begin(); it != C.conjunto.end();) {
        ++it;
        if ((*it).Getletra() != (*iter).Getletra()) {
            os << (*iter).Getletra() << '\t' << (*iter).Getpuntuacion() << endl;
        }
        ++iter;
    }
    return os;
}

int ConjuntoLetras::Getpuntuacion(char letra) {
    for (int i = 0; i < conjunto.size(); i++) {
        if (conjunto[i].Getletra() == letra) {
            return conjunto[i].Getpuntuacion();
        }
    }
    return 0;
}

deque<Letra> ConjuntoLetras::Getletras() {
    deque<Letra> deck;
    unsigned int j = 1;
    for (unsigned int i = 0; i < this->conjunto.size(); i++) {
        if (j < this->conjunto.size()) {
            if (conjunto[i].Getletra() != conjunto[j].Getletra()) {
                deck.push_back(conjunto[i]);
            }
            j++;
        }
    }
    if (deck[deck.size() - 1].Getletra() != conjunto[conjunto.size() - 1].Getletra()) {
        deck.push_back(conjunto[conjunto.size() - 1]);
    }
    return deck;
}

int ConjuntoLetras::Getpuntuacion(string palabra) {
    int puntuacion = 0;
    for (unsigned int i = 0; i < palabra.size(); i++) {
        puntuacion += Getpuntuacion(palabra[i]);
    }

    return puntuacion;
}
