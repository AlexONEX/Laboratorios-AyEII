#include "ejemplo.h"
#include <vector>
#include <map>
using namespace std;

bool pertenece(int a, vector<int> b){
    for(int i : b){
        if(i == a){
            return true;
        }
    }
    return false;
}

//Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int> k;
    if(s.empty() || s.size()== 1){
        return s;
    }
    else{
        for(int i=0; i<s.size()-1; i++){
            if(!pertenece(s[i], k)){
                k.push_back(s[i]);
            }
        }
    }
    return k;
}
// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {    //Set?
    return vector<int>();
}


// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    for(int & i : a){
        if(!pertenece(i, b)){
            return false;
        }
    }
    for(int i : b){
        if(!pertenece(i, a)){
            return false;
        }
    }
    return true;
}
// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    return true;
}
int cant_apariciones(int a, vector<int> s){
    int contador=0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == a){
            contador++;
        }
    }
    return contador;
}
// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> myMap;
    vector<int> contados;
    for(int i=0; i<s.size(); i++){
        if(!pertenece(s[i], contados)){
            myMap[s[i]] = cant_apariciones(s[i], s);
            contados.push_back(s[i]);
        }
    }
    return myMap;
}
// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> salida;
    for(int i=0; i<s.size(); i++){
        if(cant_apariciones(s[i], s) == 1){
            salida.push_back(s[i]);
        }
    }
    return salida;
}
// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> c;
    for(int i: a){
        if(b.find(i) != b.end()){
            c.insert(i);
        }
    }
    for(int i: b){
        if(a.find(i) != a.end()){
            c.insert(i);
        }
    }
    return c;
}
// Ejercicio 8