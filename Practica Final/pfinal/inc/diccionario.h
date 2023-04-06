/**

  * @file diccionario.h

  * @author Carlos Garcia Segura, Jose Maria Poblador Marquez

  */


#ifndef __Diccionario_h__
#define __Diccionario_h__

#include <vector>
#include <string>
#include "ArbolGeneral.h"
#include "BolsaLetras.h"
#include "Letra.h"

using namespace std;
/**

   @brief Clase Diccionario
   \b Definición:
   La clase diccionario contiene un arbol general en el que se guardan las letras formando palabras

*/
class Diccionario {
private:
  /**
      * @brief Campo en el que se guardan las letras para formar palabras
      */
    ArbolGeneral<Letra> datos;
    /**
        * @brief Obtiene todas las palabras vque se puedan formar con las letras de bolsa
        * @param bolsa: Bolsa de letras para la obtencion de palabras con las letras aleatorias escogidas en la bolsa
        * @param nodo: Nodo a partir del cual se inicia la busqueda
        * @return Un vector de string con las palabras escogidas
        */
    vector<string> encuentra_palabras(BolsaLetras bolsa, ArbolGeneral<Letra>::Nodo nodo);

public:
  /**
      * @brief Constructor sin argumentos
      */
    Diccionario() {
        datos = ArbolGeneral<Letra>(Letra('\0', false));
    };
    /**
        * @brief Tamaño del arbol
        */
    int size() const;
    /**
        * @brief Añade una palabra al arbol en orden
        * @param palabra: palabra que se quiere añadir
        */
    void aniade_palabra(string palabra);
    /**
        * @brief Obtiene todas las palabras en el diccionario de un longitud dada
        * @param longitud: la longitud de las palabras de salida
        * @return un vector con las palabras de longitud especifica en el parametro de entrada
        */
    vector<string> PalabrasLongitud(int longitud);
    /**
        * @brief Comprueba si una palabra esta en el diccionario o no
        * @param palabra: La palabra a comprobar
        * @return true si esta en el diccionario, false si no esta
        */
    bool Esta(string palabra);
    vector<int> numero_apariciones();
    int total_letras();
    /**
        * @brief Obtiene todas las palabras vque se puedan formar con las letras de bolsa
        * @param bolsa: Bolsa de letras para la obtencion de palabras con las letras aleatorias escogidas en la bolsa
        * @return Un vector de string con las palabras escogidas
        */
    vector<string> encuentra_palabras(BolsaLetras bolsa){return encuentra_palabras(bolsa,datos.raiz());}
    /**
     * @brief Lee de un flujo de entrada un diccionario
     * @param is: Flujo de entrada
     * @param D: El objeto donde se realiza la lectura.
     * @return El flujo de entrada
     */

    friend istream & operator>>(istream & is, Diccionario &D);
    /**
    * @brief Escribe en un flujo de salida un diccionario
    * @param os:flujo de salida
    * @param D: el objeto diccionario que se escribe
    * @return el flujo de salida
    */

    friend ostream & operator<<(ostream & os, Diccionario &D);
      /**
        * @brief Iterador del diccionario
        */
    class iterator {
    private:
        ArbolGeneral<Letra>::iter_preorden it;
        /**
         * @brief Mantiene los caracteres desde donde empieza hasta donde esta
         */
        string cad;

    public:

          /*
          * @brief Constructor por defecto
          */
        iterator() {
        }
        /*
          * @brief Devuelve el contenido de cad
          * @return Devuelve la cadena de caracteres desde el nivel 1 hasta donde se encuentra it
          */
        string operator*() const {
            return cad;
        }
        /**
         * @brief Devuelve un iterador a la siguiente palabra del diccionario
         */
        iterator & operator++();
        /**
          * @brief Compara dos iteradores
          * @param i: iterador con el  que se compara
          * @return true si los dos iteradores son iguales
          */
        bool operator==(const iterator &i) const {
            return (it == i.it);
        }
        /**
          * @brief Compara dos iteradores
          * @param i: iterador con el  que se compara
          * @return true si los dos iteradores no son iguales
          */
        bool operator!=(const iterator &i)const {
            return (it != i.it);
        }
        /**
       * @brief Obtiene la longitud de la cadena de caracteres recorrida
       * @param devuelve el nivel en el que se encuentra el iterador
       */
        int getlongitud()const {
            return it.getlevel();
        }

        friend class Diccionario;
    };
    /**
        * @brief Inicia el iterador al principio
        */
    iterator begin() {
        iterator it;
        it.it = datos.begin();
        it.cad.clear();
        return it;
    }
    /**
        * @brief inicializa el iterador al final
        */
    iterator end() {
        iterator it;
        it.it = datos.end();
        return it;
    }


};

#endif
