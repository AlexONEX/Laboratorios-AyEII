cmake_minimum_required(VERSION 3.6)
project(LaboTDD)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wno-deprecated-declarations")

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES
        main.cpp
        # sources
        src/ejemplo.cpp
        # tests
        test/testEjemplo.cpp
)

add_executable(LaboTDD ${SOURCE_FILES})

target_link_libraries(LaboTDD gtest gtest_main)
