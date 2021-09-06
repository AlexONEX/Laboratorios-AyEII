template <class T1>
T1 cuadrado(T1 x){
    return x*x;
}

template <class Contenedor, class Elem>
bool contiene(Contenedor s, Elem c){
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}
template <class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){
    if(b.size()>a.size()){
        for(int i=0; i<a.size(); i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class Contenedor, class Elem>
Elem maximo(Contenedor a){
    Elem k = a[0];
    for(int i=0; i<a.size(); i++){
        if(k<a[i]){
            k = a[i];
        }
    }
    return k;
}
