#include "gtest/gtest.h"
#include <vector>
#include "../src/ejemplo.h"

using namespace std;
/*TEST(nombreFuncion, nombreTest){

}*/
unsigned int cantidad_apariciones(int i, vector<int> v) {
    unsigned int resultado = 0;
    for (int n : v) {
        if (i==n) {
            resultado ++;
        }
    }
    return resultado;
}
bool misma_cantidad_de_apariciones(vector<int> vector1, vector<int> vector2) {
    for (int n : vector1) {
        if (cantidad_apariciones(n, vector1) != cantidad_apariciones(n, vector2)) {
            return false;
        }
    }
    for (int n : vector2) {
        if (cantidad_apariciones(n, vector1) != cantidad_apariciones(n, vector2)) {
            return false;
        }
    }
    return true;
}
string v2s(vector<char> v) {
    stringstream ss;
    for (char c : v) {
        ss << c;
    }
    return ss.str();
}
set<int> v2s(vector<int> v) {
    set<int> ret;
    for (int x : v) {
        ret.insert(x);
    }
    return ret;
}

void test_ej1(vector<int> (*qr)(vector<int>)) {
    EXPECT_TRUE(misma_cantidad_de_apariciones((*qr)(vector<int>()),vector<int>()));
    EXPECT_TRUE(misma_cantidad_de_apariciones((*qr)(vector<int>({1, 1, 1, 1, 1, 1, 1, 1, 1})),vector<int>({1})));
    EXPECT_TRUE(misma_cantidad_de_apariciones((*qr)(vector<int>({1, 1, 2, 2, 3, 3})),vector<int>({1,2,3})));
    EXPECT_TRUE(misma_cantidad_de_apariciones((*qr)(vector<int>({1, 1, 2, 3, 3})),vector<int>({1,2,3})));
}


void test_ej3(bool (*me)(vector<int>, vector<int>)) {
    EXPECT_TRUE((*me)(vector<int>{}, vector<int>{}));
    EXPECT_TRUE((*me)(vector<int>{1, 1, 1}, vector<int>{1}));
    EXPECT_TRUE((*me)(vector<int>{1, 2, 3}, vector<int>{1, 2, 3}));
    EXPECT_TRUE((*me)(vector<int>{3, 2, 1}, vector<int>{1, 2, 3}));
    EXPECT_TRUE(!(*me)(vector<int>{4, 3, 2, 1}, vector<int>{1, 2, 3}));
    EXPECT_TRUE((*me)(vector<int>{3, 3, 2, 1}, vector<int>{1, 2, 3}));
    EXPECT_TRUE(!(*me)(vector<int>{3, 3, 2, 1}, vector<int>{1, 3}));
}

TEST(Ej, 01) { test_ej1(quitar_repetidos); }

TEST(Ej, 03) { test_ej3(mismos_elementos); }

TEST(Ej, 05) {
    EXPECT_TRUE((contar_apariciones(vector<int>()) == map<int, int>()));
    EXPECT_TRUE((contar_apariciones(vector<int>({1, 2, 3})) == map<int, int>({{1, 1}, {2, 1}, {3, 1}})));
    EXPECT_TRUE((contar_apariciones(vector<int>({1, 2, 3, 1})) == map<int, int>({{1, 2}, {2, 1}, {3, 1}})));
    EXPECT_TRUE((contar_apariciones(vector<int>({1, 1})) == map<int, int>({{1, 2}})));
}

TEST(Ej, 06) {
    EXPECT_EQ(v2s(filtrar_repetidos(vector<int>{})), set<int>());
    EXPECT_EQ(v2s(filtrar_repetidos(vector<int>({1, 1}))), set<int>());
    EXPECT_EQ(v2s(filtrar_repetidos(vector<int>({1, 1, 2}))), set<int>({2}));
    EXPECT_EQ(v2s(filtrar_repetidos(vector<int>({1, 2}))), set<int>({2, 1}));
}

TEST(Ej, 07) {
    EXPECT_EQ(interseccion(set<int>(), set<int>()), set<int>());
    EXPECT_EQ(interseccion(set<int>({1, 2, 3}), set<int>()), set<int>());
    EXPECT_EQ(interseccion(set<int>({1, 2, 3}), set<int>({4})), set<int>());
    EXPECT_EQ(interseccion(set<int>({1, 2, 3}), set<int>({2, 4})), set<int>({2}));
    EXPECT_EQ(interseccion(set<int>({1, 2, 3}), set<int>({2, 1, 4})), set<int>({1, 2}));
}
