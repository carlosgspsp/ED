/**

  * @file BolsaLetras.h

  * @author Carlos Garcia Segura, Jose Maria Poblador Marquez

  */


#ifndef _BolsaLetras_h_
#define _BolsaLetras_h_

#include <iostream>
#include <string>
#include <deque>
#include "ConjuntoLetras.h"

using namespace std;
/**

   @brief TDA BolsaLetras
   \b Definición:
   BolsaLetras guarda todos los caracteres que se pueden usar y obtiene las
   letras disponibles en el juego de forma aleatoria

*/
class BolsaLetras {
private:
  /**
      * @brief Deque de char que guarda todos los caracteres disponibles
      */
    deque<char> letras;
    /**
      * @brief Funcion para obtener el deque letras
      * @return un deque de char
      */
    deque<char> Getdeque();
    /**
      * @brief Deque de char que almacena los caracteres obtenidos aleatoriamente
      */
    deque<char> dequerandom;
public:
  /**
        * @brief Constructor sin argumentos de BolsaLetras
        */
    BolsaLetras() {}
    /**
      * @brief Constructor con argumentos de BolsaLetras
      * @param c: ConjuntoLetras a parir del cual se quieren extraer todos los caracteres
      */
    BolsaLetras(ConjuntoLetras c);
    /**
      * @brief Elimina un caracter de dequerandom
      * @param letra: el caracter que se quiere eliminar
      */
    void elimina_letra(char letra);
    /**
      * @brief Obtiene un numero n de letras aleatorias disponibles en el campo letras
      * @param n: numero de letras que se quiere obtener
      * @return un deque de char con las letras obtenidas aleatoriamente
      */
    deque<char> GetRandomletras(int n);
    /**
      * @brief Operador de asignacion de BolsaLetras
      * @param otra_bolsa: Bolsa de la que se quieren obtener los datos
      */
    BolsaLetras operator=(BolsaLetras & otra_bolsa);
    /**
      * @brief Comprueba si un caracter se encuentra en letras
      * @param letra: char del caracter que se quiere buscar
      * @return true si esta, false si no esta
      */
    bool pertenece(char letra);
    /**
      * @brief Comprueba si un caracter se encuentra en dequerandom
      * @param letra: char del caracter que se quiere buscar
      * @return true si esta, false si no esta
      */
    bool pertenecerandom(char letra);
    /**
      * @brief Devuelve una copia de dequerandom
      */
    deque<char> Getdequerandom();
};


#endif
