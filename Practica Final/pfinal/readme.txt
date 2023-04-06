Práctica Final: Letras
Carlos García Segura, José Mª Poblador Márquez

DESCRIPCIÓN DEL PROGRAMA
El programa es una implementación de dos juegos de anagramas, uno estilo "Cifras y Letras" y otro estilo "Scrabble", de principio similar. Generado un número de letras aleatorias, el juego consiste en dar una palabra con esas letras (más larga en modalidad Longitud y de mayor puntuación en modalidad Puntuación). El programa dará entonces las soluciones posibles y escogerá de entre ellas la mejor. Al terminar, se puede jugar de nuevo o cambiar de modo.

ESTRUCTURA DEL PROGRAMA
Para el funcionamiento del programa se utilizan 5 módulos.

"ArbolGeneral": implementación del TDA Árbol General, en el cual se basa el diccionario.

"Diccionario": basado en el Árbol General, guarda palabras a partir de nodos colgando de la raíz que almacenan Letras. Las palabras se construyen a partir de recorrer la estructura mediante estructuras afines auxiliares (Nodos). Su funcionalidad se prueba con testdiccionario.

"Letra"/"ConjuntoLetras": una Letra es una estructura de datos que guarda atributos referidos a una letra: el carácter que la representa, el número de veces que aparece repetida, su puntuación (al estilo del "Scrabble") y un marcador de final de palabra (para los recorridos en el Diccionario) Varias Letras forman un Conjunto de Letras, optándose para su representación una cola doble (deque) de Letras.

"BolsaLetras": La Bolsa de Letras es la representación de las Letras mezcladas como una bolsa con fichas de letras, y también implementa el mecanismo de obtención aleatoria de letras. Un deque almacena todas las letras con sus repeticiones y de ahí se obtiene un segundo deque que almacena las letras obtenidas aleatoriamente. Su funcionalidad, así como la de los módulos de letras, se prueba con testbolsaletras.

FUNCIONAMIENTO
Al ejecutar el programa, se crean a partir de archivos el Diccionario, el Conjunto de Letras y la Bolsa de Letras a partir de este último. Las soluciones que encuentre el programa se guardan en un vector de strings.

Al inicio de cada modo, se obtiene el deque de letras aleatorias. El número de letras se define al llamar al programa. Se muestra el conjunto y se introduce una solución. Una vez hecho, se llama al algoritmo que obtiene las palabras del diccionario a partir de las letras del conjunto aleatorio, que se almacenan en el vector.

Para comprobar si la solución introducida es válida, se comprueba si existe en el vector soluciones. Se muestra su contenido y se escoge la mejor opción (más larga o más puntuación), mediante comparación de tamaños o puntuaciones de letras entre las componentes del vector y la solución dada.

Al terminar, se pregunta si se desea continuar jugando, y en caso afirmativo, si se desea cambiar de modo. Esta función se implementa con bucles y sentencias de tipo switch.

