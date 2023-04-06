#ifndef __ArbolGeneral_h__
#define __ArbolGeneral_h__

#include <cassert>
#include <iostream>
using namespace std;

template <class Tbase>
class ArbolGeneral {
private:

    struct nodo {
        Tbase etiqueta;
        nodo *izquierda;
        nodo *derecha;
        nodo *padre;
    };

    struct nodo *laraiz;
    void destruir(nodo * n);
    void copiar(nodo *& dest, nodo * orig);
    int contar(const nodo * n) const;
    bool soniguales(const nodo * n1, const nodo * n2) const;
    void escribe_arbol(std::ostream& out, nodo * nod) const;
    void lee_arbol(std::istream& in, nodo *& nod);

public:
    typedef struct nodo * Nodo;

    ArbolGeneral() {
        this->laraiz = NULL;
    }

    ArbolGeneral(const Tbase& e) {
        this->laraiz = new nodo;
        this->laraiz->etiqueta = e;
        this->laraiz->padre = NULL;
        this->laraiz->derecha = NULL;
        this->laraiz->izquierda = NULL;
    }

    ArbolGeneral(const ArbolGeneral<Tbase>& v);
    ~ArbolGeneral();
    ArbolGeneral<Tbase>& operator=(const ArbolGeneral<Tbase> &v);

    void AsignaRaiz(const Tbase& e);

    Nodo raiz() const {
        return this->laraiz;
    };

    Nodo hijomasizquierda(const Nodo n) const {
        return n->izquierda;
    };

    Nodo hermanoderecha(const Nodo n) const {
        return n->derecha;
    };

    Nodo padre(const Nodo n) const {
        return n->padre;
    }

    Tbase& etiqueta(const Nodo n) {
        return n->etiqueta;
    }

    const Tbase& etiqueta(const Nodo n) const {
        return n->etiqueta;
    }
    void asignar_subarbol(const ArbolGeneral<Tbase>& orig, const Nodo nod);
    void podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest);
    void podar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& dest);
    void insertar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& rama);
    void insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama);

    void clear() {
        destruir(this->laraiz);
        delete this->laraiz;
    }

    int size() const {
        return contar(this->laraiz);
    }

    bool empty() const {
        return laraiz == 0;
    }
    bool operator==(const ArbolGeneral<Tbase>& v) const;

    bool operator!=(const ArbolGeneral<Tbase>& v) const {
        return !(*this == v);
    };

    template<class T>
    friend std::istream& operator>>(std::istream& in, ArbolGeneral<T>& v);

    template<class T>
    friend std::ostream& operator<<(std::ostream& out, const ArbolGeneral<T>& v);

    class const_iter_preorden;

    class iter_preorden {
    private:
        Nodo it;
        Nodo raiz;
        int level;

    public:

        iter_preorden() {
            it = NULL;
            raiz = NULL;
            level = 0;
        }

        Tbase & operator*() {
            return it->etiqueta;
        }

        int getlevel()const {
            return level;
        }

        iter_preorden & operator++();

        bool operator==(const iter_preorden &i)const {
            return (this->it == i.it) && (this->raiz == i.raiz);
        }

        bool operator==(const ArbolGeneral<Tbase>::const_iter_preorden &i)const {
            return (this->it == i.it) && (this->raiz == i.raiz);
        }

        bool operator!=(const iter_preorden &i)const {
            return !(*this == i);
        }

        bool operator!=(const ArbolGeneral<Tbase>::const_iter_preorden &i)const {
            return !(*this == i);
        }


        friend class ArbolGeneral;
    };

    class const_iter_preorden {
    private:
        const nodo * it;
        const nodo * raiz;
        int level;

    public:

        const_iter_preorden() {
            it = NULL;
            raiz = NULL;
            level = 0;
        }

        const Tbase & operator*()const {
            return it->etiqueta;
        }

        int getlevel()const {
            return this->level;
        }

        const_iter_preorden & operator++();

        bool operator==(const const_iter_preorden &i)const {
            return (this->it == i.it) && (this->raiz == i.raiz);
        }

        bool operator==(const ArbolGeneral<Tbase>::iter_preorden &i)const {
            return (this->it == i.it) && (this->raiz == i.raiz);
        }

        const_iter_preorden operator=(const const_iter_preorden &i) {
            it = i.it;
            raiz = i.raiz;
            level = i.level;
            return *this;
        }

        const_iter_preorden operator=(const ArbolGeneral<Tbase>::iter_preorden &i) {
            it = i.it;
            raiz = i.raiz;
            level = i.level;
            return *this;
        }

        bool operator!=(const iter_preorden &i)const {
            return !(*this == i);
        }

        bool operator!=(const const_iter_preorden &i)const {
            return !(*this == i);
        }


        friend class ArbolGeneral;
    };

    iter_preorden begin() {
        iter_preorden it;
        it.it = it.raiz = this->laraiz;
        it.level = 0;
        return it;
    }

    const_iter_preorden begin()const {
        const_iter_preorden it;
        it.it = it.raiz = this->laraiz;
        it.level = 0;
        return it;
    }

    iter_preorden end() {
        iter_preorden it;
        it.raiz = this->laraiz;
        it.it = NULL;
        it.level = 0;
        return it;
    }

    const_iter_preorden end()const {
        const_iter_preorden it;
        it.raiz = this->laraiz;
        it.it = NULL;
        it.level = 0;
        return it;
    }

};

template <class Tbase>
void ArbolGeneral<Tbase>::destruir(Nodo n) {
    if (n != NULL) {

        Nodo aux;
        while (n->izquierda != NULL) {
            aux = n->izquierda;
            n->izquierda = n->izquierda->derecha;
            destruir(aux);
        }
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::copiar(Nodo &dest, Nodo orig) {
    Nodo aux1 = orig->izquierda;
    if (aux1 != NULL) {
        Nodo aux2 = dest->izquierda = new typename ArbolGeneral<Tbase>::nodo;


        do {
            aux2->etiqueta = aux1->etiqueta;
            aux2->padre = dest;
            copiar(aux2, aux1);
            aux1 = aux1->derecha;
            if (aux1 != NULL) {
                aux2 = aux2->derecha = new typename ArbolGeneral<Tbase>::nodo;

            }

        } while (aux1 != NULL);

        aux2->derecha = NULL;
    } else {
        dest->izquierda = NULL;
    }
}

template <class Tbase>
int ArbolGeneral<Tbase>::contar(const ArbolGeneral<Tbase>::nodo * n) const {
    int suma = 1;
    Nodo aux = n->izquierda;
    while (aux != NULL) {
        suma += contar(aux);
        aux = aux->derecha;
    }
    return suma;
}

template <class Tbase>
bool ArbolGeneral<Tbase>::soniguales(const ArbolGeneral<Tbase>::nodo * n1, const ArbolGeneral<Tbase>::nodo * n2) const {
    if (n1->etiqueta != n2->etiqueta) {
        return false;
    } else {
        bool iguales = true;
        Nodo aux1 = n1->izquierda, aux2 = n2->izquierda;
        while (iguales && aux1 != NULL && aux2 != NULL) {
            iguales = this->soniguales(aux1, aux2);
            aux1 = aux1->derecha;
            aux2 = aux2->derecha;

        }
        return iguales && (aux1 == aux2);
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::escribe_arbol(std::ostream& out, Nodo nod) const {
    out << 'n' << nod->etiqueta;
    Nodo aux = nod->izquierda;
    while (aux != NULL) {
        escribe_arbol(out, aux);
        aux = aux->derecha;
    }
    out << 'x';

}

template <class Tbase>
void ArbolGeneral<Tbase>::lee_arbol(std::istream& in, Nodo& nod) {
    Tbase aux;
    char marca;
    in >> aux;
    nod->etiqueta = aux;
    in >> marca;
    Nodo nodoaux;
    if (marca == 'n') {
        nodoaux = nod->izquierda = new typename ArbolGeneral<Tbase>::nodo;
    }
    while (marca == 'n') {
        lee_arbol(in, nodoaux);
        nodoaux->padre = nod;
        in >> marca;
        nodoaux->derecha = NULL;
        if (marca != 'x') {
            nodoaux = nodoaux->derecha = new typename ArbolGeneral<Tbase>::nodo;
        }
    }
}

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const ArbolGeneral<Tbase>& v) {
    this->laraiz = new ArbolGeneral<Tbase>::nodo;
    this->laraiz->padre = NULL;
    this->laraiz->derecha = NULL;
    this->laraiz->etiqueta = (v.raiz())->etiqueta;
    copiar(this->laraiz, v.raiz());
}

template<class Tbase>
ArbolGeneral<Tbase>::~ArbolGeneral() {
    this->clear();
}

template <class Tbase>
ArbolGeneral<Tbase>& ArbolGeneral<Tbase>::operator=(const ArbolGeneral<Tbase> &v) {
    if (this->laraiz != NULL) {
        destruir(this->laraiz);
    } else {

        this->laraiz = new typename ArbolGeneral<Tbase>::nodo;

    }
    this->laraiz->padre = this->laraiz->derecha = NULL;
    this->laraiz->etiqueta = (v.raiz())->etiqueta;
    copiar(this->laraiz, v.raiz());
    return *this;
}

template <class Tbase>
void ArbolGeneral<Tbase>::asignar_subarbol(const ArbolGeneral<Tbase>& orig, Nodo nod) {
    destruir(nod);
    copiar(nod, orig.raiz());
}

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest) {
    dest.clear();
    dest.laraiz = n->izquierda;
    if (dest.laraiz != NULL) {
        n->izquierda = n->izquierda->derecha;
        dest.laraiz->derecha = NULL;
        dest.laraiz->padre = NULL;
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& dest) {
    dest.clear();
    if (n != NULL) {
        if (n->derecha != NULL) {
            dest.laraiz = n->derecha;
            n->derecha = n->derecha->derecha;
            dest.laraiz->derecha = NULL;
            dest.laraiz->padre = NULL;
        }
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& rama) {
    if (n != NULL) {
        Nodo aux = n->izquierda;
        n->izquierda = rama.laraiz;
        n->izquierda->padre = n;
        n->izquierda->derecha = aux;
        rama.laraiz = NULL;
    }
}

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama) {
    if (n != NULL) {
        Nodo aux = n->derecha;

        n->derecha = rama.laraiz;
        n->derecha->padre = n->padre;
        n->derecha->derecha = aux;
        rama.laraiz = NULL;
    }
}

template<class Tbase>
bool ArbolGeneral<Tbase>::operator==(const ArbolGeneral<Tbase>& v) const {
    if (this->laraiz == NULL) {
        if (v.raiz() == NULL) {
            return true;
        } else {
            return false;
        }
    } else {
        return soniguales(this->laraiz, v.raiz());
    }
}

template<class T>
std::istream& operator>>(std::istream& in, ArbolGeneral<T>& v) {
    char marca;
    in >> marca;
    if (marca == 'n') {
        v.clear();
        v.laraiz = new typename ArbolGeneral<T>::nodo;
        v.lee_arbol(in, v.laraiz);
    }
    return in;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const ArbolGeneral<T>& v) {
    if (v.laraiz != NULL) {
        v.escribe_arbol(out, v.laraiz);
    } else {
        out << 'x';
    }
    return out;
}

template<class Tbase>
typename ArbolGeneral<Tbase>::iter_preorden & ArbolGeneral<Tbase>::iter_preorden::operator++() {
    if (it == NULL) {
        return *this;
    }
    if (it->izquierda != NULL) {
        it = it->izquierda;
        level++;
    } else if (it->derecha != NULL) {
        it = it->derecha;
    } else {
        while (it->derecha == NULL && it->padre != NULL) {
            it = it->padre;
            level--;
        }
        it = it->derecha;
    }

    return *this;
}

template<class Tbase>
typename ArbolGeneral<Tbase>::const_iter_preorden & ArbolGeneral<Tbase>::const_iter_preorden::operator++() {
    if (it == NULL) {
        return *this;
    }
    if (it->izquierda != NULL) {
        it = it->izquierda;
        level++;
    } else if (it->derecha != NULL) {
        it = it->derecha;
    } else {
        while (it->padre != NULL && it->derecha == NULL) {
            it = it->padre;
            level--;
        }
        it = it->derecha;

    }
    return *this;
}


#endif
