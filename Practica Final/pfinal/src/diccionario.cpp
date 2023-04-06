/**

  * @file ConjuntoLetras.cpp

  * @author Carlos Garcia Segura, Jose Maria Poblador Marquez

  */

#include<iostream>
#include"diccionario.h"

using namespace std;

int Diccionario::size() const {
    return datos.size();
}

void Diccionario::aniade_palabra(string cadena) {
    ArbolGeneral<Letra>::Nodo nodo = datos.raiz();
    ArbolGeneral<Letra> rama;
    if (datos.hijomasizquierda(nodo) == NULL) {
        rama = ArbolGeneral<Letra>(Letra(cadena[0], cadena.size() == 1));
        datos.insertar_hijomasizquierda(nodo, rama);
    }
    nodo = datos.hijomasizquierda(nodo);


    for (unsigned int i = 0; i < cadena.size(); i++) {
        while (datos.etiqueta(nodo).Getletra() < cadena.at(i) && datos.hermanoderecha(nodo) != NULL) {
            nodo = datos.hermanoderecha(nodo);
        }

        if (datos.etiqueta(nodo).Getletra() != cadena.at(i)) {
            bool perfecto = (i == cadena.size() - 1);
            Letra let(cadena.at(i), perfecto);
            rama = ArbolGeneral<Letra>(let);
            datos.insertar_hermanoderecha(nodo, rama);
            nodo = datos.hermanoderecha(nodo);
        }
        if (datos.hijomasizquierda(nodo) == NULL && cadena.size() > i + 1) {
            rama = ArbolGeneral<Letra>(Letra(cadena.at(i + 1), i == cadena.size() - 2));
            datos.insertar_hijomasizquierda(nodo, rama);
        }
        nodo = datos.hijomasizquierda(nodo);
    }
}

vector<int> Diccionario::numero_apariciones() {
    vector<int> numero_apariciones;

    for (int i = 'a'; i <= 'z'; i++) {
        numero_apariciones.push_back(0);
    }
    Diccionario::iterator iterador;

    for (iterador = begin(); iterador != end(); ++iterador) {
        for (int i = 0; i < (*iterador).size(); i++) {
            if ((*iterador)[i] >= 'a' && (*iterador)[i] <= 'z') {
                numero_apariciones[(*iterador)[i] - 'a']++;
            }
        }
    }

    return numero_apariciones;
}

int Diccionario::total_letras() {
    vector<int> numero_apariciones = this->numero_apariciones();
    int tamanio = numero_apariciones.size();
    int total;

    for (int i = 0; i < tamanio; i++) {
        total = total + numero_apariciones[i];
    }
    return total;
}

vector<string> Diccionario::PalabrasLongitud(int longitud) {
    vector<string> palabras_longitud;
    Diccionario::iterator iterador;

    for (iterador = begin(); iterador != end(); ++iterador) {

        if ((iterador.getlongitud() == longitud)) {
            palabras_longitud.push_back(*iterador);
        }
    }
    return palabras_longitud;
}

bool Diccionario::Esta(string palabra) {
    bool esta = true;
    unsigned int posicion = 0;
    ArbolGeneral<Letra>::Nodo nodo = datos.raiz();
    nodo = datos.hijomasizquierda(nodo);

    while (posicion < palabra.size() && esta) {
        if (datos.etiqueta(nodo).Getletra() != palabra.at(posicion)) {
            nodo = datos.hermanoderecha(nodo);
            if (nodo == NULL) {
                esta = false;
            }
        } else {
            nodo = datos.hijomasizquierda(nodo);
            posicion++;
        }
    }
    if (nodo == NULL) {
        return esta;
    } else {
        return datos.etiqueta(nodo).Esfinal() && esta;
    }


}

vector<string> Diccionario::encuentra_palabras(BolsaLetras bolsa, ArbolGeneral<Letra>::Nodo nodo){
    
    vector<string> palabras, palabras_aux;
    string palabra_aux;
    BolsaLetras bolsa_aux;
    ArbolGeneral<Letra>::Nodo nodo_aux = datos.hijomasizquierda(nodo),nodo_aux2;

    while(nodo_aux != NULL){
        if(bolsa.pertenecerandom(datos.etiqueta(nodo_aux).Getletra())){
            bolsa_aux = bolsa;
            bolsa_aux.elimina_letra(datos.etiqueta(nodo_aux).Getletra());
            palabras_aux = encuentra_palabras(bolsa_aux,nodo_aux);
            palabras.insert(palabras.end(),palabras_aux.begin(),palabras_aux.end());
            if(datos.etiqueta(nodo_aux).Esfinal()){
                nodo_aux2 = nodo_aux;
                palabra_aux.clear();
                while(nodo_aux2 != datos.raiz()){
                    palabra_aux.insert(0,1,datos.etiqueta(nodo_aux2).Getletra());
                    nodo_aux2 = datos.padre(nodo_aux2);
                }
                palabras.push_back(palabra_aux);
            }
        }
        nodo_aux = datos.hermanoderecha(nodo_aux);
    }
    return palabras;
}

istream & operator>>(istream & is, Diccionario &D) {
    ArbolGeneral<Letra>::Nodo inicio = D.datos.raiz(), aux;
    string cadena;

    while (!is.eof()) {
        getline(is, cadena);
        D.aniade_palabra(cadena);

    }

    return is;
}

ostream & operator<<(ostream & os, Diccionario &D) {

    Diccionario::iterator iterador;

    for (iterador = D.begin(); iterador != D.end(); ++iterador) {
        os << *iterador << endl;
    }

    return os;
}

Diccionario::iterator & Diccionario::iterator::operator++() {
    int level = it.getlevel();
    do {
        ++(it);
        if (it.getlevel() > 0) {
            if (it.getlevel() <= level) {
                cad = cad.substr(0, it.getlevel() - 1);
                cad.push_back((*it).Getletra());
            } else {
                cad.push_back((*it).Getletra());
            }
            level = it.getlevel();
        } else {
            break;
            break;
        }
    } while (!(*it).Esfinal());
    return *this;
}
