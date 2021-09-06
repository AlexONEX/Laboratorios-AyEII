#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Conjunto
{
    public:
        Conjunto();
        ~Conjunto();
        void insertar(const T& clave);
        bool pertenece(const T& clave) const;
        void remover(const T& clave);
        const T& siguiente(const T& clave);
        const T& anterior(const T& clave);
        const T& minimo() const;
        const T& maximo() const;
        unsigned int cardinal() const;
        void mostrar(std::ostream&) const;

    private:
        struct Nodo
        {
            Nodo(const T& v);
            void destructor(Nodo* arbol);  //
            unsigned int branches() const;
            T valor;
            Nodo* izq;
            Nodo* der;
        };
        Nodo* _raiz;
};

template<class T>
Conjunto<T>::Nodo::Nodo(const T &v) {
    valor = v;
    izq = nullptr;
    der = nullptr;
}

template<class T>
unsigned int Conjunto<T>::Nodo::branches() const {
    if(this == nullptr){
        return 0;
    }
    else{
        return 1 + this->der->branches() + this->izq->branches();
    }
}

template<class T>
void Conjunto<T>::Nodo::destructor(Nodo* arbol) {
    if(arbol != nullptr){
        destructor(arbol->der);
        destructor(arbol->izq);
        delete arbol;
    }
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Conjunto<T>& c) {
	 c.mostrar(os);
	 return os;
}

#include "Conjunto.hpp"

#endif // CONJUNTO_H_
