#ifndef SISTEMADEMENSAJES_H
#define SISTEMADEMENSAJES_H

#include "ConexionJugador.h"
#include <string>
#include <vector>

#if EJ == 4 || EJ == 5
#include "Proxy.h"
#elif EJ == 6
#include "Proxy2.h"
#endif

using namespace std;

class SistemaDeMensajes {
  public:

#if EJ == 7
    class Proxy;

    class Proxy {
    public:
        Proxy(ConexionJugador** conn);
        void enviarMensaje(string msg);

    private:
        ConexionJugador** _conn;

        // No puedo copiarlo
        Proxy(const Proxy&);
    };
#endif

    SistemaDeMensajes();
    // Pre: 0 <= id < 4
    void registrarJugador(int id, string ip);

    // Pre: 0 <= id < 4
    bool registrado(int id) const;

    // Pre: registrado(id)
    void enviarMensaje(int id, string mensaje);

    // Pre: registrado(id)
    string ipJugador(int id) const;

    // Pre: registrado(id)
    void desregistrarJugador(int id);

    #if EJ >3
    // Pre: registrado(id)
    Proxy* obtenerProxy(int id);
    #endif
    ~SistemaDeMensajes();

  private:
    ConexionJugador* _conns[4];

    #if EJ >3
    vector<Proxy*> _proxys;
    #endif


};

#endif
