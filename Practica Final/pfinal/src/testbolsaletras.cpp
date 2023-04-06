/**

  * @file ConjuntoLetras.cpp

  * @author Carlos Garcia Segura, Jose Maria Poblador Marquez

  */

#include<iostream>
#include<fstream>
#include<cstdlib>
#include"BolsaLetras.h"

using namespace std;

int main (int argc, char *argv[])
{
srand(time(NULL));
ifstream conj_in(argv[1]);
if (!conj_in.is_open()) {
  cout << "el archivo no esta abierto";
  return 0;
}
ConjuntoLetras conj;
conj_in >> conj;
BolsaLetras bolsa(conj);
deque<char> letrasrandom;
letrasrandom = bolsa.GetRandomletras(9);

cout << "Letras aleatorias: " << endl;
deque<char>::iterator it;
for(deque<char>::iterator it=letrasrandom.begin(); it!=letrasrandom.end(); it++){
  cout << *it << endl;
}



}
