cmake_minimum_required(VERSION 3.9)
project(arryList)

set(CMAKE_CXX_STANDARD 11)

add_executable(arryList linearList.h myExceptions.h changeLength1D.h arrayList.h arrayList.cpp)