#include "SistemaDeMensajes.h"

// Completar...
SistemaDeMensajes::SistemaDeMensajes() {
	for (int i = 0; i < 4; i++) {
		_conns[i] = nullptr;
	}
};

void SistemaDeMensajes::registrarJugador(int id, string ip) {
	if (registrado(id)) {
		SistemaDeMensajes::desregistrarJugador(id);
	}
	_conns[id] = new ConexionJugador(ip);
}

void SistemaDeMensajes::desregistrarJugador(int id) {	
	delete _conns[id];
	_conns[id] = nullptr;
}
bool SistemaDeMensajes::registrado(int id) const{
	if (_conns[id] == nullptr) {
		return false;
	}
	return true;
}

// Pre: registrado(id)
void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
	_conns[id]->enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const{
	return _conns[id]->ip();
}

SistemaDeMensajes::~SistemaDeMensajes() {
	for (int i = 0; i < 4; i++) {
		delete _conns[i];
	}
	for (int j = 0; j < _proxyPtrs.size(); j++) {
		delete _proxyPtrs[j];
	}
	
};

SistemaDeMensajes::Proxy::Proxy(ConexionJugador** conn) : _conn(conn) {};

void SistemaDeMensajes::Proxy::enviarMensaje(string msg) {
	(*_conn)->enviarMensaje(msg);
}

SistemaDeMensajes::Proxy* SistemaDeMensajes::obtenerProxy(int id) {
	Proxy* currentPtr = new Proxy(&_conns[id]);
	_proxyPtrs.push_back(currentPtr);
	return currentPtr;
}

