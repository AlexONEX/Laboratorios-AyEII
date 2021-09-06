
#include "string_map.h"

template <typename T>
string_map<T>::string_map() : _raiz(nullptr), _size(0){}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    desctructor(this->_raiz);
    this->_size = d._size;
    this->_raiz = copiarNodo(d._raiz);
}

template<typename T>
typename string_map<T>:: Nodo* string_map<T>::copiarNodo (Nodo* n) {
    if(n == nullptr)
        return nullptr;
    else{
        Nodo* res = new Nodo();
        if(n->definicion != nullptr){
            res->definicion = new T(*n->definicion);
        }
        for(int i = 0; i< (n->siguientes).size(); i++){
            res->siguientes[i] = copiarNodo(n->siguientes[i]);
        }
        return res;
    }
}

template <typename T>
string_map<T>::~string_map(){
    desctructor(this->_raiz);
}

template <class T>
void string_map<T>::desctructor(Nodo* x){
    if(x != nullptr){
        for(int i=0; i< x->siguientes.size(); i++){
            desctructor(x->siguientes[i]);
        }
        if(x->definicion != nullptr)
            delete(x->definicion);
        delete x;
    }
}

template<typename T>
void string_map<T>::insert(const pair<string, T> &par) {
    if(_raiz == nullptr)
        _raiz = new Nodo();
    Nodo* x = _raiz;
    if(count(par.first)==1){
        for (char c: par.first){
            x = (x->siguientes)[c];
        }
    }
    else{
        for (char c: par.first){
            if((x->siguientes)[c] == nullptr)
                (x->siguientes)[c] = new Nodo();
            x = (x->siguientes)[c];
        }
        _size++;
    }
    if(x->definicion != nullptr){
        delete x->definicion;
    }
    x->definicion = new T(par.second);
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR OPCIONAL
}

template <typename T>
int string_map<T>::count(const string& clave) const{
    Nodo* x = _raiz;
    if(_raiz != NULL){
        for (char c: clave){
            if((x->siguientes)[c] != nullptr){
                x = (x->siguientes)[c];
            }
            else
                return 0;
        }
        if (x->definicion != nullptr)
            return 1;
    }
    return 0;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* x = _raiz;
    for (char c: clave){
        x = (x->siguientes)[c];
    }
    return *(x->definicion);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* x = _raiz;
    for (char c: clave){
        x = x->siguientes[c];
    }
    return *(x->definicion);
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* first = _raiz;
    Nodo* last = _raiz;
    int ultindex = -1;
    int k= 0;
    for (char c: clave){
        for(int i = 0; i < first->siguientes.size(); i++){
            if(first->siguientes[i] != nullptr){
                last = first;
                ultindex = c;
            }
        }
        if (first->definicion != nullptr && k < clave.size()){
            last = first;
            ultindex = c;
        }
        first = first->siguientes[c];   //avanzo el nodo
        k++;
    }
    for(int i = 0; i < first->siguientes.size(); i++){
        if(first->siguientes[i] != nullptr){
            last = first;
            ultindex = -2;
        }
    }
    delete first->definicion;
    first->definicion= nullptr;
    if (last != first && ultindex!= -1){
        desctructor(last->siguientes[ultindex]);
        last->siguientes[ultindex] = nullptr;
    }
    else if (ultindex == -1){
        for (int i = 0; i < _raiz->siguientes.size(); i++){
            desctructor(_raiz->siguientes[i]);
            _raiz->siguientes[i] = nullptr;
        }
    }
    _size--;
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return _size==0;
}
