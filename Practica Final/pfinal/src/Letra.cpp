/**

  * @file ConjuntoLetras.cpp

  * @author Carlos Garcia Segura, Jose Maria Poblador Marquez

  */

#include"Letra.h"

Letra::Letra() {
    letra = '\0';
    final = false;
    repeticiones = 0;
    puntuacion = 0;
}

Letra::Letra(char l, bool f) {
    letra = l;
    final = f;
    repeticiones = puntuacion = 0;
}

Letra::Letra(char l, int r, int p) {
    letra = l;
    repeticiones = r;
    puntuacion = p;
    final = false;
}

char Letra::Getletra() {
    return letra;
}

int Letra::Getpuntuacion() {
    return puntuacion;
}

int Letra::Getrepeticiones() {
    return repeticiones;
}

bool Letra::operator==(Letra l) {
    return letra == l.Getletra();
}

bool Letra::Esfinal() {
    return final;
}

void Letra::Setfinal(bool f) {
    final = f;
}
