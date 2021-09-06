#ifndef PROXY_H
#define PROXY_H

#include "ConexionJugador.h"
#include <string>

using namespace std;

class Proxy {
public:
    Proxy(ConexionJugador* conn);
    void enviarMensaje(string msg);

private:
    ConexionJugador* _conn;

    // No puedo copiarlo por afuera de la clase, me es útil para hacer una copia sin modificar el original
    // dentro de la clase
    Proxy(const Proxy&);
};

#endif
