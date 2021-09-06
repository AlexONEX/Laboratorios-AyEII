#include <utility>
#include <list>
#include <iostream>
#include <string>

using namespace std;

using uint = unsigned int;



// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(int mes, int dia);
    int mes();
    int dia();
    void incrementar_dia();
    bool operator<(Fecha h);
#if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif

  private:
    int dia_;
    int mes_;
};

Fecha::Fecha(int d, int m): mes_(d), dia_(m){};

int Fecha::mes() {
    return mes_;
}
int Fecha::dia() {
    return dia_;
}
ostream& operator<<(ostream& os, Fecha r) {
    os << "" << r.dia() << "/" << r.mes();
    return os;
}
#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    igual_dia = igual_dia && mes() == o.mes();
    return igual_dia;
}

void Fecha::incrementar_dia(){
    if(dias_en_mes(mes_) == dia_ && mes < 12){
        mes_++;
        dia_=1;
    }
    else if (dias_en_mes(mes_) == dia_ && mes == 12){
        dia_++;
        mes_=1;
    }
    else{
        dia_++;
    }
}

bool Fecha::operator<(Fecha h) {
    return (mes()<h.mes() || mes()<=h.mes() && dia()<h.dia());
}
#endif

// Ejercicio 11, 12

class Horario{
    public:
        Horario(uint hora, uint min);
        uint hora();
        uint min();
        bool operator<(Horario h);
        bool operator==(Horario o);
private:
        uint hora_;
        uint min_;
};

Horario::Horario(uint hora, uint min): hora_(hora), min_(min){};

uint Horario::hora() {
    return hora_;
}

uint Horario::min() {
    return min_;
}

bool Horario::operator==(Horario o) {
    bool horario = this->hora() == o.hora();
    horario = horario && min() == o.min();
    return horario;
}

bool Horario::operator<(Horario h) {
    if(hora()<h.hora() || hora()<=h.hora() && min()<h.min()){
        return true;
    }
    return false;
}

    ostream& operator<<(ostream& os, Horario r) {
    os << "" << r.hora() << ":" << r.min();
    return os;
}

// Ejercicio 13
class Recordatorio{
    public:
        Recordatorio(Fecha r, Horario p, string h);
        Fecha fecha();
        Horario horario();
        string hecho();
        bool operator==(Recordatorio o);
        bool operator<(Recordatorio o);
private:
        Fecha fecha_;
        Horario horario_;
        string hecho_;
};

Recordatorio::Recordatorio(Fecha r, Horario p, string h):fecha_(r), horario_(p), hecho_(h){}

Fecha Recordatorio::fecha() {
    return fecha_;
}

Horario Recordatorio::horario() {
    return horario_;
}

string Recordatorio::hecho() {
    return hecho_;
}

bool Recordatorio::operator==(Recordatorio o) {
    return (o.horario() == horario_ && o.fecha() == fecha_ && o.hecho() == hecho_);
}

bool Recordatorio::operator<(Recordatorio o) {
    return (fecha()<o.fecha() || (fecha()==o.fecha() && horario()<o.horario()));
}

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.hecho() << " @ " << r.fecha() << " " << r.horario();
    return os;
}

// Ejercicio 14
class Agenda{
    public:
        Agenda(Fecha fecha_inicial);
        void agregar_recordatorio(Recordatorio rec);
        void incrementar_dia();
        list <Recordatorio> recordatorios_de_hoy();
        Fecha hoy();
    private:
        Fecha fecha_actual_;
        list <Recordatorio> eventos_;
};

Agenda::Agenda(Fecha f): fecha_actual_(f), eventos_(){};

void Agenda::incrementar_dia() {
    fecha_actual_.incrementar_dia();
}

void Agenda::agregar_recordatorio(Recordatorio rec) {
    eventos_.push_back(rec);
}
Fecha Agenda::hoy() {
    return fecha_actual_;
}

list<Recordatorio> Agenda::recordatorios_de_hoy() {
    list <Recordatorio> events;
    for(auto element: eventos_){
        if(element.fecha()==fecha_actual_){
            events.push_back(element);
        }
    }
    events.sort();
    return events;
}
ostream& operator<<(ostream& os, Agenda r) {
    os << r.hoy() << endl << "=====" << endl;
    for(auto element: r.recordatorios_de_hoy()){
        os << element.hecho() << " @ " << element.fecha() << " " << element.horario() << endl;
    }
    return os;
}

