# CMakeList.txt : CMake project for MyLibrary, include source and define
# project specific logic here.

cmake_minimum_required (VERSION 3.14)

# Project name
project (CPP_Base_Example VERSION 0.0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Global vars
set (LIB_NAME_TEST MyLibraryTest)
set (LIB_NAME MyLibrary)
set (EXE_NAME MyApp)



# Definir libreria Google Test
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/release-1.8.1.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)



# Definir libreria
add_library (${LIB_NAME} STATIC
        MyLibrary/src/example.cpp
        MyLibrary/src/hello.cpp)



# Definir aplicacion de pruebas
add_executable (${EXE_NAME} MyLibraryTestApp/main.cpp)

target_link_libraries (${EXE_NAME}
        PRIVATE ${LIB_NAME})

target_include_directories(${EXE_NAME}
        PRIVATE MyLibrary/include)



# Definir libreria de pruebas
add_executable(${LIB_NAME_TEST} MyLibraryTest/example_test.cpp)

target_link_libraries (${LIB_NAME_TEST}
        PRIVATE ${LIB_NAME}
        gtest_main)

target_include_directories(${LIB_NAME_TEST}
        PRIVATE MyLibrary/include)

add_test(MyLibrary.UnitTest COMMAND ${LIB_NAME_TEST})














