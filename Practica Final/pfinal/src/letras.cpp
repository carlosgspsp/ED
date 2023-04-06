/**

  * @file ConjuntoLetras.cpp

  * @author Carlos Garcia Segura, Jose Maria Poblador Marquez

  */

#include<iostream>
#include<fstream>
#include"diccionario.h"
#include"BolsaLetras.h"
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

vector<string>::iterator encuentra(vector<string>::iterator begin, vector<string>::iterator end, string solucion) {
    bool esta;
    for (vector<string>::iterator it = begin; it != end; it++) {
        esta = true;
        for (int i = 0; i < (*it).size() && (*it).size() == solucion.size() && esta; i++) {
            if ((*it)[i] != solucion[i]) {
                esta = false;
            }
        }
        if (esta && (*it).size() == solucion.size()) {
            return it;
        }
    }
    return end;
}

int main(int argc, char * argv[]) {

    if (argc != 5) {
        cout << "Sintaxis: ./letras <diccionario> <letras>";
        cout << " <numero de letras aleatorias> <L|P>" << endl;
        return 0;
    }

    ConjuntoLetras conj;
    Diccionario dic;
    vector<string> soluciones;
    srand(time(NULL));

    ifstream dic_in(argv[1]), conj_in(argv[2]);
    dic_in >> dic;
    conj_in >> conj;
    BolsaLetras bolsa(conj);

    char modo = argv[4][0];
    bool continuar = true;
    while (continuar) {
        switch (modo) {
            case 'L':
            {
                cout << "Modo de juego: Longitud" << endl;
                cout << "Letras: " << endl;
                bolsa.GetRandomletras(atoi(argv[3]));
                for (int i=0; i<bolsa.Getdequerandom().size(); i++)
                    cout << bolsa.Getdequerandom()[i] << "\t";

                cout << endl << "Introduce tu solucion: ";
                string solucion;
                cin >> solucion;
                soluciones = dic.encuentra_palabras(bolsa);

                if (encuentra(soluciones.begin(), soluciones.end(), solucion) == soluciones.end()) {
                    cout << "\nLo siento, no es una solución valida" << endl;
                } else
                    cout << endl << solucion << "\tLongitud:" << solucion.size() << endl;



                for (vector<string>::iterator it = soluciones.begin(); it != soluciones.end(); it++) {
                    cout << *it << "\tLongitud:" << (*it).size() << endl;
                }
                solucion = soluciones[0];
                for (int i = 0; i < soluciones.size(); i++) {
                    if (soluciones[i].size() > solucion.size()) {
                        solucion = soluciones[i];
                    }
                }
                cout << "Mejor solucion: " << solucion << endl;

                break;
            }

            case 'P':
            {
                cout << "Modo de juego: Puntuacion" << endl;
                cout << "Puntuaciones: " << conj << endl;
                cout << "Letras: " << endl;
                bolsa.GetRandomletras(atoi(argv[3]));
                for (int i=0; i<bolsa.Getdequerandom().size(); i++)
                    cout << bolsa.Getdequerandom()[i] << "\t";

                cout << endl << "Introduce tu solucion: ";
                string solucion;
                cin >> solucion;
                soluciones = dic.encuentra_palabras(bolsa);

                if (encuentra(soluciones.begin(), soluciones.end(), solucion) == soluciones.end()) {
                    cout << "\nLo siento, no es una solución valida" << endl;
                } else
                    cout << endl << solucion << "\tPuntuacion:" << conj.Getpuntuacion(solucion) << endl;



                for (vector<string>::iterator it = soluciones.begin(); it != soluciones.end(); it++) {
                    cout << *it << "\tPuntuacion:" << conj.Getpuntuacion(*it) << endl;
                }
                solucion = soluciones[0];
                for (int i = 0; i < soluciones.size(); i++) {
                    if (conj.Getpuntuacion(soluciones[i]) > conj.Getpuntuacion(solucion)) {
                        solucion = soluciones[i];
                    }
                }
                cout << "Mejor solucion: " << solucion << endl;
                break;
            }
        }

        cout << "¿Quieres seguir jugando? [S|N]";
        char seguir;
        cin >> seguir;

        if (seguir == 's' || seguir == 'S') {
            continuar = true;
            cout << "¿Quieres cambiar de modo? [S|N]";
            char cambiar;
            cin >> cambiar;
            if (cambiar == 's' || cambiar == 'S') {
                cout << "¿Que modo quieres Jugar? ['L'(Longitud)|'P'(Puntuacion)]";
                char modo2;
                cin >> modo2;
                if (modo2 == 'l' || modo2 == 'L') {
                    modo = 'L';
                } else if (modo2 == 'p' || modo2 == 'P') {
                    modo = 'P';
                } else cout << "La respuesta introducida no es valida [L|N]";
            } else if (cambiar != 'n' || cambiar != 'N') {
                cout << "La respuesta introducida no es valida [S|N]";
            }
        } else if (seguir == 'n' || seguir == 'N') {
            continuar = false;
        } else cout << "La respuesta introducida no es valida [S|N]";
    }
}

