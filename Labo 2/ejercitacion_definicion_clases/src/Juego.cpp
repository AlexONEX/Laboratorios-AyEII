#include <utility>
#include <list>
#include <string>

using namespace std;

// Ejercicio 15

// Juego

using Pos = pair<int, int>;

const char ARRIBA = '^';
const char ABAJO = 'v';
const char DERECHA = '<';
const char IZQUIERDA = '>';

//Ejercicio 15
class Pocion{
    
};

class Juego {
public:
    Juego(uint casilleros, Pos pos_inicial);
    Pos posicion_jugador();
    uint turno_actual();
    void mover_jugador(char dir);
    void ingerir_pocion(uint movimientos, uint turnos);

private:
    uint casilleros_;
    Pos pos_;
    uint turno_;
    list<Pocion> pociones_;
    uint movimientos_extra_;

    void calcular_movimientos_extra();
};

Juego::Juego(uint casilleros, Pos pos_inicial) :
        casilleros_(casilleros),
        pos_(pos_inicial),
        turno_(),
        pociones_(),
        movimientos_extra_() {
}

Pos Juego::posicion_jugador() {
    return pos_;
}

uint Juego::turno_actual() {
    return turno_;
}

void Juego::mover_jugador(char dir) {
    int dy = 0;
    int dx = 0;

    switch (dir) {
        case ARRIBA:
            dy = -1;
            break;
        case ABAJO:
            dy = 1;
            break;
        case IZQUIERDA:
            dx = -1;
            break;
        case DERECHA:
            dx = 1;
            break;
    }

    int ny = pos_.first + dy;
    int nx = pos_.second + dx;

    if (ny < 0 || ny >= (int) casilleros_)
        return;

    if (nx < 0 || nx >= (int) casilleros_)
        return;

    pos_ = Pos(ny, nx);

    if (movimientos_extra_) {
        movimientos_extra_--;
    }
    if (!movimientos_extra_) {
        turno_++;
        calcular_movimientos_extra();
    }
}

void Juego::ingerir_pocion(uint movimientos, uint turnos) {
    uint vence = turno_ + turnos;
    pociones_.push_back(Pocion(movimientos, vence));
    calcular_movimientos_extra();
}

void Juego::calcular_movimientos_extra() {
    uint extra = 0;

    for (auto it = pociones_.begin(); it != pociones_.end(); ) {
        if (it->second <= turno_) {
            it = pociones_.erase(it);
        } else {
            extra += it->first;
            it++;
        }
    }

    movimientos_extra_ = extra;
}
