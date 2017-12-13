cmake_minimum_required(VERSION 3.9)
project(ExtendedChain)

set(CMAKE_CXX_STANDARD 11)

add_executable(ExtendedChain myExceptions.h chainNode.h linearList.h chainWithIterator.h extendedLinearList.h extendedChain.h main.cpp)