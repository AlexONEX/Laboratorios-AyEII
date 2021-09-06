#include "SistemaDeMensajes.h"

SistemaDeMensajes::SistemaDeMensajes(){
    for (int i = 0; i < 4; ++i) {
        this->_conns[i] = nullptr;
    }
};

void SistemaDeMensajes::registrarJugador(int id, string ip){
    if (this->registrado(id)) {
        delete  this->_conns[id];
    }
    this->_conns[id] = new ConexionJugador(ip);
};
void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    (this->_conns[id])->enviarMensaje(mensaje);
};

bool SistemaDeMensajes::registrado(int id) const{
    return this->_conns[id] != nullptr;
};

string SistemaDeMensajes::ipJugador(int id) const{
    return (this->_conns[id])->ip();
};

void SistemaDeMensajes::desregistrarJugador(int id){
    delete this->_conns[id];
    this->_conns[id] = nullptr;

};


#if EJ == 4 || EJ == 5
Proxy* SistemaDeMensajes::obtenerProxy(int id){
    Proxy* pr_j = new Proxy(this->_conns[id]);
    this->_proxys.push_back(pr_j);
    return  pr_j;
};
#elif EJ == 6
Proxy* SistemaDeMensajes::obtenerProxy(int id){
    Proxy* pr_j = new Proxy( &(this->_conns[id]));
    this->_proxys.push_back(pr_j);
    return  pr_j;
};
#endif


SistemaDeMensajes::~SistemaDeMensajes(){

    for (int id=0;id < 4; id++) {
        delete _conns[id];
    }

    #if EJ >3
    for (Proxy* &pr : this->_proxys) {
        delete pr;
    }
#endif

};

#if EJ == 7

SistemaDeMensajes::Proxy::Proxy(ConexionJugador** conn) : _conn(conn) {};

void SistemaDeMensajes::Proxy::enviarMensaje(string msg) {
	(*_conn)->enviarMensaje(msg);
}

SistemaDeMensajes::Proxy* SistemaDeMensajes::obtenerProxy(int id){
    Proxy* pr_j = new Proxy( &(this->_conns[id]));
    this->_proxys.push_back(pr_j);
    return  pr_j;
};
#endif