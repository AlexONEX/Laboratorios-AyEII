#include <iostream>
#include "gtest/gtest.h"
using namespace std;

int main(int argc, char **argv) {
    cout << "LaboTDD - Ejecutando Tests" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}