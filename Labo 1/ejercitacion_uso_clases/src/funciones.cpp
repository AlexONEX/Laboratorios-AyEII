#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include "algobot.h"

using namespace std;

bool pertenece(int a, vector<int> b){
    for(int i : b){
        if(i == a){
            return true;
        }
    }
    return false;
}
bool pertenece2(string a, vector<string> b){
    for(auto i : b){
        if(i == a){
            return true;
        }
    }
    return false;
}
bool interseccion2(vector<string> a, vector<string> b){
    for(const string& i:a){
        if(find(b.begin(), b.end(), i) != b.end())
            return true;
    }
    for(const string& i:b){
        if(find(a.begin(), a.end(), i) != a.end())
            return true;
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
vector<int> quitar_repetidos_v2(vector<int> s) {
    vector<int> clean;
    set<int> mySet( s.begin(), s.end() );
    clean.assign( mySet.begin(), mySet.end() );
    return clean;
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
    set<int> cleanA( a.begin(), a.end());
    set<int> cleanB( b.begin(), b.end());
    return cleanA==cleanB;
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
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> c;
    for(int & i : s){
        c[i%10].insert(i);
    }
    return c;
}
bool notChanged(vector<pair<char, char>> tr, char m){
    for(auto j: tr){
        if(j.second == m){
            return false;
        }
    }
    return true;
}
// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str){   //Solamente traduzco una vez por elemento?
    vector<char> c = str;
    if(tr.empty()){
        return str;
    }
    else{
        for(auto j : tr){
            for(char & i : c){
                if(i == j.first && notChanged(tr, j.first)){
                    i = j.second;
                }
            }
        }
    }
    return c;
}
bool checkMany(const string& s){
    for(auto const& letra: s){
        if(letra == ';'){
            return true;
        }
    }
    return false;
}

vector<string> adjunto_to_libreta(const string& s){
    vector<string> g;
    stringstream test(s);
    if(checkMany(s)){
        string segment;
        vector<string> seglist;
        while(getline(test, segment, ';')){
            seglist.push_back(segment);
        }
        return seglist;
    }
    vector<string> k = {s};
    return k;
}
// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s){// Por cada mail hago un set grupo y luego comparo los sets
    vector<vector<string>> grupos;
    grupos.reserve(s.size());
    for(const auto& m: s){   //Toma un mail retorna un conjunto de libretas string
        grupos.push_back(adjunto_to_libreta(m.asunto()));
    }
    for(int i=0; i<grupos.size(); i++){
        for(int j=0; j<grupos.size(); j++){
            if(grupos[i] != grupos[j] && interseccion2(grupos[i], grupos[j])){
                return true;
            }
        }
    }
    return false;
}


// Ejercicio 11

Mail ultimoMailGrupo(const vector<Mail>& s, const set<LU>& miembros){
    Mail ultimoMail;
    for(auto const& element: s){
        if(element.libretas() == miembros && element.adjunto()){
            ultimoMail = element;
        }
    }
    return ultimoMail;
}
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {// Recibo mail, armo los grupos y le asocio a cada grupo su ultimo mail
    map<set<LU>, Mail> myMap;   //c.insert(make_pair(grupo, ultimoMail))
    for(auto const& mail: s){
        Mail c = ultimoMailGrupo(s, mail.libretas());
        myMap.insert(make_pair(mail.libretas(), c));
    }
    return myMap;
}
