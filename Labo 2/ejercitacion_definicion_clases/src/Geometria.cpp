#include <iostream>
#include <math.h>
using namespace std;
float PI = 3.14;
using uint = unsigned int;

// Ejercicio 1
class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        uint area();

    private:
        int alto_;
        int ancho_;

};

Rectangulo::Rectangulo(uint alto, uint ancho) : alto_(alto), ancho_(ancho) {};

uint Rectangulo::alto() {
    return alto_;
}

uint Rectangulo::ancho() {
    return ancho_;
}

uint Rectangulo::area() {
    return ancho_*alto_;
}

// Ejercicio 2
class Elipse {
    public:
        Elipse(uint a, uint b);
        uint r_a();
        uint r_b();
        float area();
    private:
        uint a_;
        uint b_;
};

Elipse::Elipse(uint a, uint b) : a_(a), b_(b) {};

float Elipse::area(){
    return a_*b_*PI;
}

uint Elipse::r_a() {
    return a_;
}

uint Elipse::r_b() {
    return b_;
}

// Ejercicio 3
class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo r_;
};

Cuadrado::Cuadrado(uint lado): r_(lado, lado) {}

uint Cuadrado::lado() {
    return r_.alto();
}

float Cuadrado::area() {
    return r_.alto()*r_.alto();
}

// Ejercicio 4
class Circulo{
    public:
        Circulo(uint radio);
        uint radio();
        uint area();
    private:
        Elipse r_;
};
Circulo::Circulo(uint radio): r_(radio, radio){};

uint Circulo::radio() {
    return r_.r_a();
}
uint Circulo::area() {
    return r_.area();
}

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

ostream& operator<<(ostream& os, Elipse r) {
    os << "Elipse(" << r.r_a() << ", " << r.r_b() << ")";
    return os;
}

ostream& operator<<(ostream& os, Circulo r) {
    os << "Circ(" << r.radio() << ")";
    return os;
}

ostream& operator<<(ostream& os, Cuadrado r) {
    os << "Cuad(" << r.lado() << ")";
    return os;
}
