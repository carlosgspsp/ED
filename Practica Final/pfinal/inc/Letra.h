/**

  * @file Letra.h

  * @author Carlos Garcia Segura, Jose Maria Poblador Marquez

  */

#ifndef _Letra_h_
#define _Letra_h_

#include<iostream>
#include<string>
using namespace std;

/**

   @brief TDA Letra
   \b Definición:
   La clase letra guarda la informacion sobre cada letra

*/
class Letra {
private:
  /**
     * @brief letra
     * En este campo se almacena el caracter de la letra
     */
    char letra;
    /**
     * @brief final
     * En este campo se almacena si la letra es el final de una palabra o no
     */
    bool final;
    /**
         * @brief repeticiones
         * En este campo se almacena el numero de veces que puede aparecer la letra
         */
    int repeticiones;
    /**
     * @brief puntuacion
     * En este campo se almacena la puntuaicon de la letra
     */
    int puntuacion;

public:
  /**
      * @brief Constructor sin argumentos de Letra
      */
    Letra();
    /**
      * @brief constructor con argumentos de Letra
      * @param l: caracter de la letra
      * @param f: true o false dependiendo de si la letra es final o no
      */
    Letra(char l, bool f);
    /**
      * @brief constructor con argumentos de Letra
      * @param l: caracter de la letra
      * @param r: numero de repeticiones de la letra
      * @param p: puntuacion de la letra
      */
    Letra(char l, int r, int p);
    /**
      * @brief Obtiene el caracter de la letra
      * @return un char con el caracter de la letra
      */
    char Getletra();
    /**
      * @brief Obtiene el numero de repeticiones maximo de la letra
      * @return un int con el numero maximo de repeticiones de la letra
      */
    int Getrepeticiones();
    /**
      * @brief Obtiene la puntuacion asignada a la letra
      * @return un int con la puntuacion asignada a la letra
      */
    int Getpuntuacion();
    /**
      * @brief Comprueba si la letra es el final de una palabra
      * @return true si es el final de una palabra, false si no lo es
      */
    bool Esfinal();
    /**
      * @brief Cambia la variable final a true o false
      * @param f: Un bool
      */
    void Setfinal(bool f);
    /**
      * @brief Operador de comparacion de Letra
      * @param l: la letra que se quiere comparar
      * @return true si son iguales
      */
    bool operator==(Letra l);
};


#endif
