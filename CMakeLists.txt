cmake_minimum_required(VERSION 3.0.0)
project(Alpha)
add_executable(${PROJECT_NAME} main.cpp fragments/fileReader/fileReader.cpp fragments/errorSys/errorSys.cpp fragments/tokenSys/tokenSys.hpp fragments/tokenSplitter/tokenSplitter.cpp fragments/tokenSplitter/tokenSplitter.hpp fragments/tokenSys/tokenSys.cpp)