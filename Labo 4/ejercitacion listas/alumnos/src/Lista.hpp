#include "Lista.h"

Lista::Lista():_longitud(0),_head(nullptr), _end(nullptr){};

Lista::Lista(const Lista& l) : Lista() {
    *this = l;
}

Lista::~Lista(){
    Nodo* temp = _head;
    while(_head!=nullptr){
        temp = temp->next;
        delete _head;
        _head = temp;
    }
    _end = nullptr;
    _longitud=0;
}

Lista& Lista::operator=(const Lista& aCopiar) {
    this->~Lista();
    Nodo* temp = aCopiar._head;
    while(temp != nullptr){
        agregarAtras(temp->dato);
        temp = temp->next;
    }
    return *this;
}
void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = elem;
    nuevo->before = nullptr;
    nuevo->next = _head;
    if(_head != nullptr){
        _head->before = nuevo;
    }
    else{
        _end = nuevo;
    }
    _head = nuevo;
    _longitud++;
}

void Lista::agregarAtras(const int& elem) {  //final
    Nodo* nuevo = new Nodo;
    nuevo->dato = elem;
    nuevo->next = nullptr;
    nuevo->before = _end;
    if(_end != nullptr){
        _end->next= nuevo;
    }
    else{
        _head = nuevo;
    }
    _end = nuevo;
    _longitud++;
}
//i < _longitud
void Lista::eliminar(Nat i) {
    Nodo* temp = _head;
    int j=0;
    while(j<i) {
        temp = temp->next;
        j++;
    }
    if(longitud()==1){
        delete(_head);
        _head = nullptr;
        _end  = nullptr;
        _longitud = 0;
    }
    else if(_head != temp && _end != temp){
        temp->before->next = temp->next;
        temp->next->before = temp->before;
        delete(temp);
        _longitud--;
    }
    else if(_head == temp){
        temp->next->before = nullptr;
        _head = temp->next;
        delete(temp);
        _longitud--;
    }
    else{
        temp->before->next = nullptr;
        _end = temp->before;
        delete(temp);
        _longitud--;
    }
}

int Lista::longitud() const {
    return _longitud;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* temp = _head;
    int j=0;
    while(j<i) {
        temp = temp->next;
        j++;
    }
    const int& dato2 = temp->dato;
    return dato2;
}

int& Lista::iesimo(Nat i) {
    Nodo* temp = _head;
    int j=0;
    while(j<i) {
        temp = temp->next;
        j++;
    }
    int& dato2 = temp->dato;
    return dato2;
}

void Lista::mostrar(ostream& o) {
    // Completar
}
