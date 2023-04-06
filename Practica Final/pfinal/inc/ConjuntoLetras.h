/**

  * @file ConjuntoLetras.h

  * @author Carlos Garcia Segura, Jose Maria Poblador Marquez

  */

#include<iostream>
#include<string>
#include"Letra.h"
#include<deque>

using namespace std;
/**

   @brief TDA ConjuntoLetras.h
   \b Definición:
   La clase conjunto letras guarda un conjunto de Letras

*/
class ConjuntoLetras {
private:
  /**
      * @brief Deque de Letra en el que se guarda la informacion sobre las letras
      */
    deque<Letra> conjunto;
    /**
      * @brief añade una Letra al final de conjunto
      * @param l: Lam Letra que se quiere añadir
      */
    void push_back(Letra l);
    /**
      * @brief Obtiene la puntuacion de un caracter
      * @param l: char del que se quiere obtener la puntuacion
      * @return la puntuacion en un int
      */
    int Getpuntuacion(char l);

public:
    deque<Letra> Getletras();
    /**
      * @brief Obtiene la puntuacion de una palabra
      * @param palabra: string del cual se quiere saber la puntuacion total
      * @return in int con la puntuacion total
      */
    int Getpuntuacion(string palabra);
    /**
    * @brief Lee de un flujo de entrada un diccionario
    * @param is:Flujo de entrada
    * @param D: El objeto donde se realiza la lectura.
    * @return El flujo de entrada
    */
    friend istream& operator>>(istream & is, ConjuntoLetras &C);
    /**
    * @brief Escribe en un flujo de salida un diccionario
    * @param os:flujo de salida
    * @param D: el objeto diccionario que se escribe
    * @return el flujo de salida
    */
    friend ostream& operator<<(ostream & os, ConjuntoLetras &C);

};
