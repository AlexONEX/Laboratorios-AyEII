#include "Conjunto.h"

template <class T>
Conjunto<T>::Conjunto() {
    _raiz = nullptr;
}

template <class T>
Conjunto<T>::~Conjunto() {
    this->_raiz->destructor(this->_raiz);
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    if(_raiz == nullptr){
        return false;
    }
    else if(clave == _raiz->valor){
        return true;
    }
    else {
        Nodo* iterador = _raiz;
        while(iterador != nullptr){
            if(iterador->valor == clave){
                return true;
            }
            else if(iterador->valor < clave){
                iterador = iterador->der;
            }
            else{
                iterador = iterador->izq;
            }
        }
    }
    return false;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if(pertenece(clave) == false){
        if(this->_raiz == nullptr){
            this->_raiz = new Nodo(clave);
        }
        else{
            Nodo* iterador = this->_raiz;
            while(true){
                if(iterador->valor < clave && iterador->der == nullptr){
                    iterador->der = new Nodo(clave);
                    break;
                }
                else if(iterador->valor < clave && iterador->der != nullptr){
                    iterador = iterador->der;
                }
                else if(iterador->valor > clave && iterador->izq == nullptr){
                    iterador->izq = new Nodo(clave);
                    break;
                }
                else if(iterador->valor > clave && iterador->izq != nullptr){
                    iterador = iterador->izq;
                }
            }
        }
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    if(this->pertenece(clave)) {
        if (clave == _raiz->valor){
            if (_raiz->izq == nullptr && _raiz->der == nullptr){
                delete _raiz;
                _raiz = nullptr;
            }
            else if (_raiz->der == nullptr || _raiz->izq == nullptr){
                if (_raiz->der){
                    Nodo* aux = _raiz->der;
                    delete _raiz;
                    _raiz = aux;
                }
                else {
                    Nodo* aux = _raiz->izq;
                    delete _raiz;
                    _raiz = aux;
                }
            }
            else{
                T sig = siguiente(clave);
                remover(sig);
                _raiz->valor = sig;
            }
        }
        else{
            Nodo *sucesor = _raiz;
            Nodo *iterador = nullptr;
            while(true) {
                if (sucesor->der && clave == sucesor->der->valor) {
                    iterador = sucesor->der;
                    break;
                }
                else if(sucesor->izq && clave == sucesor->izq->valor) {
                    iterador = sucesor->izq;
                    break;
                }
                else {
                    if(clave < sucesor->valor) {
                        sucesor = sucesor->izq;
                    }
                    else{
                        sucesor = sucesor->der;
                    }
                }
            }
            if(iterador->der == nullptr && iterador->izq == nullptr){ // Caso Hoja
                if(iterador == sucesor->der){ //Antes de eliminarlo lo pongo en null.
                    sucesor->der = nullptr;
                }
                else{
                    sucesor->izq = nullptr;
                }
                delete iterador;
            }
            else if(iterador->der == nullptr || iterador->izq == nullptr){ //Caso 1 Hijo
                if(iterador == sucesor->der){  //Caso Hijo en Derecha
                    if(iterador->der){
                        sucesor->der = iterador->der;
                    }
                    else{
                        sucesor->der = iterador->izq;
                    }
                }
                else{       //Caso Hijo en Izquierda
                    if(iterador->der){
                        sucesor->izq = iterador->der;
                    }
                    else{
                        sucesor->izq = iterador->izq;
                    }
                }
                delete iterador;
            }
            else {  //caso 2 hijos
                T sig = siguiente(clave);
                remover(sig);
                iterador->valor= sig;
            }
        }
    }
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    EXPECT_TRUE(this->pertenece(clave));
    Nodo* iterador = this->_raiz;
    Nodo* sucesor = nullptr;
    while(iterador != nullptr){
        if(clave < iterador->valor){
            sucesor = iterador;
            iterador= iterador->izq;
        }
        else{
            iterador = iterador->der;
        }
    }
    return sucesor->valor;
}

template <class T>
const T& Conjunto<T>::minimo() const {
    EXPECT_TRUE(this->_raiz->branches()>0);
    Nodo* iterador = this->_raiz;
    while(iterador->izq != nullptr){
        iterador = iterador->izq;
    }
    return iterador->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    EXPECT_TRUE(this->_raiz->branches()>0);
    Nodo* iterador = this->_raiz;
    while(true){
        if(iterador->der == nullptr){
            return iterador->valor;
        }
        else{
            iterador = iterador->der;
        }
    }
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return this->_raiz->branches();
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}
