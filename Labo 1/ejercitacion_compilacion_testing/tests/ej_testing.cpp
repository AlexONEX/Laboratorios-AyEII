#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    int resultado = 22;
    int calculo = 15+7;
    EXPECT_EQ(resultado, calculo);
}

// Ejercicio 5
TEST(Aritmetica, potencia) {
    int base = 10;
    int exponente = 2;
    EXPECT_EQ(100, pow(10,2));
}

// Ejercicio 6
TEST(Aritmetica, potencia_general){
    for(int i = -5; i<6; i++){
        EXPECT_EQ(i*i, pow(i, 2));
    }
}
//Ejercicio 7
TEST(Diccionario, obtener){
    map<int, int> myDic;
    myDic.insert(make_pair(2,6));
    EXPECT_EQ(myDic.at(2), 6);
}
//Ejercicio 8
TEST(Diccionario, definir){
    map<int, int> c;
    c.insert(make_pair(2, 7));
    EXPECT_EQ(c.count(3), 0);
    c.insert(make_pair(3,2));
    EXPECT_EQ(c.count(3), 1);
}
TEST(Truco, inicio){
    Truco partida;
    EXPECT_EQ(partida.puntaje_j1(), 0);
    EXPECT_EQ(partida.puntaje_j2(), 0);
}
TEST(Truco, buenas){
    Truco partida;
    EXPECT_FALSE(partida.buenas(1));
    for (int i = 0; i < 15; ++i) {
        partida.sumar_punto(1);
    }
    EXPECT_FALSE(partida.buenas(1));
    partida.sumar_punto(1);
    EXPECT_TRUE(partida.buenas(1));
    partida.sumar_punto(1);
    partida.sumar_punto(1);
    EXPECT_TRUE(partida.buenas(1));
}